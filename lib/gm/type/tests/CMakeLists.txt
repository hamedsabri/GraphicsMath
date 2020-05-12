file(GLOB CPPFILES *.cpp)
foreach( CPPFILE ${CPPFILES} )
    get_filename_component(TEST_PROGRAM ${CPPFILE} NAME_WE)
    gm_test_program(${TEST_PROGRAM}
        CPPFILES
            ${CPPFILE}
        LIBRARIES
            gm_tool
            gm_type
    )
endforeach( CPPFILE )
