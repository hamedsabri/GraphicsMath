#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set rangeType = interface.ArgType("range") %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("range") }}" )
{
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenArithmeticRange( rangeType, 1, 2 ) -}}
    ) == {{ rangeType.elementType.elementSize - 1 }} );
}
{% endfor %}
