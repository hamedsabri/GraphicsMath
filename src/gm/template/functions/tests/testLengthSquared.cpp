#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ParamCls("vector") }}" )
{
    gm::{{ interface.ParamCls("vector") }} {{ interface.ParamVar("vector") }}(
{% for index in range(interface.Param("vector").type.elementSize) -%}
    {{ interface.Param("vector").type.CppNumber(index * 2) }}
{%- if index + 1 < interface.Param("vector").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.ParamVar("vector") }} )
{% if interface.Param("vector").type.elementSize == 2 -%}
           == {{ interface.Param("vector").type.CppNumber(4) }}
{% elif interface.Param("vector").type.elementSize == 3 -%}
           == {{ interface.Param("vector").type.CppNumber(20) }}
{% elif interface.Param("vector").type.elementSize == 4 -%}
           == {{ interface.Param("vector").type.CppNumber(56) }}
{%- endif -%}
    );
}
{% endfor %}
