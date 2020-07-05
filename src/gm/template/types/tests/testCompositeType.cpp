#include <catch2/catch.hpp>

#include <gm/types/{{ valueType.headerFileName }}>

TEST_CASE( "{{ valueType.className }}_DefaultConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
}
