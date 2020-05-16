"""
A collection of classes serving as contextual objects used in the code-gen templates.
"""

from utils import UpperCamelCase


class Function:
    """
    A simple code-gen context object for a function.

    Args:
        name (str): name of the function.
    """

    def __init__(self, name):
        self._name = name

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


class FunctionGroup:
    """
    Group of functions which share a common code-generation context.
    """

    def __init__(self, functionNames, **functionContext):
        self.functions = []
        for name in functionNames:
            function = Function(name)

            # Set the function context as attributes on the Function each object.
            for key, value in functionContext.items():
                setattr(function, key, value)

            self.functions.append(function)
