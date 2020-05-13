#!/usr/bin/env python

"""
C++ Code generation.
"""

import os
import functools
import subprocess
import shlex
import collections

from jinja2 import Template


# Name of the project directory.
PROJECT_DIR = "gm"

# Name of the codeGenTemplates directory.
TEMPLATE_DIR = "template"

# Name of the subdirectory where all types reside.
TYPE_DIR = "type"

# Prefix for the class names of types.
TYPES_CLASS_PREFIX = ""

# POD types we are interested in generating code for.  Double is omitted for the time being.
FLOAT = "float"
INT = "int"

# TYPES is a dict of type name (str) -> type object (CompositeType).
# It is populated in GenerateCompositeTypes.
TYPES = {}

#
# Utilities
#

def RunCommand(command):
    """
    Run a command in the shell by forking a subprocess.
    """
    print("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


def WriteFile(filePath, content):
    """
    Write a file to disk.

    Args:
        filePath (str): path to write to.
        content (str): content to write.
    """
    print("Generated {!r}".format(filePath))
    with open(filePath, 'w') as f:
        f.write(content)


def FormatCode(fileNames):
    """
    Run clang-format over input files, formatting in-place.

    Args:
        fileNames (list): input files to automatically format.
    """
    command = "clang-format -i " + " ".join(fileNames)
    RunCommand(command)


def GetTemplateFile(templateName):
    """
    Args:
        templateName (str): name of the template file.

    Returns:
        str: full path to the codegen template.
    """
    return os.path.abspath(os.path.join(TEMPLATE_DIR, templateName))


def GenerateCode(context, templatePath):
    """
    Generate a single source file with a template and code-gen context.

    Args:
        context (obj): context object with attributes which are consumed in the template rendering.
        templatePath (str): path to the template file to perform substitution.

    Returns:
        str: file name of generated source file.
    """
    with open(templatePath, 'r') as f:
        templateStr = f.read()
        template = Template(templateStr)
        code = template.render(context=context)
        return code


#
# Types
#

class ValueType:
    """
    Abstract base class for all data types.
    """

    @property
    def className(self):
        raise NotImplementedError()

    @property
    def headerFileName(self):
        raise NotImplementedError()

    @property
    def isScalar(self):
        return False

    @property
    def isVector(self):
        return False

    @property
    def isArray(self):
        return False

    @property
    def isComposite(self):
        return False


class PODType(ValueType):
    """
    POD (Plain old data) type, used in code-gen contexts.
    """

    def __init__(self, typeName):
        assert(isinstance(typeName, str))
        self._typeName = typeName

    @property
    def className(self):
        """
        Returns:
            str: the ctype of this type.
        """
        return self._typeName

    @property
    def isScalar(self):
        return True


POD_TYPES = [
    PODType(FLOAT),
    PODType(INT)
]



class VectorType(ValueType):
    """
    Code generation for an C++ vector type.
    """

    def __init__(self, dims, elementType):
        assert(isinstance(dims, tuple))
        assert(isinstance(elementType, PODType))
        self.dims = dims
        self.elementType = elementType

    @property
    def elementSize(self):
        return functools.reduce(lambda x, y: x * y, self.dims)

    @property
    def className(self):
        if len(self.dims) == 2:
            prefix = TYPES_CLASS_PREFIX + "Mat"
        else:
            prefix = TYPES_CLASS_PREFIX + "Vec"

        return "{prefix}{dims}{elementType}".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            elementType=self.elementType.className[0]
        )

    @property
    def headerFileName(self):
        if len(self.dims) == 2:
            prefix = "mat"
        else:
            prefix = "vec"

        return "{prefix}{dims}{elementType}.h".format(
            prefix=prefix,
            dims=str(self.dims[0]),
            elementType=self.elementType.className[0]
        )

    @property
    def isVector(self):
        return True


class ArrayType(ValueType):
    """
    Code generation for an C++ array type.
    """

    def __init__(self, elementType):
        assert(isinstance(elementType, ValueType))
        self.elementType = elementType

    @property
    def className(self):
        if self.elementType.className.startswith(TYPES_CLASS_PREFIX):
            prefix = ""
        else:
            prefix = TYPES_CLASS_PREFIX

        return "{prefix}{elementTypeName}Array".format(
            prefix=prefix,
            elementTypeName=(self.elementType.className[0].upper() + self.elementType.className[1:])
        )

    @property
    def headerFileName(self):
        if self.elementType.isVector:
            return "{elementHeaderFileName}Array.h".format(
                elementHeaderFileName=os.path.splitext(self.elementType.headerFileName)[0]
            )
        else:
            return "{elementTypeName}Array.h".format(
                elementTypeName=self.elementType.className[0].lower() + self.elementType.className[1:]
            )

    @property
    def isArray(self):
        return True


"""
CompositeElement is a single element of an CompositeType, described by a name, type, and default value.

Args:
    name (str): is used to uniquely address this element from the parent Composite type.
    type (object): the data type.
    defaultValue (str): string, encoding C++ code that will be assigned to element member variable.
"""
CompositeElement = collections.namedtuple("CompositeElement", ["name", "type", "defaultValue"])


