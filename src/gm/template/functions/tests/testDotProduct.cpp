#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgType("lhs").varName }}A(
{% for index in range(interface.Arg("lhs").type.elementSize) -%}
    {{ interface.Arg("lhs").type.CppValue(index) }}
{%- if index + 1 < interface.Arg("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgType("lhs").varName }}B(
{% for index in range(interface.Arg("lhs").type.elementSize) -%}
    {{ interface.Arg("lhs").type.CppValue(index * 5) }}
{%- if index + 1 < interface.Arg("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.ArgType("lhs").varName }}A, {{ interface.ArgType("lhs").varName }}B )
{% if interface.Arg("lhs").type.elementSize == 2 -%}
           == {{ interface.Arg("lhs").type.CppValue(5) }}
{% elif interface.Arg("lhs").type.elementSize == 3 -%}
           == {{ interface.Arg("lhs").type.CppValue(25) }}
{% elif interface.Arg("lhs").type.elementSize == 4 -%}
           == {{ interface.Arg("lhs").type.CppValue(70) }}
{%- endif -%}
    );
}
{% endfor %}
