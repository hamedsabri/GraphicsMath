#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("value00") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value00") }}" )
{
    {{ namespacedValueClass }} value00 = {{ typeUtils.GenUniformValue(valueType, 0) }};
    {{ namespacedValueClass }} value01 = {{ typeUtils.GenUniformValue(valueType, 2) }};
    {{ namespacedValueClass }} value10 = {{ typeUtils.GenUniformValue(valueType, 3) }};
    {{ namespacedValueClass }} value11 = {{ typeUtils.GenUniformValue(valueType, 5) }};

    {{ namespacedValueClass }} result = gm::{{ function.name }}(
        value00,
        value01,
        value10,
        value11,
        /* weightX */ 0.5,
        /* weightY */ 0.5
    );

    CHECK( result == {{ typeUtils.GenUniformValue(valueType, 2.5) }} );
}
{% endfor %}
