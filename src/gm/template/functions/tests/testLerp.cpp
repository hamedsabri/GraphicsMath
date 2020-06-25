#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("valueA") }}" )
{
{%- if interface.Arg("valueA").type.isScalar -%}
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}A =
        {{ interface.Arg("valueA").type.CppValue(3) }};
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}B =
        {{ interface.Arg("valueA").type.CppValue(1) }};
{%- elif interface.Arg("valueA").type.isVector -%}
    gm::{{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}A(
{% for index in range(interface.Arg("valueA").type.elementSize) -%}
    {{ interface.Arg("valueA").type.CppValue(index * 2) }}
{%- if index + 1 < interface.Arg("valueA").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ interface.ArgClass("valueB") }} {{ interface.ArgType("valueB").varName }}B(
{% for index in range(interface.Arg("valueB").type.elementSize) -%}
    {{ interface.Arg("valueB").type.CppValue(index * 4) }}
{%- if index + 1 < interface.Arg("valueB").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Arg("valueA").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("valueA") }} {{ interface.ArgType("valueA").varName }}Lerp =
        gm::{{ function.name }}(
            {{ interface.ArgType("valueA").varName }}A,
            {{ interface.ArgType("valueB").varName }}B,
            {{ interface.ArgType("valueB").CppValue(0.5) }}
        );

{%- if interface.Arg("valueA").type.isScalar -%}
    CHECK( {{ interface.ArgType("valueA").varName }}Lerp
           == Approx( {{ interface.Arg("valueA").type.CppValue(2) }} ));
{%- elif interface.Arg("valueA").type.isVector -%}
{% for index in range(interface.Arg("valueA").type.elementSize) -%}
    CHECK( {{ interface.ArgType("valueA").varName }}Lerp[ {{ index }} ]
           == Approx( {{ interface.Arg("valueA").type.CppValue( index * 3 ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
