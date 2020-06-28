#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("source") }}" )
{
{%- if interface.Arg("source").type.isScalar -%}
    {{ interface.ArgClass("source") }} {{ interface.ArgType("source").varName }}A =
        {{ interface.Arg("source").type.CppValue(3) }};
    {{ interface.ArgClass("source") }} {{ interface.ArgType("source").varName }}B =
        {{ interface.Arg("source").type.CppValue(1) }};
{%- elif interface.Arg("source").type.isVector -%}
    gm::{{ interface.ArgClass("source") }} {{ interface.ArgType("source").varName }}A(
{% for index in range(interface.Arg("source").type.elementSize) -%}
    {{ interface.Arg("source").type.CppValue(index * 2) }}
{%- if index + 1 < interface.Arg("source").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ArgClass("target") }} {{ interface.ArgType("target").varName }}B(
{% for index in range(interface.Arg("target").type.elementSize) -%}
    {{ interface.Arg("target").type.CppValue(index * 4) }}
{%- if index + 1 < interface.Arg("target").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Arg("source").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("source") }} {{ interface.ArgType("source").varName }}Lerp =
        gm::{{ function.name }}(
            {{ interface.ArgType("source").varName }}A,
            {{ interface.ArgType("target").varName }}B,
            {{ interface.ArgType("target").CppValue(0.5) }}
        );

{%- if interface.Arg("source").type.isScalar -%}
    CHECK( {{ interface.ArgType("source").varName }}Lerp
           == Approx( {{ interface.Arg("source").type.CppValue(2) }} ));
{%- elif interface.Arg("source").type.isVector -%}
{% for index in range(interface.Arg("source").type.elementSize) -%}
    CHECK( {{ interface.ArgType("source").varName }}Lerp[ {{ index }} ]
           == Approx( {{ interface.Arg("source").type.CppValue( index * 3 ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
