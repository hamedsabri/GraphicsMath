file(GLOB CPPFILES *.cpp)
cpp_test_program(benchmark_${CATEGORY_NAME}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)
