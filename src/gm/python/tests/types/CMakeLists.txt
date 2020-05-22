file(GLOB PYTHON_FILES *.py)

foreach(
    PYTHON_FILE
    ${PYTHON_FILES}
)
    get_filename_component(TEST_SUFFIX ${PYTHON_FILE} NAME_WE)
    set(TEST_NAME "py${TEST_SUFFIX}")
    add_test(
        NAME ${TEST_NAME}
        COMMAND ${Python_EXECUTABLE} -m unittest
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    set_tests_properties(${TEST_NAME}
        PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/src/gm/python:$ENV{PYTHONPATH}"
    )

endforeach()
