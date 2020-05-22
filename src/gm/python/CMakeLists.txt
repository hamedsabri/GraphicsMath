file(GLOB CPPFILES *.cpp)
cpp_python_module(gm
    TYPE
        SHARED
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
