# GraphicsMath {#mainpage}

\section GM_Introduction Introduction

GraphicsMath is a C++ header-only computer graphics math library.  It has optional python bindings, and support for usage in CUDA device code.

Instead of using C++ templates, the source code of types, functions and their respective tests 
are generated from jinja2 template files.  This is an effort to improve compilation times and code readability, 
at cost of extra source code and a discrete code-gen step.

\section GM_Building Building

A convenience build script is provided at the root of the repository for building all targets, and optionally installing to a location: `./build.sh <OPTIONAL_INSTALL_LOCATION>`.

\subsection GM_Building_PythonBindings Building Python Bindings

To build python bindings for GraphicsMath, set the cmake option `BUILD_PYTHON_BINDINGS="ON"` when configuring cmake.

\subsection GM_Building_CUDADeviceCode Including in CUDA Device Code

To include and utilize GraphicsMath types and functions in CUDA device code, set the pre-processor definition `GM_CUDA_SUPPORT`.

\section GM_DeveloperNotes Developer Notes

\subsection GM_DeveloperNotes_SourceTree Source Tree

The C++ headers are organized into the three categories:
- \p src/gm/base - common utilities and definitions.
- \p src/gm/types - computer graphics value types (vectors, arrays).
- \p src/gm/functions - functionality which operate on \p gm types.

Python bindings for \p types and \p functions are available under \p src/gm/python.

Tests and benchmark code reside within the sub-directories.

\subsection GM_DeveloperNotes_CodeGeneration Code Generation

The executable python script located at \p src/gm/genCode.py can be run to generate and update source code.  Coe-formatters \p clang-format and \p black need to be available in the codegen environment.

Some common code generation logic are located under \p src/gm/codeGen/.

The jinja2 templates are located under \p src/gm/template.

\subsection GM_DeveloperNotes_Motivation Motivation

<em>Why another math library?</em>  

This is a personal project to internalize math concepts and explore data and compute optimization techniques.

\section GM_GitHubHosted GitHub Repository

The GraphicsMath project is hosted on GitHub: https://github.com/moddyz/GraphicsMath.

