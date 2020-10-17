cmake_minimum_required(VERSION 3.17)

# Project Name
project(
    GraphicsMath
    VERSION 0.0
    DESCRIPTION "Header-only computer graphics math library."
    LANGUAGES CXX
)

# Set module search paths.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/tools)
# Apply options.
include(Options)

# Tools
include(Tools)

# Apply project defaults.
include(Defaults)

# Build source tree.
add_subdirectory(thirdparty)
add_subdirectory(src)
