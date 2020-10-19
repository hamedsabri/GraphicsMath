![Build and test](https://github.com/moddyz/GraphicsMath/workflows/Build%20and%20test/badge.svg)

# GraphicsMath

**GraphicsMath** is a C++ header-only computer graphics math library. 

Optional features include:
- Python bindings.
- Usage in CUDA device code.

## Table of Contents

- [Dependencies](#dependencies)
- [Building](#building)
- [Documentation](#documentation)

### Dependencies

The following dependencies are mandatory:
- C++ compiler
- [CMake](https://cmake.org/documentation/) (3.12 or greater)

The following dependencies are optional:
- [Python](https://www.python.org/) for python bindings.
- [Doxygen](https://www.doxygen.nl/index.html) and [graphiviz](https://graphviz.org/) for documentation.

## Building

Example snippet for building this project:
```
mkdir build && cd build
cmake -DBUILD_TESTING=ON -DCMAKE_INSTALL_PREFIX="/apps/GraphicsMath/" ..
cmake --build  . -- VERBOSE=1 -j8 all test install
```
CMake options for configuring this project:

| CMake Variable name     | Description                                                            | Default |
| ----------------------- | ---------------------------------------------------------------------- | ------- |
| `BUILD_TESTING`         | Build tests.                                                           | `OFF`   |
| `BUILD_DOCUMENTATION`   | Build documentation.                                                   | `OFF`   |
| `BUILD_PYTHON_BINDINGS` | Build python bindings.                                                 | `OFF`   |
| `BUILD_BENCHMARKING`    | Build performance benchmarking tests.                                  | `OFF`   |

## Documentation

Doxygen documentation based on the latest state of master, [hosted by GitHub Pages](https://moddyz.github.io/GraphicsMath/).
