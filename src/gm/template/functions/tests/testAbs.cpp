#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value") }}" )
{
{%- if interface.Arg("value").type.isScalar -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }} =
        -{{ interface.Arg("value").type.CppValue(2.333) }};
{%- elif interface.Arg("value").type.isVector -%}
    gm::{{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}(
{% for index in range(interface.Arg("value").type.elementSize) -%}
{%- if index % 2 == 1 -%}
        -
{%- endif -%}
    {{ interface.Arg("value").type.CppValue(index * 2.333) }}
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Arg("value").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}Abs =
        gm::{{ function.name }}( {{ interface.ArgType("value").varName }} );

{%- if interface.Arg("value").type.isScalar -%}
    CHECK( {{ interface.ArgType("value").varName }}Abs
           == Approx( {{ interface.Arg("value").type.CppValue( abs(2.333) ) }} ));
{%- elif interface.Arg("value").type.isVector -%}
{% for index in range(interface.Arg("value").type.elementSize) -%}
    CHECK( {{ interface.ArgType("value").varName }}Abs[ {{ index }} ]
           == Approx( {{ interface.Arg("value").type.CppValue( abs(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
