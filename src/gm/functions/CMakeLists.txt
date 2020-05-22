set(CATEGORY_NAME "functions")

file(GLOB HEADERS *.h)
file(
    COPY ${HEADERS}
    DESTINATION ${CMAKE_BINARY_DIR}/include/${LIBRARY_NAME}/${CATEGORY_NAME}
)

install(
    FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${LIBRARY_NAME}/${CATEGORY_NAME}
)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
