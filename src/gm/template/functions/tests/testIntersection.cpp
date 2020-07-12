#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set rangeType = interface.ArgType("lhs") %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    // Overlaps.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, -3, -1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -2, -1 ) -}} );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, -1, 1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -1, 1 ) -}} );

    // Empty.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, -5, -3 ) -}}
    ).IsEmpty() );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, 1, -1 ) -}}
    ).IsEmpty() );
}
{% endfor %}
