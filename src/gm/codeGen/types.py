"""
types.py

A collection of classes representing value types, serving as contextual objects
used in the code generation templates.
"""


import os
import functools
import collections

from utils import LowerCamelCase, UpperCamelCase

"""
Scalar types we are interested in generating code for.
"""
BOOL = "bool"
INT = "int"
FLOAT = "float"
DOUBLE = "double"

"""
Namespace of this library.
"""
NAMESPACE = "gm::"


class ValueType:
    """
    Abstract base class for all value types in the GraphicsMath library.

    ValueType instances are used throughout the code generation templates, for both
    C++ and python sources, and for both types and functions.
    """

    CATEGORY = None

    @property
    def className(self):
        """
        Implementation should return the name of the C++ class or typename associated
        with the value type.
        """
        raise NotImplementedError()

    @property
    def headerFileName(self):
        """
        Implementation should return the base file name of the header associated with the value type.
        """
        raise NotImplementedError()

    @property
    def varName(self):
        """
        Implementation should return a variable name suitable for the current value type.
        """
        raise NotImplementedError()

    def CppValue(self, value):
        """
        Implementation should implement this helper method for converting a value instance into
        a representative string, with respect to the current value type and to the C++ language.
        """
        raise NotImplementedError()

    def PyValue(self, value):
        """
        Implementation should implement this helper method for converting a value instance into
        a representative string, with respect to the current value type and to the Python language.
        """
        raise NotImplementedError()

    @property
    def namespacedClassName(self):
        """
        Returns:
             str: Globally namespaced symbol name associated with this value type.
        """
        return NAMESPACE + self.className

    @property
    def isScalar(self):
        """
        Implementation should return ``True`` if it is a ScalarType.  By default, ``False`` will be returned.

        Returns:
            bool: False
        """
        return False

    @property
    def isVector(self):
        """
        Implementation should return ``True`` if it is a VectorType.  By default, ``False`` will be returned.

        Returns:
            bool: False
        """
        return False

    @property
    def isArray(self):
        """
        Implementation should return ``True`` if it is a ArrayType.  By default, ``False`` will be returned.

        Returns:
            bool: False
        """
        return False

    @property
    def isRange(self):
        """
        Implementation should return ``True`` if it is a RangeType.  By default, ``False`` will be returned.

        Returns:
            bool: False
        """
        return False

    @property
    def isComposite(self):
        """
        Implementation should return ``True`` if it is a array type.  By default, ``False`` will be returned.

        Returns:
            bool: False
        """
        return False


class ScalarType(ValueType):
    """
    Scalar type, used in code-gen contexts.
    Without being perfectly accurate to the mathematical definition, Scalar to capture POD types provided by C++.
    POD is rather tiring to type!

    Args:
        typeName (str): the C++ typename of the value type.

    Class members:
        CATEGORY (str): The named category of all scalar value types.
    """

    CATEGORY = "scalar"

    def __init__(self, typeName):
        assert isinstance(typeName, str)
        self._typeName = typeName

    def __hash__(self):
        """
        Scalar types are simply unique by their C++ typename.
        """
        return hash((self._typeName))

    @property
    def className(self):
        """
        Returns:
            str: the ctype of this type.
        """
        return self._typeName

    @property
    def namespacedClassName(self):
        """
        The scalar types we have defined so far do not need a namespace.
        The design choice has been made to not obfuscate the POD types with type definition.
        """
        return self.className

    @property
    def isScalar(self):
        """
        Returns:
            bool: True.
        """
        return True

    def CppValue(self, value):
        """
        Convert the ``value`` instance to the C++ compliant value of the current type, as a string.

        Args:
            value (object): value instance.

        Returns:
            str: string representation of ``value``.
        """
        if self.className == INT:
            return str(int(value))
        elif self.className == FLOAT:
            return str(float(value)) + "f"
        elif self.className == DOUBLE:
            return str(float(value))
        elif self.className == BOOL:
            return str(bool(value)).lower()

    def PyValue(self, value):
        """
        Convert the ``value`` instance to the Python compliant value of the current type, as a string.

        Args:
            value (object): value instance.

        Returns:
            str: string representation of ``value``.
        """
        if self.className == INT:
            return str(int(value))
        elif self.className in (FLOAT, DOUBLE):
            return str(float(value))
        elif self.className == BOOL:
            return str(bool(value))

    @property
    def varName(self):
        """
        Returns:
            str: variable name for this value type.
        """
        return self.className + "Val"


