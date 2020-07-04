"""
Common code generation utilities.
"""

import os
import shlex
import subprocess
import math
import logging

from jinja2 import (
    Environment,
    Template,
    StrictUndefined,
    FileSystemLoader,
)

"""
Name of the code generation template directory.
"""
TEMPLATE_DIR = "template"

"""
Python source file extension.
"""
PY_SOURCE_EXT = ".py"

"""
CPP file extension(s).
"""
CPP_SOURCE_EXT = ".cpp"
CPP_HEADER_EXT = ".h"

"""
Global jinja2 environment.
"""
JINJA2_ENVIRONMENT = Environment(
    undefined=StrictUndefined,
    loader=FileSystemLoader(
        os.path.abspath(os.path.join(os.path.dirname(__file__), "..", TEMPLATE_DIR))
    ),
)

"""
Global logger
"""
LOGGER = logging.getLogger("gm")


class Style:
    """
    Style is a collection of ANSI escape sequences for styling text printed in the console.
    """

    HEADER = "\033[95m"
    BLUE = "\033[94m"
    GREEN = "\033[92m"
    WARNING = "\033[93m"
    FAIL = "\033[91m"
    END = "\033[0m"
    BOLD = "\033[1m"
    UNDERLINE = "\033[4m"


def PrintMessage(message):
    """
    Print a message in the console.

    Args:
        message (str): message to print.
    """
    print(Style.GREEN + Style.BOLD + message + Style.END)


def GetFileExt(filePath):
    """
    Get the file extension of ``filePath``.
    """
    return os.path.splitext(filePath)[1]


def UpperCamelCase(lowerCamelCaseStr):
    """
    Return the UpperCamelCase variant of a lower camel case string.
    """
    return lowerCamelCaseStr[0].upper() + lowerCamelCaseStr[1:]


def LowerCamelCase(upperCamelCaseStr):
    """
    Return the lowerCamelCase variant of an upper camel case string.
    """
    return upperCamelCaseStr[0].lower() + upperCamelCaseStr[1:]


def RunCommand(command, expectedCode=0):
    """
    Run the ``command`` by forking a subprocess.

    Args:
        command (str): The command to run.
        expectedCode (int): Expected return code of the process.
    """
    LOGGER.info("Running command {}".format(command))
    process = subprocess.Popen(
        shlex.split(command), stdout=subprocess.PIPE, stderr=subprocess.STDOUT
    )
    stdout, _ = process.communicate()
    if process.returncode != expectedCode:
        LOGGER.error(stdout)
        raise RuntimeError(
            "Expected return code {expectedCode} != {returnCode}".format(
                expectedCode=expectedCode, returnCode=process.returncode,
            )
        )


def WriteFile(filePath, content):
    """
    Write a file to disk with ``content`` at the specified ``filePath``.

    Args:
        filePath (str): path to write to.
        content (str): content to write.
    """
    LOGGER.info("Generated {!r}".format(filePath))
    with open(filePath, "w") as f:
        f.write(content)


def FormatCode(fileNames):
    """
    Run clang-format over input files, formatting in-place.

    Args:
        fileNames (list): input files to automatically format.
    """
    pythonFiles = [
        fileName for fileName in fileNames if GetFileExt(fileName) == PY_SOURCE_EXT
    ]
    if pythonFiles:
        RunCommand("black " + " ".join(pythonFiles))

    cppFiles = [
        fileName
        for fileName in fileNames
        if GetFileExt(fileName) in (CPP_SOURCE_EXT, CPP_HEADER_EXT)
    ]
    if cppFiles:
        RunCommand("clang-format -i " + " ".join(cppFiles))


def GetTemplateFile(templateName):
    """
    Args:
        templateName (str): name of the template file.

    Returns:
        str: full path to the codegen template.
    """
    return os.path.abspath(os.path.join(TEMPLATE_DIR, templateName))


def RenderTemplate(templatePath, **kwargs):
    """
    Render a jinja2 template with a contextual information.

    Args:
        templatePath (str): path to the template file to perform substitution.

    Returns:
        str: file name of generated source file.
    """
    fileExt = GetFileExt(templatePath)
    if fileExt in (CPP_SOURCE_EXT, CPP_HEADER_EXT):
        commentPrefix = "//"
    elif fileExt == PY_SOURCE_EXT:
        commentPrefix = "#"
    else:
        raise ValueError("Unknown codegen template suffix: %s".format(fileExt))

    with open(templatePath, "r") as f:
        templateStr = f.read()
        templateStr = os.linesep.join(
            [
                commentPrefix,
                commentPrefix
                + " This file is auto-generated, please do not modify directly!",
                commentPrefix,
                "",
            ]
            + templateStr.split(os.linesep)
        )
        template = JINJA2_ENVIRONMENT.from_string(templateStr)
        code = template.render(math=math, min=min, max=max, abs=abs, **kwargs)
        return code


def GenerateCode(relTemplatePath, outputPath, **kwargs):
    """
    Generate code by rendering the specified jinja2 template at ``relTemplatePath``, passing in ``kwargs``,
    and saving the results onto disk at ``outputPath``.

    Returns:
        str: the file path to the generated code on disk.
    """
    code = RenderTemplate(GetTemplateFile(relTemplatePath), **kwargs)
    outputAbsPath = os.path.abspath(outputPath)
    WriteFile(outputAbsPath, code)
    return outputAbsPath
