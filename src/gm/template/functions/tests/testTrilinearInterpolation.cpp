#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("value000") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value000") }}" )
{
    {{ namespacedValueClass }} value000 = {{ typeUtils.GenUniformSequence(valueType, 0) }};
    {{ namespacedValueClass }} value001 = {{ typeUtils.GenUniformSequence(valueType, 2) }};
    {{ namespacedValueClass }} value010 = {{ typeUtils.GenUniformSequence(valueType, 3) }};
    {{ namespacedValueClass }} value011 = {{ typeUtils.GenUniformSequence(valueType, 5) }};

    {{ namespacedValueClass }} value100 = {{ typeUtils.GenUniformSequence(valueType, 1) }};
    {{ namespacedValueClass }} value101 = {{ typeUtils.GenUniformSequence(valueType, 3) }};
    {{ namespacedValueClass }} value110 = {{ typeUtils.GenUniformSequence(valueType, 4) }};
    {{ namespacedValueClass }} value111 = {{ typeUtils.GenUniformSequence(valueType, 6) }};

    {{ namespacedValueClass }} result = gm::{{ function.name }}(
        value000,
        value001,
        value010,
        value011,
        value100,
        value101,
        value110,
        value111,
        /* weightX */ 0.5,
        /* weightY */ 0.5,
        /* weightZ */ 0.5
    );

    CHECK( result == {{ typeUtils.GenUniformSequence(valueType, 3) }} );
}
{% endfor %}
