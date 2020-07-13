#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
{% set value = interface.ArgName("value") %}
{% set valueType = interface.ArgType("value") %}
{% set valueClass = interface.ArgClass("value") %}
TEST_CASE( "{{ function.name }}_{{ valueClass }}" )
{
{%- if valueType.isScalar -%}
    {{ valueClass }} {{ valueType.varName }} =
        -{{ valueType.CppValue(2.333) }};
{%- elif valueType.isVector -%}
    gm::{{ valueClass }} {{ valueType.varName }}(
{% for index in range(valueType.elementSize) -%}
{%- if index % 2 == 1 -%}
        -
{%- endif -%}
    {{ valueType.CppValue(index * 2.333) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not valueType.isScalar -%}
    gm::
{%- endif -%}
    {{ valueClass }} {{ valueType.varName }}Abs =
        gm::{{ function.name }}( {{ valueType.varName }} );

{%- if valueType.isScalar -%}
    CHECK( {{ valueType.varName }}Abs
           == Approx( {{ valueType.CppValue( abs(2.333) ) }} ));
{%- elif valueType.isVector -%}
{% for index in range(valueType.elementSize) -%}
    CHECK( {{ valueType.varName }}Abs[ {{ index }} ]
           == Approx( {{ valueType.CppValue( abs(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
