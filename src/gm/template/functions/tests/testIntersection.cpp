#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    // Overlaps.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -2, 2 ) -}},
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -3, -1 ) -}}
    ) == {{- typeUtils.GenRange( interface.ArgType("lhs"), -2, -1 ) -}} );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -2, 2 ) -}},
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -1, 1 ) -}}
    ) == {{- typeUtils.GenRange( interface.ArgType("lhs"), -1, 1 ) -}} );

    // Empty.
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -2, 2 ) -}},
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -5, -3 ) -}}
    ).IsEmpty() );
    CHECK( gm::{{ function.name }}(
        {{- typeUtils.GenRange( interface.ArgType("lhs"), -2, 2 ) -}},
        {{- typeUtils.GenRange( interface.ArgType("lhs"), 1, -1 ) -}}
    ).IsEmpty() );
}
{% endfor %}