class CompositeType(ValueType):
    """
    Code generation for an C++ composite data type.
    A composite type is a structure composed of one or more elements.
    Each element can be of type pod, vector, array, or another composite.

    Args:
        name (str): name of the composite type.
        elements (list): list of CompositeElement(s).
        extraIncludes (list): list of extras includes to encode near the top of the source file.
    """

    def __init__(self, name, elements, extraIncludes=None):
        for element in elements:
            assert(isinstance(element.type, ValueType))
        self._name = name
        self.elements = elements
        self.elementSize = len(self.elements)
        self.extraIncludes = extraIncludes or []

    @property
    def className(self):
        return self._name[:1].upper() + self._name[1:]

    @property
    def headerFileName(self):
        return "{name}.h".format(
            name=self._name[:1].lower() + self._name[1:]
        )

    @property
    def isComposite(self):
        return True


def GenerateCompositeType(compositeType):
    """
    Generate a single C++ composite type source file.

    Args:
        compositeType (CompositeType): composite data type to generate definition source code for.

    Returns:
        str: file path to the generated source file.
    """
    filePath = os.path.join(os.path.abspath(TYPE_DIR), compositeType.headerFileName)
    code = GenerateCode(
        compositeType,
        GetTemplateFile(os.path.join(TYPE_DIR, "compositeType.h"))
    )
    WriteFile(filePath, code)
    return filePath


def GenerateBoundsCompositeTypes():
    """
    Generate Bounds composite type source file.

    Returns:
        list: paths to generated source files.
    """
    filePaths = []

    for vectorType in [
        VectorType((2,), PODType(FLOAT)),
        VectorType((3,), PODType(FLOAT)),
        VectorType((2,), PODType(INT)),
        VectorType((3,), PODType(INT))
    ]:
        compositeTypeName = "bounds{dims}{elementType}".format(
            dims=str(vectorType.dims[0]),
            elementType=vectorType.elementType.className[0]
        )

        # Min default value.
        minDefaultValue = "{vectorClassName}(".format(
            vectorClassName=vectorType.className
        )
        for index in range(vectorType.dims[0]):
            minDefaultValue += "std::numeric_limits< {vectorElementType} >::max()".format(
                vectorElementType=vectorType.elementType.className
            )
            if index + 1 < vectorType.dims[0]:
                minDefaultValue += ","
        minDefaultValue += ")"

        # Max default value.
        maxDefaultValue = "{vectorClassName}(".format(
            vectorClassName=vectorType.className
        )
        for index in range(vectorType.dims[0]):
            maxDefaultValue += "std::numeric_limits< {vectorElementType} >::min()".format(
                vectorElementType=vectorType.elementType.className
            )
            if index + 1 < vectorType.dims[0]:
                maxDefaultValue += ","
        maxDefaultValue += ")"

        compositeType = CompositeType(
            compositeTypeName,
            [
                CompositeElement(name="min", type=vectorType, defaultValue=minDefaultValue),
                CompositeElement(name="max", type=vectorType, defaultValue=maxDefaultValue),
            ],
            extraIncludes=[
                "<limits>",
            ]
        )

        # Cache composite type into global TYPES, to be queried in function generation in a later stage.
        TYPES[compositeType.className] = compositeType

        filePaths.append(GenerateCompositeType(compositeType))

    return filePaths


def GenerateCompositeTypes():
    """
    Generate all composite type source files.

    Returns:
        list: paths to generated source files.
    """
    filePaths = []
    filePaths += GenerateBoundsCompositeTypes()
    return filePaths


def GenerateArrayTypes():
    """
    Generate all array type source files.

    Returns:
        list: paths to generated source files.
    """
    # Build ArrayType(s)
    arrayTypes = []
    for podType in POD_TYPES:
        arrayType = ArrayType(podType)
        arrayTypes.append(arrayType)

    for vectorType in VECTOR_TYPES:
        arrayType = ArrayType(vectorType)
        arrayTypes.append(arrayType)

    # Generate code for ArrayType(s)
    filePaths = []
    for arrayType in arrayTypes:
        filePath = os.path.join(os.path.abspath(TYPE_DIR), arrayType.headerFileName)
        code = GenerateCode(arrayType, GetTemplateFile(os.path.join(TYPE_DIR, 'arrayType.h')))
        WriteFile(filePath, code)
        filePaths.append(filePath)

    return filePaths


VECTOR_TYPES = [
    # Single-index vector types.
    VectorType((2,), PODType(INT)),
    VectorType((3,), PODType(INT)),
    VectorType((4,), PODType(INT)),
    VectorType((2,), PODType(FLOAT)),
    VectorType((3,), PODType(FLOAT)),
    VectorType((4,), PODType(FLOAT)),

    # Matrix types.
    VectorType((3,3), PODType(FLOAT)),
    VectorType((4,4), PODType(FLOAT)),
]


def GenerateVectorTypes():
    """
    Generate all vector type source files.

    Returns:
        list: paths to generated source files.
    """
    # Generate vector class headers.
    filePaths = []
    headerFileNames = []
    for vectorType in VECTOR_TYPES:
        code = GenerateCode(vectorType, GetTemplateFile(os.path.join(TYPE_DIR, "vectorType.h")))
        filePath = os.path.join(os.path.abspath(TYPE_DIR), vectorType.headerFileName)
        WriteFile(filePath, code)
        filePaths.append(filePath)
        headerFileNames.append(vectorType.headerFileName)

    return filePaths


def GenerateTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of pod, vectors, and matrices will also be generated.

    Returns:
        list: paths to of generated source files.
    """
    filePaths = GenerateVectorTypes()
    filePaths += GenerateArrayTypes()
    filePaths += GenerateCompositeTypes()
    return filePaths


if __name__ == "__main__":
    filePaths = GenerateTypes()
    FormatCode(filePaths)