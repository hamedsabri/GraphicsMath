#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("source") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("source") }}" )
{
    {{ namespacedValueClass }} source = {{ typeUtils.GenArithmeticSequence(valueType, 0) }};
    {{ namespacedValueClass }} target = {{ typeUtils.GenArithmeticSequence(valueType, 5) }};
    {{ namespacedValueClass }} result = gm::{{ function.name }}(
        source,
        target,
        /* weight */ 0.5
    );

    CHECK( result == {{ typeUtils.GenArithmeticSequence(valueType, 2.5) }} );
}
{% endfor %}
