#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("sourceValue") }}" )
{
{%- if interface.Arg("sourceValue").type.isScalar -%}
    {{ interface.ArgClass("sourceValue") }} {{ interface.ArgType("sourceValue").varName }} =
        {{ interface.Arg("sourceValue").type.CppValue(0.5) }};
{%- elif interface.Arg("sourceValue").type.isVector -%}
    gm::{{ interface.ArgClass("sourceValue") }} {{ interface.ArgType("sourceValue").varName }}(
{% for index in range(interface.Arg("sourceValue").type.elementSize) -%}
    {{ interface.Arg("sourceValue").type.CppValue(index * 0.05) }}
{%- if index + 1 < interface.Arg("sourceValue").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif -%}

{%- if not interface.Arg("sourceValue").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("sourceValue") }} {{ interface.ArgType("sourceValue").varName }}Mapped =
        gm::{{ function.name }}(
            {{ interface.ArgType("sourceValue").varName }},
            gm::{{ interface.ArgClass("sourceRange") }}(
                {{ interface.Arg("sourceValue").type.CppValue(-1.0) }},
                {{ interface.Arg("sourceValue").type.CppValue(1.0) }}
            ),
            gm::{{ interface.ArgClass("sourceRange") }}(
                {{ interface.Arg("sourceValue").type.CppValue(0.0) }},
                {{ interface.Arg("sourceValue").type.CppValue(1.0) }}
            )
        );

{%- if interface.Arg("sourceValue").type.isScalar -%}
    CHECK( {{ interface.ArgType("sourceValue").varName }}Mapped
           == Approx( {{ interface.Arg("sourceValue").type.CppValue(0.75) }} ));
{%- elif interface.Arg("sourceValue").type.isVector -%}
{% for index in range(interface.Arg("sourceValue").type.elementSize) -%}
    CHECK( {{ interface.ArgType("sourceValue").varName }}Mapped[ {{ index }} ]
           == Approx( {{ interface.Arg("sourceValue").type.CppValue( (index * 0.05 + 1.0) * 0.5 ) }} ));
{%- endfor %}
{%- endif %}

}
{% endfor %}
