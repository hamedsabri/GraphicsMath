#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("valueA") }}" )
{
{%- if interface.Arg("valueA").type.isScalar -%}
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}A =
        {{ interface.Arg("valueA").type.CppValue(2.333) }};
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}B =
        {{ interface.Arg("valueA").type.CppValue(1.333) }};
{%- elif interface.Arg("valueA").type.isVector -%}
    gm::{{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}A(
{% for index in range(interface.Arg("valueA").type.elementSize) -%}
    {{ interface.Arg("valueA").type.CppValue(index * 2.333) }}
{%- if index + 1 < interface.Arg("valueA").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ArgClass("valueB") }} {{ interface.ArgType("valueB").varName }}B(
{% for index in range(interface.Arg("valueB").type.elementSize) -%}
    {{ interface.Arg("valueB").type.CppValue(index * 1.333) }}
{%- if index + 1 < interface.Arg("valueB").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Arg("valueA").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}Min =
        gm::{{ function.name }}( {{ interface.ArgType("valueA").varName }}A, {{ interface.ArgType("valueB").varName }}B );

{%- if interface.Arg("valueA").type.isScalar -%}
    CHECK( {{ interface.ArgType("valueA").varName }}Min
           == Approx( {{ interface.Arg("valueA").type.CppValue( min(2.333, 1.333) ) }} ));
{%- elif interface.Arg("valueA").type.isVector -%}
{% for index in range(interface.Arg("valueA").type.elementSize) -%}
    CHECK( {{ interface.ArgType("valueA").varName }}Min[ {{ index }} ]
           == Approx( {{ interface.Arg("valueA").type.CppValue( min(index * 2.333, index * 1.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
