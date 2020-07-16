#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("value") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value") }}" )
{
    {{ namespacedValueClass }} value = {{ typeUtils.GenArithmeticSequence(valueType, 1.333) }};
    CHECK( gm::{{ function.name }}( value ) ==
           {{ typeUtils.GenArithmeticSequence(valueType, 1.333, math.floor) }} );
}
{% endfor %}
