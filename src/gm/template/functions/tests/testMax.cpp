#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("valueA") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("valueA") }}" )
{
    {{ namespacedValueClass }} valueA = {{ typeUtils.GenArithmeticSequence(valueType, 1.333) }};
    {{ namespacedValueClass }} valueB = {{ typeUtils.GenArithmeticSequence(valueType, 2.333) }};
    CHECK( gm::{{ function.name }}( valueA, valueB ) ==
           {{ typeUtils.GenArithmeticSequence(valueType, 2.333) }} );
}
{% endfor %}
