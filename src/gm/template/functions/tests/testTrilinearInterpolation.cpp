#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set valueType            = interface.ArgType("corner000") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("corner000") }}" )
{
    {{ namespacedValueClass }} corner000 = {{ typeUtils.GenUniformSequence(valueType, 0) }};
    {{ namespacedValueClass }} corner100 = {{ typeUtils.GenUniformSequence(valueType, 2) }};
    {{ namespacedValueClass }} corner010 = {{ typeUtils.GenUniformSequence(valueType, 3) }};
    {{ namespacedValueClass }} corner110 = {{ typeUtils.GenUniformSequence(valueType, 5) }};

    {{ namespacedValueClass }} corner001 = {{ typeUtils.GenUniformSequence(valueType, 1) }};
    {{ namespacedValueClass }} corner101 = {{ typeUtils.GenUniformSequence(valueType, 3) }};
    {{ namespacedValueClass }} corner011 = {{ typeUtils.GenUniformSequence(valueType, 4) }};
    {{ namespacedValueClass }} corner111 = {{ typeUtils.GenUniformSequence(valueType, 6) }};

    {{ namespacedValueClass }} result = gm::{{ function.name }}(
        corner000,
        corner100,
        corner010,
        corner110,
        corner001,
        corner101,
        corner011,
        corner111,
        gm::Vec3f( 0.5, 0.5, 0.5 )
    );

    CHECK( result == {{ typeUtils.GenUniformSequence(valueType, 3) }} );
}
{% endfor %}