class ElementContainerType(ValueType):
    """
    Base class for all value types which are homogenous element type containers.
    """

    def __hash__(self):
        """
        The hash combination of its element type, with an Array suffix.
        """
        return hash((self.elementType, self.CATEGORY))

    def CppValue(self, value):
        """
        Convert the ``value`` instance to the C++ compliant value of the current vector's element type, as a string.

        Args:
            value (object): value instance.

        Returns:
            str: string representation of ``value``.
        """
        return self.elementType.CppValue(value)

    def PyValue(self, value):
        """
        Convert the ``value`` instance to the Python compliant value of the current vector's element type, as a string.

        Args:
            value (object): value instance.

        Returns:
            str: string representation of ``value``.
        """
        return self.elementType.PyValue(value)

    @property
    def varName(self):
        """
        Returns:
            str: A name for variables of this type.
        """
        return self.CATEGORY


class VectorType(ElementContainerType):
    """
    Code generation representation of a homogenously typed fixed size container of arbituary shape.

    VectorType captures the following categories of value types:

        1. Vectors in the traditional mathematical sense (think column and row vectors)
        2. Matrices.

    Args:
        shape (tuple): The shape, or dimensions of this vector container type.
        elementType (ValueType): The value type of the elements within this vector container.

    Class members:
        CATEGORY (str): The named category of all vector value types.
    """

    CATEGORY = "vector"

    def __init__(self, shape, elementType):
        assert isinstance(shape, tuple)
        assert isinstance(elementType, ScalarType)
        self.shape = shape
        self.elementType = elementType

    def __hash__(self):
        """
        VectorType(s) are unique by its shape and element type.
        """
        return hash((self.shape, self.elementType))

    @property
    def className(self):
        """
        VectorType class names are described by the combination of:

            1. A named prefix associated with the shape dimension,
            2. The shape's _first_ length
            3. The element type.

        We might need to extend this if there was a requirement to support 3 X 4 matrices
        for efficient storage of per-instance matrices.
        """
        if len(self.shape) == 2:
            prefix = "Mat"
        else:
            prefix = "Vec"

        return "{prefix}{shape}{elementType}".format(
            prefix=prefix,
            shape=str(self.shape[0]),
            elementType=self.elementType.className[0],
        )

    @property
    def headerFileName(self):
        """
        Similar to ``VectorType.className``, but lowerCamelCasing for the named shape prefix.
        """
        if len(self.shape) == 2:
            prefix = "mat"
        else:
            prefix = "vec"

        return "{prefix}{shape}{elementType}.h".format(
            prefix=prefix,
            shape=str(self.shape[0]),
            elementType=self.elementType.className[0],
        )

    @property
    def elementSize(self):
        """
        Returns:
            int: the fixed number of elements in this vector container.  The element size is the
               product of all the shape lengths.
        """
        return functools.reduce(lambda x, y: x * y, self.shape)

    @property
    def varName(self):
        """
        Returns:
            str: a meaningful prefix for naming variables of this type.
        """
        if len(self.shape) == 2:
            return "matrix"
        else:
            return "vector"

    @property
    def isVector(self):
        """
        Returns:
            bool: True, this class is indeed a vector!
        """
        return True


