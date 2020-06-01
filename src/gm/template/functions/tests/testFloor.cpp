#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value") }}" )
{
{%- if interface.Arg("value").type.isScalar -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgVariable("value") }} =
        {{ interface.Arg("value").type.CppNumber(2.333) }};
{%- elif interface.Arg("value").type.isVector -%}
    gm::{{ interface.ArgClass("value") }} {{ interface.ArgVariable("value") }}(
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
    {{ interface.ArgClass("value") }} {{ interface.ArgVariable("value") }}Floored =
        gm::{{ function.name }}( {{ interface.ArgVariable("value") }} );

{%- if interface.Arg("value").type.isScalar -%}
    CHECK( {{ interface.ArgVariable("value") }}Floored
           == Approx( {{ interface.Arg("value").type.CppNumber( math.floor(2.333) ) }} ));
{%- elif interface.Arg("value").type.isVector -%}
{% for index in range(interface.Arg("value").type.elementSize) -%}
    CHECK( {{ interface.ArgVariable("value") }}Floored[ {{ index }} ]
           == Approx( {{ interface.Arg("value").type.CppNumber( math.floor(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
