"""
A collection of classes serving as contextual objects used in the code-gen templates.
"""

from utils import UpperCamelCase
from collections import OrderedDict


class Mutability:
    """
    Describes the mutability of a function parameter.
    """
    Const = 0
    Mutable = 1


class FunctionParameter:
    """
    Description of a function parameter.

    Args:
        name (str): name of this parameter.
        type (ValueType): type of the parameter.
        mutability (Mutability): mutability of the parameter.
    """

    def __init__(self, name, type, mutability):
        self.name = name
        self.type = type
        self.mutability = mutability

    @property
    def constQualifier(self):
        if self.mutability == Mutability.Const:
            return "const"
        else:
            return ""

    @property
    def variableName(self):
        if self.mutability == Mutability.Const:
            return "i_" + self.name
        else:
            return "o_" + self.name


class FunctionInterface:
    """
    Interface of a function, describing the parameters (type and qualifiers), and return type.

    Args:
        parameters (list): ordered list of function parameters.
        returnType (ValueType): return value type.  If `None` is specified, then the function return type is void.
    """

    def __init__(self, parameters, returnType=None):
        self._parameters = OrderedDict([(param.name, param) for param in parameters])
        self._returnType = returnType

    @property
    def returnType(self):
        if self._returnType:
            return self._returnType.className
        else:
            return "void"

    @property
    def typedParameters(self):
        """
        Generate a string of typed, and named parameters.
        """
        paramString = ""
        for index, param in enumerate(self._parameters.values()):
            paramString += param.constQualifier
            paramString += " "
            paramString += param.type.className
            paramString += "& "
            paramString += param.variableName
            if index + 1 < len(self._parameters):
                paramString += ", "
        return paramString

    @property
    def namedParameters(self):
        return ", ".join([param.variableName for param in self._parameters.values()])

    def Param(self, name):
        """
        Retrieve a ``FunctionParameter` from this interface, by name.
        """
        return self._parameters[name]


class Function:
    """
    A simple code-gen context object for a function.

    Args:
        name (str): name of the function.
        interfaces (list): list of interfaces which describe the different variations of
            parameters and return types.
    """

    def __init__(self, name, interfaces):
        self._name = name
        self.interfaces = interfaces

    @property
    def headerFileName(self):
        """
        Get the name of the header hosting this function.
        """
        return "{name}.h".format(name=self._name,)

    @property
    def name(self):
        """
        Returns:
            str: the C++ symbol name of this function.
        """
        return UpperCamelCase(self._name)

    @property
    def types(self):
        """
        Return:
            set: the unique set of types used across all interfaces of this function.
        """
        types = set()
        for interface in self.interfaces:
            types = types.union([param.type for param in interface._parameters.values()])
            if interface._returnType:
                types = types.union([interface._returnType])
        return types


class FunctionGroup:
    """
    Group of functions which share a common code-generation context.
    """

    def __init__(self, functionNames, interfaces):
        self.functions = []
        for name in functionNames:
            function = Function(name, interfaces)
            self.functions.append(function)
