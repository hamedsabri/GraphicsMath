# GraphicsMath

**GraphicsMath** is a C++ header-only computer graphics math library. 

Optional features include:
- Python bindings.
- Usage in CUDA device code.

## Table of Contents

- [Documentation](#documentation)
- [Building](#building)
  - [Requirements](#requirements)
- [Build Status](#build-status)

## Documentation

Doxygen documentation based on the latest state of master, [hosted by GitHub Pages](https://moddyz.github.io/GraphicsMath/).

## Building

A convenience build script is provided, for building all targets, and optionally installing to a location:
```
./build.sh <OPTIONAL_INSTALL_LOCATION>
```

### Requirements

- `>= CMake-3.17`
- `>= C++17`
- `doxygen` and `graphviz` (optional for documentation)

## Build Status

|       | master | 
| ----- | ------ | 
| macOS-10.14 | [![Build Status](https://travis-ci.com/moddyz/GraphicsMath.svg?branch=master)](https://travis-ci.com/moddyz/GraphicsMath) |

