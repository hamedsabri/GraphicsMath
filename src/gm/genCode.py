#!/usr/bin/env python

"""
Main entry point / script for generating GraphicsMath C++ code from templates.
"""

import os

from codeGen.utils import (
    GetTemplateFile,
    GenerateCode,
    WriteFile,
    FormatCode,
    LowerCamelCase,
    UpperCamelCase,
)

from codeGen.types import (
    PODType,
    VectorType,
    ArrayType,
    CompositeType,
    CompositeElement,
    INT,
    FLOAT,
    BOOL,
)

from codeGen.functions import (
    FunctionGroup,
    Function,
    FunctionInterface,
    FunctionArg,
    Mutability,
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
Name of the benchmarks sub-directory, under functions/, where benchmarking code reside.
"""
BENCHMARKS_DIR = "benchmarks"

"""
Name of the python subdirectory, where the bindings reside.
"""
PYTHON_DIR = "python"

"""
Global set of POD value types.
"""
NUMERIC_POD_TYPES = [PODType(FLOAT), PODType(INT)]
POD_TYPES = NUMERIC_POD_TYPES + [PODType(BOOL)]

"""
Global set of vector value types to generate.
"""
MATRIX_TYPES = [
    VectorType((3, 3), PODType(FLOAT)),
    VectorType((4, 4), PODType(FLOAT)),
]

SINGLE_INDEX_VECTOR_TYPES_FLOAT = [
    VectorType((2,), PODType(FLOAT)),
    VectorType((3,), PODType(FLOAT)),
    VectorType((4,), PODType(FLOAT)),
]

SINGLE_INDEX_VECTOR_TYPES_INT = [
    VectorType((2,), PODType(INT)),
    VectorType((3,), PODType(INT)),
    VectorType((4,), PODType(INT)),
]

VECTOR_TYPES = sorted(
    SINGLE_INDEX_VECTOR_TYPES_FLOAT + SINGLE_INDEX_VECTOR_TYPES_INT + MATRIX_TYPES
)

"""
COMPOSITE_TYPES is a dict of type name (str) -> type object (CompositeType).
It is populated in GenerateCompositeTypes.
"""
COMPOSITE_TYPES = {}

"""
FUNCTIONS is a dict of function name (str) -> function object (Function).
It is populated in GenerateFunctions.
"""
FUNCTIONS = {}

#
# Code generation for types.
#


def PopulateBoundsCompositeTypes():
    """
    Populate bounds composite types, by updating the global ``COMPOSITE_TYPES``.
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

        # Instantiate the type with min-max elements.
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

    return filePaths


def GenerateCompositeTypes():
    """
    Generate all composite type source files.

    Returns:
        list: paths to generated source files.
    """
    PopulateBoundsCompositeTypes()

    # Generate C++ source code.
    filePaths = []

    for compositeType in COMPOSITE_TYPES.values():
        # C++ source code.
        filePaths.append(
            GenerateCode(
                os.path.join(TYPES_DIR, "compositeType.h"),
                os.path.join(TYPES_DIR, compositeType.headerFileName),
                compositeType=compositeType,
            )
        )

        # Python bindings.
        filePaths.append(
            GenerateCode(
                os.path.join(PYTHON_DIR, TYPES_DIR, "bindCompositeType.cpp"),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    "bind{className}.cpp".format(className=compositeType.className),
                ),
                compositeType=compositeType,
            )
        )

        # Tests for python bindings.
        filePaths.append(
            GenerateCode(
                os.path.join(PYTHON_DIR, TYPES_DIR, TESTS_DIR, "testCompositeType.py"),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{className}.py".format(className=compositeType.className),
                ),
                compositeType=compositeType,
            )
        )

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
        filePaths.append(
            GenerateCode(
                os.path.join(TYPES_DIR, "arrayType.h"),
                os.path.join(TYPES_DIR, arrayType.headerFileName),
                arrayType=arrayType,
            )
        )

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
        # C++ header source.
        filePaths.append(
            GenerateCode(
                os.path.join(TYPES_DIR, "vectorType.h"),
                os.path.join(TYPES_DIR, vectorType.headerFileName),
                vectorType=vectorType,
            )
        )

        # C++ tests.
        filePaths.append(
            GenerateCode(
                os.path.join(TYPES_DIR, TESTS_DIR, "testVectorType.cpp"),
                os.path.join(
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{className}.cpp".format(className=vectorType.className),
                ),
                vectorType=vectorType,
            )
        )

        # Python bindings source.
        filePaths.append(
            GenerateCode(
                os.path.join(PYTHON_DIR, TYPES_DIR, "bindVectorType.cpp"),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    "bind{className}.cpp".format(className=vectorType.className),
                ),
                vectorType=vectorType,
            )
        )

        # Python bindings tests.
        filePaths.append(
            GenerateCode(
                os.path.join(PYTHON_DIR, TYPES_DIR, TESTS_DIR, "testVectorType.py"),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{className}.py".format(className=vectorType.className),
                ),
                vectorType=vectorType,
            )
        )

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


