#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set vectorType            = interface.ArgType("normal") %}
{% set vectorClass           = interface.ArgClass("normal") %}
{% set namespacedVectorClass = vectorType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ vectorClass }}" )
{
    {{ namespacedVectorClass }} normal = {{ typeUtils.GenArithmeticSequence(vectorType, 1) }};
    CHECK( gm::{{ function.name }}( normal, {{ typeUtils.GenUniformSequence(vectorType, 2) }} ) == normal );
    CHECK( gm::{{ function.name }}( normal, {{ typeUtils.GenUniformSequence(vectorType, -2) }} ) == -normal );
}
{% endfor %}
