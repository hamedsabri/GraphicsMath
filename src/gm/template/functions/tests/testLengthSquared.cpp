#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("vector") }}" )
{
    gm::{{ interface.ArgClass("vector") }} {{ interface.ArgType("vector").varName }}(
{% for index in range(interface.Arg("vector").type.elementSize) -%}
    {{ interface.Arg("vector").type.CppNumber(index * 2) }}
{%- if index + 1 < interface.Arg("vector").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.ArgType("vector").varName }} )
{% if interface.Arg("vector").type.elementSize == 2 -%}
           == {{ interface.Arg("vector").type.CppNumber(4) }}
{% elif interface.Arg("vector").type.elementSize == 3 -%}
           == {{ interface.Arg("vector").type.CppNumber(20) }}
{% elif interface.Arg("vector").type.elementSize == 4 -%}
           == {{ interface.Arg("vector").type.CppNumber(56) }}
{%- endif -%}
    );
}
{% endfor %}
