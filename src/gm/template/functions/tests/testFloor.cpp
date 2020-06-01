#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.Param("value").type.className }}" )
{
{%- if interface.Param("value").type.isScalar -%}
    {{ interface.Param("value").type.className }} {{ interface.Param("value").type.variablePrefix }} =
        {{ interface.Param("value").type.CppNumber(2.333) }};
{%- elif interface.Param("value").type.isVector -%}
    gm::{{ interface.Param("value").type.className }} {{ interface.Param("value").type.variablePrefix }}(
{% for index in range(interface.Param("value").type.elementSize) -%}
    {{ interface.Param("value").type.CppNumber(index * 2.333) }}
{%- if index + 1 < interface.Param("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Param("value").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.Param("value").type.className }} {{ interface.Param("value").type.variablePrefix }}Floored =
        gm::{{ function.name }}( {{ interface.Param("value").type.variablePrefix }} );

{%- if interface.Param("value").type.isScalar -%}
    CHECK( {{ interface.Param("value").type.variablePrefix }}Floored
           == Approx( {{ interface.Param("value").type.CppNumber( math.floor(2.333) ) }} ));
{%- elif interface.Param("value").type.isVector -%}
{% for index in range(interface.Param("value").type.elementSize) -%}
    CHECK( {{ interface.Param("value").type.variablePrefix }}Floored[ {{ index }} ]
           == Approx( {{ interface.Param("value").type.CppNumber( math.floor(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
