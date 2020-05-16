#!/usr/bin/env python

"""
Main entry point / script for generating GraphicsMath C++ code.
"""

import os

from codeGen.utils import (
    GetTemplateFile,
    GenerateCode,
    WriteFile,
    FormatCode,
)

from codeGen.types import (
    PODType,
    VectorType,
    ArrayType,
    CompositeType,
    CompositeElement,
    INT,
    FLOAT,
)

from codeGen.functions import (
    Function,
    FunctionGroup,
)


"""
Name of the subdirectory where all type header files reside.
"""
TYPES_DIR = "types"

"""
Name of the subdirectory where all function header files reside.
"""
FUNCTIONS_DIR = "functions"

"""
Name of the subdirectory, under types/ and functions/ where their tests reside.
"""
TESTS_DIR = "tests"

"""
Global set of POD value types.
"""
POD_TYPES = set([PODType(FLOAT), PODType(INT)])

"""
VECTOR_TYPES Global set of vector value types to generate.
"""
VECTOR_TYPES = set(
    [
        # Single-index vector types.
        VectorType((2,), PODType(INT)),
        VectorType((3,), PODType(INT)),
        VectorType((4,), PODType(INT)),
        VectorType((2,), PODType(FLOAT)),
        VectorType((3,), PODType(FLOAT)),
        VectorType((4,), PODType(FLOAT)),
        # Matrix types.
        VectorType((3, 3), PODType(FLOAT)),
        VectorType((4, 4), PODType(FLOAT)),
    ]
)

"""
COMPOSITE_TYPES is a dict of type name (str) -> type object (CompositeType).
It is populated in GenerateCompositeTypes.
"""
COMPOSITE_TYPES = {}

#
# Code generation for types.
#


def GenerateCompositeType(compositeType):
    """
    Generate a single C++ composite type source file.

    Args:
        compositeType (CompositeType): composite data type to generate definition source code for.

    Returns:
        str: file path to the generated source file.
    """
    filePath = os.path.join(os.path.abspath(TYPES_DIR), compositeType.headerFileName)
    code = GenerateCode(
        compositeType, GetTemplateFile(os.path.join(TYPES_DIR, "compositeType.h"))
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
        VectorType((3,), PODType(INT)),
    ]:
        compositeTypeName = "bounds{dims}{elementType}".format(
            dims=str(vectorType.dims[0]),
            elementType=vectorType.elementType.className[0],
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
                CompositeElement(
                    name="min", type=vectorType, defaultValue=minDefaultValue
                ),
                CompositeElement(
                    name="max", type=vectorType, defaultValue=maxDefaultValue
                ),
            ],
            extraIncludes=["<limits>",],
        )

        # Store composite type into global COMPOSITE_TYPES, to be queried in function generation
        # in a later stage.
        COMPOSITE_TYPES[compositeType.className] = compositeType

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
        filePath = os.path.join(os.path.abspath(TYPES_DIR), arrayType.headerFileName)
        code = GenerateCode(
            arrayType, GetTemplateFile(os.path.join(TYPES_DIR, "arrayType.h"))
        )
        WriteFile(filePath, code)
        filePaths.append(filePath)

    return filePaths


def GenerateVectorTypes():
    """
    Generate all vector type source files.

    Returns:
        list: paths to generated source files.
    """
    # Generate vector class headers.
    filePaths = []
    for vectorType in VECTOR_TYPES:
        code = GenerateCode(
            vectorType, GetTemplateFile(os.path.join(TYPES_DIR, "vectorType.h"))
        )
        filePath = os.path.join(os.path.abspath(TYPES_DIR), vectorType.headerFileName)
        WriteFile(filePath, code)
        filePaths.append(filePath)

    # Tests
    for vectorType in VECTOR_TYPES:
        code = GenerateCode(
            vectorType, GetTemplateFile(os.path.join(TYPES_DIR, "testVectorType.cpp"))
        )
        filePath = os.path.join(
            os.path.abspath(TYPES_DIR),
            TESTS_DIR,
            "test{className}.cpp".format(className=vectorType.className),
        )
        WriteFile(filePath, code)
        filePaths.append(filePath)

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


#
# Code generation for functions.
#


def GenerateFunction(function):
    """
    Generate code for a function.

    Args:
        functionFileName (str): name of the template file.  This name will also be used to write the generated code.

    Returns:
        str: file path to the generated code.
    """
    filePath = os.path.join(os.path.abspath(FUNCTIONS_DIR), function.headerFileName)
    code = GenerateCode(
        function, GetTemplateFile(os.path.join(FUNCTIONS_DIR, function.headerFileName))
    )
    WriteFile(filePath, code)

    return filePath


def GenerateFunctions():
    """
    Generate code for templatized function.

    Returns:
        list: file paths to the generated files.
    """
    functionGroups = [
        FunctionGroup(
            ["dotProduct", "length", "lengthSquared",],
            types=[
                VectorType((2,), PODType(FLOAT)),
                VectorType((3,), PODType(FLOAT)),
                VectorType((4,), PODType(FLOAT)),
            ],
        ),
    ]

    filePaths = []
    for functionGroup in functionGroups:
        for function in functionGroup.functions:
            filePath = GenerateFunction(function)
            filePaths.append(filePath)

    return filePaths


if __name__ == "__main__":
    # Generate types first, to populate type registry.
    filePaths = GenerateTypes()

    # Proceed with generating functions.
    filePaths += GenerateFunctions()

    # Format all the code to standard.
    FormatCode(filePaths)
