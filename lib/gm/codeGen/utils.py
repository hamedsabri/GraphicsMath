"""
Common code generation utilities.
"""

import os
import shlex
import subprocess

from jinja2 import Template

# Name of the codegen template directory.
TEMPLATE_DIR = "template"


def RunCommand(command):
    """
    Run the ``command`` by forking a subprocess.
    """
    print("Running command {}".format(command))
    process = subprocess.Popen(shlex.split(command))
    process.wait()


def WriteFile(filePath, content):
    """
    Write a file to disk with ``content`` at the specified ``filePath``.

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
