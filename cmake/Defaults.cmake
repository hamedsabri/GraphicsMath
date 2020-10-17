# Project defaults.

if(BUILD_TESTING OR BUILD_BENCHMARKING)
    enable_testing()
    list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
endif()

if(BUILD_DOCUMENTATION)
    doxygen_documentation(docs
        GENERATE_TAGFILE
            TRUE
        DOXYFILE
            ${PROJECT_SOURCE_DIR}/src/gm/Doxyfile.in
        INPUTS
            ${PROJECT_SOURCE_DIR}/src/gm
            ${PROJECT_SOURCE_DIR}/src/gm/base
            ${PROJECT_SOURCE_DIR}/src/gm/types
            ${PROJECT_SOURCE_DIR}/src/gm/functions
        DEPENDENCIES
            gm
    )
endif()

if(BUILD_PYTHON_BINDINGS)
    find_package(Python COMPONENTS Development Interpreter)
    message(STATUS "Found python executable: ${Python_EXECUTABLE}")
endif()
