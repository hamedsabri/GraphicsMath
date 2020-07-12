#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set containerType = interface.ArgType("container") %}
{% set containeeType = interface.ArgType("containee") %}
TEST_CASE( "{{ function.name }}_{{ containerType.className }}_{{ containeeType.className }}" )
{
{% if containeeType.isRange -%}
    gm::{{ containerType.className }} {{ containerType.varName }}(
        /* min */ {{ typeUtils.GenRangeElement( containerType, -2 ) }},
        /* max */ {{ typeUtils.GenRangeElement( containerType, 4 ) }}
    );
    CHECK( gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, -2, 3 ) }} ) );
    CHECK( gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, -1, 2 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, -3, 2 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, -1, 5 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, 7, 10 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRange( containerType, -5, -4 ) }} ) );
{%- else -%}
    gm::{{ containerType.className }} {{ containerType.varName }}(
        /* min */ {{ typeUtils.GenRangeElement( containerType, -2 ) }},
        /* max */ {{ typeUtils.GenRangeElement( containerType, 4 ) }}
    );
    CHECK( gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRangeElement( containerType, -2 ) }} ) );
    CHECK( gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRangeElement( containerType, -0 ) }} ) );
    CHECK( gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRangeElement( containerType, 4 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRangeElement( containerType, -3 ) }} ) );
    CHECK( !gm::Contains( {{ containerType.varName }}, {{ typeUtils.GenRangeElement( containerType, 5 ) }} ) );
{%- endif -%}
}
{% endfor %}
