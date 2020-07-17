#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("corner00") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("corner00") }}" )
{
    {{ namespacedValueClass }} corner00 = {{ typeUtils.GenUniformSequence(valueType, 0) }};
    {{ namespacedValueClass }} corner10 = {{ typeUtils.GenUniformSequence(valueType, 2) }};
    {{ namespacedValueClass }} corner01 = {{ typeUtils.GenUniformSequence(valueType, 3) }};
    {{ namespacedValueClass }} corner11 = {{ typeUtils.GenUniformSequence(valueType, 5) }};

    {{ namespacedValueClass }} result = gm::{{ function.name }}(
        corner00,
        corner10,
        corner01,
        corner11,
        gm::Vec2f( 0.5, 0.5 )
    );

    CHECK( result == {{ typeUtils.GenUniformSequence(valueType, 2.5) }} );
}
{% endfor %}
