#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

// This test is auto-generated! Please do not modify directly

{% for vectorType in function.types %}
TEST_CASE( "{{ function.name }}_{{ vectorType.className }}" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.GetCppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::LengthSquared( {{ vectorType.variablePrefix }} )
{% if vectorType.elementSize == 2 -%}
           == {{ vectorType.GetCppNumber(4) }}
{% elif vectorType.elementSize == 3 -%}
           == {{ vectorType.GetCppNumber(20) }}
{% elif vectorType.elementSize == 4 -%}
           == {{ vectorType.GetCppNumber(56) }}
{%- endif -%}
    );
}
{% endfor %}
