#!/usr/bin/env python

"""
Main entry point / script for generating GraphicsMath C++ and Python source code from templates.
"""

import os

from codeGen.utils import (
    GetTemplateFile,
    GenerateCode,
    WriteFile,
    FormatCode,
    LowerCamelCase,
    UpperCamelCase,
    PrintMessage,
)

from codeGen.types import (
    ScalarType,
    VectorType,
    RangeType,
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
    FunctionCategory,
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
Global set of Scalar value types.
"""
NUMERIC_SCALAR_TYPES = [ScalarType(FLOAT), ScalarType(INT)]
SCALAR_TYPES = NUMERIC_SCALAR_TYPES + [ScalarType(BOOL)]

"""
Global set of vector value types to generate.
"""
MATRIX_TYPES = [
    VectorType((3, 3), ScalarType(FLOAT)),
    VectorType((4, 4), ScalarType(FLOAT)),
]

SINGLE_INDEX_VECTOR_TYPES_FLOAT = [
    VectorType((2,), ScalarType(FLOAT)),
    VectorType((3,), ScalarType(FLOAT)),
    VectorType((4,), ScalarType(FLOAT)),
]

SINGLE_INDEX_VECTOR_TYPES_INT = [
    VectorType((2,), ScalarType(INT)),
    VectorType((3,), ScalarType(INT)),
    VectorType((4,), ScalarType(INT)),
]

VECTOR_TYPES = SINGLE_INDEX_VECTOR_TYPES_FLOAT + SINGLE_INDEX_VECTOR_TYPES_INT + MATRIX_TYPES

"""
RANGE_TYPES is the fixed, global set of range-based types (min, max) to generate code for.
"""
RANGE_TYPES = [RangeType(scalarType) for scalarType in NUMERIC_SCALAR_TYPES] + [
    RangeType(vectorType) for vectorType in VECTOR_TYPES if len(vectorType.shape) == 1
]


"""
ARRAY_TYPES is the fixed, global set of array-based value types to generate code for.
"""
ARRAY_TYPES = [ArrayType(scalarType) for scalarType in SCALAR_TYPES] + [
    ArrayType(vectorType) for vectorType in VECTOR_TYPES
]

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

def PopulateCompositeTypes():
    """
    Populate the COMPOSITE_TYPES dictionary.
    """
    compositeTypes = []
    for compositeType in compositeTypes:
        COMPOSITE_TYPES[compositeType.name] = compositeType


def GenerateTypes():
    """
    Top-level entry point for generating all data type source files.
    Vectors and matrices types will be generated.
    Array types of pod, vectors, and matrices will also be generated.

    Returns:
        tuple: (
            list: paths to of generated source files.
            list: associated ValueType(s)
        )
    """
    # TODO Generate composite types.
    PrintMessage("Generating types...")

    PopulateCompositeTypes()

    filePaths = []
    valueTypes = VECTOR_TYPES + RANGE_TYPES + ARRAY_TYPES + COMPOSITE_TYPES.values()
    for valueType in valueTypes:
        # C++ source code.
        filePaths.append(
            GenerateCode(
                os.path.join(
                    TYPES_DIR, "{category}Type.h".format(category=valueType.CATEGORY,)
                ),
                os.path.join(TYPES_DIR, valueType.headerFileName),
                valueType=valueType,
            )
        )

        # Cpp tests.
        filePaths.append(
            GenerateCode(
                os.path.join(
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{category}Type.cpp".format(
                        category=UpperCamelCase(valueType.CATEGORY),
                    ),
                ),
                os.path.join(
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{className}.cpp".format(className=valueType.className),
                ),
                valueType=valueType,
            )
        )

        # Python bindings.
        filePaths.append(
            GenerateCode(
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    "bind{category}Type.cpp".format(
                        category=UpperCamelCase(valueType.CATEGORY),
                    ),
                ),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    "bind{className}.cpp".format(className=valueType.className),
                ),
                valueType=valueType,
            )
        )

        # Tests for python bindings.
        filePaths.append(
            GenerateCode(
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{category}Type.py".format(
                        category=UpperCamelCase(valueType.CATEGORY),
                    ),
                ),
                os.path.join(
                    PYTHON_DIR,
                    TYPES_DIR,
                    TESTS_DIR,
                    "test{className}.py".format(className=valueType.className),
                ),
                valueType=valueType,
            )
        )

    return filePaths, valueTypes


def GenerateFunctions():
    """
    Generate code for all of the functions.

    Returns:
        list: file paths to the generated files.
    """
    PrintMessage("Generating functions...")

    # Unary operations.
    unaryOps = []
    for valueType in (
        [ScalarType(FLOAT),] + SINGLE_INDEX_VECTOR_TYPES_FLOAT + MATRIX_TYPES
    ):
        unaryOps.append(
            FunctionInterface(
                arguments=[FunctionArg("value", valueType, Mutability.Const),],
                returnType=valueType,
            )
        )

    # Binary comparison operations.
    binaryComparisonOps = []
    for valueType in SCALAR_TYPES + VECTOR_TYPES:
        binaryComparisonOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("valueA", valueType, Mutability.Const),
                    FunctionArg("valueB", valueType, Mutability.Const),
                ],
                returnType=valueType,
            )
        )

    # Vector product(s).
    vectorProductOps = []
    for vectorType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        vectorProductOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("lhs", vectorType, Mutability.Const),
                    FunctionArg("rhs", vectorType, Mutability.Const),
                ],
                returnType=vectorType.elementType,
            )
        )

    # Cross product.
    crossProductOps = []
    for vectorType in (VectorType((3,), ScalarType(FLOAT)),):
        crossProductOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("lhs", vectorType, Mutability.Const),
                    FunctionArg("rhs", vectorType, Mutability.Const),
                ],
                returnType=vectorType,
            )
        )

    # Vector reduction.
    vectorReductionOps = []
    for vectorType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        vectorReductionOps.append(
            FunctionInterface(
                arguments=[FunctionArg("vector", vectorType, Mutability.Const),],
                returnType=vectorType.elementType,
            )
        )

    # Vector unary operation.
    vectorOps = []
    for vectorType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        vectorOps.append(
            FunctionInterface(
                arguments=[FunctionArg("vector", vectorType, Mutability.Const),],
                returnType=vectorType,
            )
        )

    # Set matrix value.
    setMatrixOps = []
    for matrixType in MATRIX_TYPES:
        setMatrixOps.append(
            FunctionInterface(
                arguments=[FunctionArg("matrix", matrixType, Mutability.Mutable),],
            )
        )

    # Check matrix value.
    checkMatrixOps = []
    for matrixType in MATRIX_TYPES:
        checkMatrixOps.append(
            FunctionInterface(
                arguments=[FunctionArg("matrix", matrixType, Mutability.Const),],
                returnType=ScalarType(BOOL),
            )
        )

    # Matrix unary ops.
    matrixUnaryOps = []
    for matrixType in MATRIX_TYPES:
        matrixUnaryOps.append(
            FunctionInterface(
                arguments=[FunctionArg("matrix", matrixType, Mutability.Const),],
                returnType=matrixType,
            )
        )

    # Matrix binary ops.
    matrixBinaryOps = []
    for matrixType in MATRIX_TYPES:
        matrixBinaryOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("lhs", matrixType, Mutability.Const),
                    FunctionArg("rhs", matrixType, Mutability.Const),
                ],
                returnType=matrixType,
            )
        )

    # Set vector transform channels.
    setVectorTransformOps = []
    for matrixType in MATRIX_TYPES:
        setVectorTransformOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg(
                        "vector",
                        VectorType((matrixType.shape[0] - 1,), matrixType.elementType),
                        Mutability.Const,
                    ),
                    FunctionArg("matrix", matrixType, Mutability.Mutable),
                ],
            )
        )

    # Angle interfaces.
    angleOps = []
    for scalarType in (ScalarType(FLOAT),):
        angleOps.append(
            FunctionInterface(
                arguments=[FunctionArg("angle", scalarType, Mutability.Const),],
                returnType=scalarType,
            )
        )

    # Euclidean space point operations.
    pointReductionOps = []
    for vectorType in (
        VectorType((2,), ScalarType(FLOAT)),
        VectorType((3,), ScalarType(FLOAT)),
    ):
        pointReductionOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("pointA", vectorType, Mutability.Const),
                    FunctionArg("pointB", vectorType, Mutability.Const),
                ],
                returnType=vectorType.elementType,
            )
        )

    # Interpolation operators.
    interpolationOps = []
    for valueType in (
        [ScalarType(FLOAT)] + MATRIX_TYPES + SINGLE_INDEX_VECTOR_TYPES_FLOAT
    ):
        arguments = [
            FunctionArg("source", valueType, Mutability.Const),
            FunctionArg("target", valueType, Mutability.Const),
        ]
        if valueType.isScalar:
            arguments.append(FunctionArg("weight", valueType, Mutability.Const))
        else:
            assert valueType.isVector
            arguments.append(
                FunctionArg("weight", valueType.elementType, Mutability.Const)
            )

        interpolationOps.append(
            FunctionInterface(arguments=arguments, returnType=valueType,)
        )

    # Map operators.
    mapOps = []
    for valueType in (
        [ScalarType(FLOAT)] + MATRIX_TYPES + SINGLE_INDEX_VECTOR_TYPES_FLOAT
    ):
        if valueType.isScalar:
            rangeValueType = RangeType(valueType)
        else:
            assert valueType.isVector
            rangeValueType = RangeType(valueType.elementType)

        arguments = [
            FunctionArg("sourceValue", valueType, Mutability.Const),
            FunctionArg("sourceRange", rangeValueType, Mutability.Const),
            FunctionArg("targetRange", rangeValueType, Mutability.Const),
        ]

        mapOps.append(FunctionInterface(arguments=arguments, returnType=valueType,))

    # Map operators.
    clampOps = []
    for valueType in (NUMERIC_SCALAR_TYPES + VECTOR_TYPES):
        if valueType.isScalar:
            rangeValueType = RangeType(valueType)
        else:
            assert valueType.isVector
            rangeValueType = RangeType(valueType.elementType)

        arguments = [
            FunctionArg("value", valueType, Mutability.Const),
            FunctionArg("range", rangeValueType, Mutability.Const),
        ]

        clampOps.append(FunctionInterface(arguments=arguments, returnType=valueType,))

    rayOps = []
    for valueType in (
        VectorType((2,), ScalarType(FLOAT)),
        VectorType((3,), ScalarType(FLOAT)),
    ):
        rayOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("origin", valueType, Mutability.Const),
                    FunctionArg("direction", valueType, Mutability.Const),
                    FunctionArg("magnitude", valueType.elementType, Mutability.Const),
                ],
                returnType=valueType,
            )
        )

    rangeOps = []
    for valueType in RANGE_TYPES:
        rangeOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("lhs", valueType, Mutability.Const),
                    FunctionArg("rhs", valueType, Mutability.Const),
                ],
                returnType=valueType,
            )
        )

    quadraticOps = []
    for valueType in (ScalarType(FLOAT),):
        quadraticOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("a", valueType, Mutability.Const),
                    FunctionArg("b", valueType, Mutability.Const),
                    FunctionArg("c", valueType, Mutability.Const),
                    FunctionArg(
                        "roots", VectorType((2,), valueType), Mutability.Mutable
                    ),
                ],
                returnType=ScalarType(INT),
            )
        )

    raySphereIntersectionOps = []
    for valueType in (VectorType((3,), ScalarType(FLOAT)),):
        raySphereIntersectionOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("sphereOrigin", valueType, Mutability.Const),
                    FunctionArg(
                        "sphereRadius", valueType.elementType, Mutability.Const
                    ),
                    FunctionArg("rayOrigin", valueType, Mutability.Const),
                    FunctionArg("rayDirection", valueType, Mutability.Const),
                    FunctionArg(
                        "intersections",
                        RangeType(valueType.elementType),
                        Mutability.Mutable,
                    ),
                ],
                returnType=ScalarType(INT),
            )
        )

    rayAABBIntersectionOps = []
    for valueType in SINGLE_INDEX_VECTOR_TYPES_FLOAT:
        rayAABBIntersectionOps.append(
            FunctionInterface(
                arguments=[
                    FunctionArg("rayOrigin", valueType, Mutability.Const),
                    FunctionArg("rayDirection", valueType, Mutability.Const),
                    FunctionArg("aabb", RangeType(valueType), Mutability.Const),
                    FunctionArg(
                        "intersections",
                        RangeType(valueType.elementType),
                        Mutability.Mutable,
                    ),
                ],
                returnType=ScalarType(BOOL),
            )
        )

    # Random number generation.
    randomOps = []
    for valueType in NUMERIC_SCALAR_TYPES:
        randomOps.append(
            FunctionInterface(
                arguments=[FunctionArg("range", RangeType(valueType), Mutability.Const),],
                returnType=valueType,
            )
        )

    functionGroups = [
        # Basic.
        FunctionGroup(["floor", "ceil", "abs",], unaryOps, FunctionCategory.BASIC),
        FunctionGroup(["min", "max",], binaryComparisonOps, FunctionCategory.BASIC),
        FunctionGroup(["quadraticRoots",], quadraticOps, FunctionCategory.BASIC),
        FunctionGroup(["degrees", "radians",], angleOps, FunctionCategory.BASIC),
        FunctionGroup(["randomNumber",], randomOps, FunctionCategory.BASIC),
        FunctionGroup(
            ["linearInterpolation",], interpolationOps, FunctionCategory.BASIC
        ),
        FunctionGroup(["linearMap",], mapOps, FunctionCategory.BASIC),
        FunctionGroup(["clamp",], clampOps, FunctionCategory.BASIC),
        FunctionGroup(["intersection", "expand"], rangeOps, FunctionCategory.BASIC),

        # Linear algebra.
        FunctionGroup(["isIdentity"], checkMatrixOps, FunctionCategory.LINEAR_ALGEBRA),
        FunctionGroup(["setIdentity"], setMatrixOps, FunctionCategory.LINEAR_ALGEBRA),
        FunctionGroup(["transpose"], matrixUnaryOps, FunctionCategory.LINEAR_ALGEBRA),
        FunctionGroup(
            ["matrixProduct"], matrixBinaryOps, FunctionCategory.LINEAR_ALGEBRA
        ),
        FunctionGroup(["normalize",], vectorOps, FunctionCategory.LINEAR_ALGEBRA),
        FunctionGroup(
            ["length", "lengthSquared",],
            vectorReductionOps,
            FunctionCategory.LINEAR_ALGEBRA,
        ),
        FunctionGroup(
            ["dotProduct",], vectorProductOps, FunctionCategory.LINEAR_ALGEBRA
        ),
        FunctionGroup(
            ["crossProduct",], crossProductOps, FunctionCategory.LINEAR_ALGEBRA
        ),
        FunctionGroup(["distance"], pointReductionOps, FunctionCategory.LINEAR_ALGEBRA),
        FunctionGroup(
            ["setTranslate", "setScale",],
            setVectorTransformOps,
            FunctionCategory.LINEAR_ALGEBRA,
        ),

        # Ray tracing
        FunctionGroup(["rayPosition",], rayOps, FunctionCategory.RAY_TRACING),
        FunctionGroup(
            ["raySphereIntersection",],
            raySphereIntersectionOps,
            FunctionCategory.RAY_TRACING,
        ),
        FunctionGroup(
            ["rayAABBIntersection",],
            rayAABBIntersectionOps,
            FunctionCategory.RAY_TRACING,
        ),
    ]

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
    # Generate the complete set ValueTypes first, pre-requisite to generating functions.
    filePaths, valueTypes = GenerateTypes()

    # Follow up with generating functions.
    filePaths += GenerateFunctions()

    # Generate python module.
    PrintMessage("Generating python module...")
    filePaths.append(
        GenerateCode(
            os.path.join(PYTHON_DIR, "module.cpp"),
            os.path.join(PYTHON_DIR, "module.cpp"),
            types=valueTypes,
            functions=FUNCTIONS.values(),
            UpperCamelCase=UpperCamelCase,
        )
    )

    # Format all the code to standard.
    PrintMessage("Formatting code...")
    FormatCode(filePaths)
