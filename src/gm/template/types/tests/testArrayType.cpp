#include <catch2/catch.hpp>

#include <gm/types/{{ arrayType.headerFileName }}>

TEST_CASE( "{{ arrayType.className }}_DefaultConstructor" )
{
    gm::{{ arrayType.className }} {{ arrayType.varName }};
    CHECK( {{ arrayType.varName }}.size() == 0 );
}
