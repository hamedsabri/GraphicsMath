"""
A collection of classes serving as contextual objects used in the code-gen templates.
"""

from utils import UpperCamelCase
from collections import OrderedDict


class Mutability:
    """
    Enumeration class describing the mutability of a function parameter.
    """
    Const = 0
    Mutable = 1


class Parameter:
    """
    Description of a function parameter (type, qualifiers).

    Args:
        type (ValueType): type of the parameter.
        mutability (Mutability): mutability of the parameter.
    """

    def __init__(self, name, type, mutability):
        self.name = name
        self.type = type
        self.mutability = mutability

    @property
    def cppConstQualifier(self):
        if self.mutability == Mutability.Const:
            return "const"
        else:
            return ""

    @property
    def cppName(self):
        if self.mutability == Mutability.Const:
            return "i_" + self.name
        else:
            return "o_" + self.name


class Signature:
    """
    Signature of a function, describing the parameters (type and qualifiers), and return type.
    """

    def __init__(self, parameters, returnType=None):
        self._parameters = OrderedDict([(param.name, param) for param in parameters])
        self._returnType = returnType

    @property
    def cppReturnType(self):
        if self._returnType:
            return self._returnType.className
        else:
            return "void"

    @property
    def cppTypedParameters(self):
        """
        Generate the parameters component of a function signature.
        """
        paramString = ""
        for index, param in enumerate(self._parameters.values()):
            paramString += param.cppConstQualifier
            paramString += " "
            paramString += param.type.className
            paramString += "& "
            paramString += param.cppName
            if index + 1 < len(self._parameters):
                paramString += ", "
        return paramString

    @property
    def parameterNames(self):
        return ", ".join([param.cppName for param in self._parameters.values()])

    def GetParameter(self, name):
        """
        Retrieve a parameter from this signature, by name.
        """
        return self._parameters[name]


class Function:
    """
    A simple code-gen context object for a function.

    Args:
        name (str): name of the function.
    """

    def __init__(self, name, signatures):
        self._name = name
        self.signatures = signatures

    @property
    def headerFileName(self):
        """
        Get the name of the header hosting this function.
        """
        return "{name}.h".format(name=self._name,)

    @property
    def name(self):
        """
        Get the functions C++ symbol name (without namespace).
        """
        return UpperCamelCase(self._name)

    def GetTypeSet(self):
        """
        Return the set of types which are used in all the signatures of this function.
        """
        types = set()
        for signature in self.signatures:
            types = types.union([param.type for param in signature._parameters.values()])
            if signature._returnType:
                types = types.union([signature._returnType])
        return types


class FunctionGroup:
    """
    Group of functions which share a common code-generation context.
    """

    def __init__(self, functionNames, signatures):
        self.functions = []
        for name in functionNames:
            function = Function(name, signatures)
            self.functions.append(function)
