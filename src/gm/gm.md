# GraphicsMath {#mainpage}

\section GM_Introduction Introduction

GraphicsMath is a C++ header-only computer graphics math library, with optional python bindings.

Instead of using C++ templates, the source code of types, functions and their respective tests 
are generated from jinja2 template files.  This is an effort to improve compilation times and code readability, 
at cost of extra source code and a discrete code-gen step.

\section GM_CodeOrganization Code organization

The C++ headers are organized into the three categories:
- \p src/gm/base - common utilities and definitions.
- \p src/gm/types - computer graphics value types (vectors, arrays).
- \p src/gm/functions - functionality which operate on \p gm types.

Python bindings for \p types and \p functions are available under \p src/gm/python.

Tests reside within the sub-directories.

\section GM_CodeGeneration Code generation

The executable python script located at \p src/gm/genCode.py can be run to generate and update source code.  Coe-formatters \p clang-format and \p black need to be available in the codegen environment.

Some common code generation logic are located under \p src/gm/codeGen/.

The jinja2 templates are located under \p src/gm/template.

\section GM_Motivation Motivation

<em>Why another math library?</em>  

This is a personal project to internalize math concepts and explore data and compute optimization techniques.
