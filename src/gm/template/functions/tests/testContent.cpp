#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set rangeType            = interface.ArgType("range") %}
{% set namespacedValueClass = rangeType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("range") }}" )
{
    {{ namespacedValueClass }} range = {{ typeUtils.GenRange(rangeType, 0, 2) }};
{%- if rangeType.elementType.isVector -%}
    CHECK( gm::{{ function.name }}( range ) == {{ math.pow(2, rangeType.elementType.elementSize ) }} );
{%- elif rangeType.elementType.isScalar -%}
    CHECK( gm::{{ function.name }}( range ) == {{ rangeType.CppValue(2) }} );
{%- endif -%}
}
{% endfor %}
