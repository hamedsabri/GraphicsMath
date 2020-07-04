#include <catch2/catch.hpp>

#include <gm/types/{{ rangeType.headerFileName }}>

TEST_CASE( "{{ rangeType.className }}_DefaultConstructor" )
{
    gm::{{ rangeType.className }} {{ rangeType.varName }};
}
