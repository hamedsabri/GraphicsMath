#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.Param("vector").type.className }}" )
{
    gm::{{ interface.Param("vector").type.className }} {{ interface.Param("vector").type.variablePrefix }}(
{% for index in range(interface.Param("vector").type.elementSize) -%}
    {{ interface.Param("vector").type.CppNumber(index * 2) }}
{%- if index + 1 < interface.Param("vector").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( gm::{{ function.name }}( {{ interface.Param("vector").type.variablePrefix }} )
{% if interface.Param("vector").type.elementSize == 2 -%}
           == Approx( {{ interface.Param("vector").type.CppNumber(math.sqrt(4.0)) }} )
{% elif interface.Param("vector").type.elementSize == 3 -%}
           == Approx( {{ interface.Param("vector").type.CppNumber(math.sqrt(20.0)) }} )
{% elif interface.Param("vector").type.elementSize == 4 -%}
           == Approx( {{ interface.Param("vector").type.CppNumber(math.sqrt(56)) }} )
{%- endif -%}
    );
}
{% endfor %}
