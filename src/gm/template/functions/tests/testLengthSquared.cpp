#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for vectorType in function.types %}
TEST_CASE( "{{ function.name }}_{{ vectorType.className }}" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ vectorType.variablePrefix }} )
{% if vectorType.elementSize == 2 -%}
           == {{ vectorType.CppNumber(4) }}
{% elif vectorType.elementSize == 3 -%}
           == {{ vectorType.CppNumber(20) }}
{% elif vectorType.elementSize == 4 -%}
           == {{ vectorType.CppNumber(56) }}
{%- endif -%}
    );
}
{% endfor %}
