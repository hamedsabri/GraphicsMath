# GraphicsMath {#mainpage}

\section GM_Introduction Introduction

GraphicsMath is a C++ header-only computer graphics math library.

Instead of using C++ templates, the source code of types, functions and their respective tests 
are generated from jinja2 template files.  This is an effort to improve compilation times and code readability, 
at cost of extra source code and a discrete code-gen step.

\section GM_CodeOrganization Code organization

The headers are organized in three main categories:
- \p gm/base - common utilities and definitions.
- \p gm/types - computer graphics value types (vectors, arrays)
- \p gm/functions - functionality which operate on \p gm types.

Tests reside under each category sub-directory.

\section GM_CodeGeneration Code generation

The executable python script located at \p src/gm/generateCode.py can be run to generate and update source code.

Some common code generation logic are located under \p src/gm/codeGen/.

The jinja2 templates are located under \p src/gm/template.

\section GM_Motivation Motivation

<em>Why another math library?</em>  

This is a personal project to internalize math concepts and explore data and compute optimization techniques.