def GenerateFunctions():
    """
    Generate code for all of the functions.

    Returns:
        list: file paths to the generated files.
    """
    functionGroups = []

    # Single input element-wise computation.
    singleInputElementWiseInterfaces = []
    for valueType in [PODType(FLOAT)] + SINGLE_INDEX_VECTOR_TYPES_FLOAT + MATRIX_TYPES:
        singleInputElementWiseInterfaces.append(
            FunctionInterface(
                arguments=[FunctionArg("value", valueType, Mutability.Const),],
                returnType=valueType,
            )
        )
    functionGroups.append(
        FunctionGroup(["floor", "ceil",], interfaces=singleInputElementWiseInterfaces,)
    )

    # Dual-input element-wise computation.
    dualInputElementWiseInterfaces = []
    for valueType in POD_TYPES + VECTOR_TYPES:
        dualInputElementWiseInterfaces.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("valueA", valueType, Mutability.Const),
                    FunctionArg("valueB", valueType, Mutability.Const),
                ],
                returnType=valueType,
            )
        )
    functionGroups.append(
        FunctionGroup(["min", "max",], interfaces=dualInputElementWiseInterfaces,)
    )

    # Vector product(s).
    vectorProductInterfaces = []
    for vectorType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        vectorProductInterfaces.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("lhs", vectorType, Mutability.Const),
                    FunctionArg("rhs", vectorType, Mutability.Const),
                ],
                returnType=vectorType.elementType,
            )
        )
    functionGroups.append(
        FunctionGroup(["dotProduct"], interfaces=vectorProductInterfaces,)
    )

    # Vector reduction.
    vectorReductionInterfaces = []
    for vectorType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        vectorReductionInterfaces.append(
            FunctionInterface(
                arguments=[FunctionArg("vector", vectorType, Mutability.Const),],
                returnType=vectorType.elementType,
            )
        )

    functionGroups.append(
        FunctionGroup(
            ["length", "lengthSquared"], interfaces=vectorReductionInterfaces,
        )
    )

    # Set matrix value.
    setMatrixInterfaces = []
    for matrixType in MATRIX_TYPES:
        setMatrixInterfaces.append(
            FunctionInterface(
                arguments=[FunctionArg("matrix", matrixType, Mutability.Mutable),],
            )
        )
    functionGroups.append(
        FunctionGroup(["setIdentity"], interfaces=setMatrixInterfaces,)
    )

    # Check matrix value.
    checkMatrixInterfaces = []
    for matrixType in MATRIX_TYPES:
        checkMatrixInterfaces.append(
            FunctionInterface(
                arguments=[FunctionArg("matrix", matrixType, Mutability.Mutable),],
                returnType=PODType(BOOL),
            )
        )
    functionGroups.append(
        FunctionGroup(["isIdentity"], interfaces=checkMatrixInterfaces,)
    )

    # Generate code.
    filePaths = []
    for functionGroup in functionGroups:
        for function in functionGroup.functions:
            # Generate C++ source code.
            filePaths.append(
                GenerateCode(
                    os.path.join(FUNCTIONS_DIR, function.headerFileName),
                    os.path.join(FUNCTIONS_DIR, function.headerFileName),
                    function=function,
                )
            )

            # Generate C++ test code (if the template is available).
            # Some tests are hand-authored.
            testTemplatePath = os.path.join(
                FUNCTIONS_DIR, TESTS_DIR, "test{name}.cpp".format(name=function.name)
            )
            if os.path.isfile(GetTemplateFile(testTemplatePath)):
                filePaths.append(
                    GenerateCode(
                        testTemplatePath,
                        os.path.join(
                            FUNCTIONS_DIR,
                            TESTS_DIR,
                            "test{name}.cpp".format(name=function.name),
                        ),
                        function=function,
                    )
                )

            # Benchmarking.
            filePaths.append(
                GenerateCode(
                    os.path.join(
                        FUNCTIONS_DIR, BENCHMARKS_DIR, "benchmarkFunction.cpp"
                    ),
                    os.path.join(
                        FUNCTIONS_DIR,
                        BENCHMARKS_DIR,
                        "benchmark{name}.cpp".format(name=function.name),
                    ),
                    function=function,
                )
            )

            # Python bindings source.
            filePaths.append(
                GenerateCode(
                    os.path.join(PYTHON_DIR, FUNCTIONS_DIR, "bindFunction.cpp"),
                    os.path.join(
                        PYTHON_DIR,
                        FUNCTIONS_DIR,
                        "bind{name}.cpp".format(name=function.name),
                    ),
                    function=function,
                )
            )

            # Register in global FUNCTIONS
            assert function.name not in FUNCTIONS
            FUNCTIONS[function.name] = function

    return filePaths


#
# Main
#

if __name__ == "__main__":
    # Generate types first, to populate type registry.
    filePaths = GenerateTypes()

    # Proceed with generating functions.
    filePaths += GenerateFunctions()

    # Generate python module.
    filePaths.append(
        GenerateCode(
            os.path.join(PYTHON_DIR, "module.cpp"),
            os.path.join(PYTHON_DIR, "module.cpp"),
            types=list(VECTOR_TYPES) + COMPOSITE_TYPES.values(),
            functions=FUNCTIONS.values(),
            UpperCamelCase=UpperCamelCase,
        )
    )

    # Format all the code to standard.
    FormatCode(filePaths)
