#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set rangeType = interface.ArgType("lhs") %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    // Expand with non-empty ranges.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 4 ) -}},
        {{- typeUtils.GenRange( rangeType, -3, -1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -3, 4 ) -}} );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, -1, 1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -2, 2 ) -}} );

    // Expand with one empty range.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, -2, 2 ) -}},
        {{- typeUtils.GenRange( rangeType, 1, -1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -2, 2 ) -}} );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, 2, -2 ) -}},
        {{- typeUtils.GenRange( rangeType, -1, 1 ) -}}
    ) == {{- typeUtils.GenRange( rangeType, -1, 1 ) -}} );

    // Expand with two empty ranges.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( rangeType, 2, -2 ) -}},
        {{- typeUtils.GenRange( rangeType, 1, -1 ) -}}
    ).IsEmpty() );
}
{% endfor %}
