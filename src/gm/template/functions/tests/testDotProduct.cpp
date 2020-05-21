#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for vectorType in function.types %}
TEST_CASE( "{{ function.name }}_{{ vectorType.className }}" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.GetCppNumber(index) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.GetCppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ vectorType.variablePrefix }}A, {{ vectorType.variablePrefix }}B )
{% if vectorType.elementSize == 2 -%}
           == {{ vectorType.GetCppNumber(5) }}
{% elif vectorType.elementSize == 3 -%}
           == {{ vectorType.GetCppNumber(25) }}
{% elif vectorType.elementSize == 4 -%}
           == {{ vectorType.GetCppNumber(70) }}
{%- endif -%}
    );
}
{% endfor %}
