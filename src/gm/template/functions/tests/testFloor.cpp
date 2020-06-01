#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value") }}" )
{
{%- if interface.Arg("value").type.isScalar -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }} =
        {{ interface.Arg("value").type.CppNumber(2.333) }};
{%- elif interface.Arg("value").type.isVector -%}
    gm::{{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}(
{% for index in range(interface.Arg("value").type.elementSize) -%}
    {{ interface.Arg("value").type.CppNumber(index * 2.333) }}
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Arg("value").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}Floored =
        gm::{{ function.name }}( {{ interface.ArgType("value").varName }} );

{%- if interface.Arg("value").type.isScalar -%}
    CHECK( {{ interface.ArgType("value").varName }}Floored
           == Approx( {{ interface.Arg("value").type.CppNumber( math.floor(2.333) ) }} ));
{%- elif interface.Arg("value").type.isVector -%}
{% for index in range(interface.Arg("value").type.elementSize) -%}
    CHECK( {{ interface.ArgType("value").varName }}Floored[ {{ index }} ]
           == Approx( {{ interface.Arg("value").type.CppNumber( math.floor(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
