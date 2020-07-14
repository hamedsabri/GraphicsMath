#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set vectorType            = interface.ArgType("lhs") %}
{% set vectorClass           = interface.ArgClass("lhs") %}
{% set namespacedVectorClass = vectorType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ vectorClass }}" )
{
    {{ namespacedVectorClass }} {{ vectorType.varName }}A = {{ typeUtils.GenArithmeticSeq(vectorType, 1) }};
    {{ namespacedVectorClass }} {{ vectorType.varName }}B = {{ typeUtils.GenArithmeticSeq(vectorType, 5) }};
    CHECK( gm::{{ function.name }}( {{ vectorType.varName }}A, {{ vectorType.varName }}B )
{% if vectorType.elementSize == 2 -%}
           == {{ vectorType.CppValue(5) }}
{% elif vectorType.elementSize == 3 -%}
           == {{ vectorType.CppValue(25) }}
{% elif vectorType.elementSize == 4 -%}
           == {{ vectorType.CppValue(70) }}
{%- endif -%}
    );
}
{% endfor %}
