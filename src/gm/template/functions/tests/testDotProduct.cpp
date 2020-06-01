#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgVariable("lhs") }}A(
{% for index in range(interface.Arg("lhs").type.elementSize) -%}
    {{ interface.Arg("lhs").type.CppNumber(index) }}
{%- if index + 1 < interface.Arg("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgVariable("lhs") }}B(
{% for index in range(interface.Arg("lhs").type.elementSize) -%}
    {{ interface.Arg("lhs").type.CppNumber(index * 5) }}
{%- if index + 1 < interface.Arg("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.ArgVariable("lhs") }}A, {{ interface.ArgVariable("lhs") }}B )
{% if interface.Arg("lhs").type.elementSize == 2 -%}
           == {{ interface.Arg("lhs").type.CppNumber(5) }}
{% elif interface.Arg("lhs").type.elementSize == 3 -%}
           == {{ interface.Arg("lhs").type.CppNumber(25) }}
{% elif interface.Arg("lhs").type.elementSize == 4 -%}
           == {{ interface.Arg("lhs").type.CppNumber(70) }}
{%- endif -%}
    );
}
{% endfor %}
