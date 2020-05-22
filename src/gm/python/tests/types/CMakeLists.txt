file(GLOB PYTHON_FILES *.py)

foreach(
    PYTHON_FILE
    ${PYTHON_FILES}
)
    get_filename_component(TEST_NAME ${PYTHON_FILE} NAME_WE)
    list(APPEND PYTHON_TESTS ${TEST_NAME})
endforeach()

add_test(
    NAME test_python_types
    COMMAND ${Python_EXECUTABLE} -m unittest ${PYTHON_TESTS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

set_tests_properties(test_python_types
    PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/src/gm/python:$ENV{PYTHONPATH}"
)
