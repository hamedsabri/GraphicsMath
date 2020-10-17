file(GLOB CPPFILES *.cpp)
cpp_test(test_${CATEGORY_NAME}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)
