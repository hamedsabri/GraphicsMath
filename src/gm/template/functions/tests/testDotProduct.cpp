#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ParamCls("lhs") }}" )
{
    gm::{{ interface.ParamCls("lhs") }} {{ interface.ParamVar("lhs") }}A(
{% for index in range(interface.Param("lhs").type.elementSize) -%}
    {{ interface.Param("lhs").type.CppNumber(index) }}
{%- if index + 1 < interface.Param("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ParamCls("lhs") }} {{ interface.ParamVar("lhs") }}B(
{% for index in range(interface.Param("lhs").type.elementSize) -%}
    {{ interface.Param("lhs").type.CppNumber(index * 5) }}
{%- if index + 1 < interface.Param("lhs").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.ParamVar("lhs") }}A, {{ interface.ParamVar("lhs") }}B )
{% if interface.Param("lhs").type.elementSize == 2 -%}
           == {{ interface.Param("lhs").type.CppNumber(5) }}
{% elif interface.Param("lhs").type.elementSize == 3 -%}
           == {{ interface.Param("lhs").type.CppNumber(25) }}
{% elif interface.Param("lhs").type.elementSize == 4 -%}
           == {{ interface.Param("lhs").type.CppNumber(70) }}
{%- endif -%}
    );
}
{% endfor %}
