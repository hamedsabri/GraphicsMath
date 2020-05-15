"""
A collection of classes serving as contextual objects used in the code-gen templates.
"""

from utils import UpperCamelCase


class Function:
    """
    A simple code-gen context object for a function.  Not much to see here.
    """

    def __init__(self, functionName):
        self._name = functionName

    @property
    def headerFileName(self):
        """
        Get the name of the header hosting this function.
        """
        return "{name}.h".format(
            name=self._name,
        )

    @property
    def functionName(self):
        """
        Get the functions C++ symbol name (without namespace).
        """
        return UpperCamelCase(self._name)


class FunctionGroup:
    """
    Group of functions which share a common code-generation context.
    """

    def __init__(self, functionNames, **functionContext):
        self.functions = []
        for functionName in functionNames:
            function = Function(functionName)

            # Set the function context as attributes on the Function each object.
            for key, value in functionContext.items():
                setattr(function, key, value)

            self.functions.append(function)


