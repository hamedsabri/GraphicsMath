file(GLOB CPPFILES *.cpp)
cpp_test(benchmark_${CATEGORY_NAME}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)
