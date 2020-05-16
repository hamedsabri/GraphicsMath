file(GLOB CPPFILES *.cpp)
cpp_test_program(test_${CATEGORY_NAME}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        gm
)
