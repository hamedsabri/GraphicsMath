file(GLOB CPPFILES *.cpp types/*.cpp)
cpp_python_module(gm
    TYPE
        SHARED
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)

add_subdirectory(types)
