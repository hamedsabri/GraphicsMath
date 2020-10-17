# GraphicsMath {#mainpage}

\section GM_section_introduction Introduction

GraphicsMath is a C++ header-only computer graphics math library.  It has optional python bindings, and support for usage in CUDA device code.

Instead of using C++ templates, the source code of types, functions and their respective tests 
are generated from jinja2 template files.  This is an effort to improve compilation times and code readability, 
at cost of extra source code and a discrete code-gen step.

\section GM_section_usage Library usage

The library is organized into \ref GM_types and \ref GM_functions.

\section GM_section_building Building

See README.md on https://github.com/moddyz/GraphicsMath for build instructions.

\subsection GM_section_developerNotes_sourceTree Source Tree

The C++ headers are organized into the three categories:
- \p src/gm/base - common utilities and definitions.
- \p src/gm/types - computer graphics value types (vectors, arrays).
- \p src/gm/functions - functionality which operate on \p gm types.

Python bindings for \p types and \p functions are available under \p src/gm/python.

Tests and benchmark code reside within the sub-directories.

\subsection GM_section_developerNotes_codeGeneration Code Generation

The executable python script located at \p src/gm/genCode.py can be run to generate and update source code.  Coe-formatters \p clang-format and \p black need to be available in the codegen environment.

Some common code generation logic are located under \p src/gm/codeGen/.

The jinja2 templates are located under \p src/gm/template.

\subsection GM_section_developerNotes_motivation Motivation

<em>Why another math library?</em>  

This is a personal project to internalize math concepts and explore data and compute optimization techniques.

\section GM_section_github GitHub Repository

The GraphicsMath project is hosted on GitHub: https://github.com/moddyz/GraphicsMath.

\defgroup GM_types Types
\brief Value types commonly used in computer graphics.

\defgroup gm_types_vector Vector types
\ingroup GM_types
\brief Fixed length containers of elemental value types.

\defgroup gm_types_range Range types
\ingroup GM_types
\brief Minimum, maximum range of elemental value types.

\defgroup gm_types_composite Composite types
\ingroup GM_types
\brief \em Named element compositions of array, vector, scalar, or other composite value types.

\defgroup GM_functions Functions
\brief Functional operators commonly used in computer graphics.

\defgroup gm_functions_basic Basic math operators
\ingroup GM_functions
\brief Basic math operators such as absolute value, floor, min, max, and angle unit conversion.

\defgroup gm_functions_linearAlgebra Linear algebra operators
\ingroup GM_functions
\brief Linear algebra operators operating on vectors and matrices.

\defgroup gm_functions_rayTracing Ray tracing operators
\ingroup GM_functions
\brief Common operators used in ray tracing, including ray intersection tests.