class RangeType(ElementContainerType):
    """
    Code generation object for representing a range of values, of a particular type, with lower and upper limits (min and max).

    Originally, RangeType(s) were generated as Bounds classes implemented through CompositeType -
    however, the it is also useful to have scalar value ranges.  The terminology "bounds" usually is
    associated with 2 dimensional or 3 dimensional ranges - it felt inappropriate for a 1 dimensional range.

    The code generation templates of RangeType(s) of integral element type also implement iteration policy for
    iterating over all the discrete "indices" within the range.  A useful application of this is for iterating
    over a Range2i, for accessing pixel values of a 2D image!

    Class members:
        CATEGORY (str): The named category of all Range value types.
    """

    CATEGORY = "range"

    def __init__(self, elementType):
        assert isinstance(elementType, (ScalarType, VectorType))
        self.elementType = elementType

    @property
    def className(self):
        """
        The class name of an RangeType is the class name of its element type joined
        with a "Range" suffix.

        Returns:
            str: the class name of this range type.
        """
        return "{elementTypeName}Range".format(
            elementTypeName=(UpperCamelCase(self.elementType.className))
        )

    @property
    def headerFileName(self):
        """
        The header file name of an RangeType is th header file name of its element type joined
        with a "Range" suffix.

        There is the special case when its element type is scalar - there is no header file
        associated with scalar types (they're C++ POD types, with no type definition).
        The lowerCamelCased className is used for scalar types.

        Returns:
            str: the header file name of this RangeType.
        """
        if self.elementType.isVector:
            return "{elementHeaderFileName}Range.h".format(
                elementHeaderFileName=os.path.splitext(self.elementType.headerFileName)[
                    0
                ]
            )
        else:
            return "{elementTypeName}Range.h".format(
                elementTypeName=LowerCamelCase(self.elementType.className),
            )

    @property
    def isRange(self):
        """
        Returns:
            bool: True, this class is indeed an array type.
        """
        return True


class ArrayType(ElementContainerType):
    """
    Code generation for an sequentially-ordered, dynamically re-sizable, and homogenously typed container.

    Currently, the array types in GraphicsMath are simply type definitions of std::vector.

    Class members:
        CATEGORY (str): The named category of all Array value types.
    """

    CATEGORY = "array"

    def __init__(self, elementType):
        assert isinstance(elementType, ValueType)
        self.elementType = elementType

    def __hash__(self):
        """
        The hash combination of its element type, with an Array suffix.
        """
        return hash((self.elementType, "Array"))

    @property
    def className(self):
        """
        The class name of an ArrayType is the class name of its element type joined
        with an "Array" suffix.

        Returns:
            str: the class name of this array type.
        """
        return "{elementTypeName}Array".format(
            elementTypeName=(UpperCamelCase(self.elementType.className))
        )

    @property
    def headerFileName(self):
        """
        The header file name of an ArrayType is th header file name of its element type joined
        with an "Array" suffix.

        There is the special case when its element type is scalar - there is no header file
        associated with scalar types (they're all POD types, with no type definition).
        The lowerCamelCased className is used for scalar types.

        Returns:
            str: the header file name of this array type.
        """
        if self.elementType.isVector:
            return "{elementHeaderFileName}Array.h".format(
                elementHeaderFileName=os.path.splitext(self.elementType.headerFileName)[
                    0
                ]
            )
        else:
            return "{elementTypeName}Array.h".format(
                elementTypeName=LowerCamelCase(self.elementType.className),
            )

    @property
    def isArray(self):
        """
        Returns:
            bool: True, this class is indeed an array type.
        """
        return True


class CompositeElement:
    """
    CompositeElement is a uniquely named child of a CompositeType.

    Args:
        name (str): is used to uniquely address this element from the parent Composite type.
        type (object): the data type.
        defaultValue (str): string, encoding C++ code that will be assigned to element member variable.
    """

    def __init__(self, name, type, defaultValue=None):
        self.name = name
        self.type = type
        self.defaultValue = defaultValue

    @property
    def accessorName(self):
        return UpperCamelCase(self.name)


class CompositeType(ValueType):
    """
    Code generation for an C++ composite data type.
    A composite type is a structure composed of one or more elements.
    Each element can be of type pod, vector, array, or another composite.

    Args:
        name (str): name of the composite type.
        elements (list): list of CompositeElement(s).
        extraIncludes (list): list of extras includes to encode near the top of the source file.

    Class members:
        CATEGORY (str): The named category of all Composite value types.
    """

    CATEGORY = "composite"

    def __init__(self, name, elements, extraIncludes=None):
        for element in elements:
            assert isinstance(element.type, ValueType)
        self.name = name
        self.elements = elements
        self.elementSize = len(self.elements)
        self.extraIncludes = extraIncludes or []

    def __hash__(self):
        return hash((self.name, self.elements))

    @property
    def className(self):
        return UpperCamelCase(self.name)

    @property
    def headerFileName(self):
        return "{name}.h".format(name=LowerCamelCase(self.name),)

    @property
    def isComposite(self):
        return True

    @property
    def varName(self):
        """
        Returns:
            str: variable name for this value type.
        """
        return self.name
