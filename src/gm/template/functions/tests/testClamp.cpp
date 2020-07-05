#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% macro testCase(inputScalar, expectedScalar, testCaseName) %}
{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("value") }}_{{ testCaseName }}" )
{
{%- if interface.Arg("value").type.isScalar -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }} =
        {{ interface.ArgType("value").CppValue(inputScalar) }};
{%- else -%}
    gm::{{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}(
{% for index in range(interface.Arg("value").type.elementSize) -%}
    {{ interface.Arg("value").type.CppValue(inputScalar) }}
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif -%}
    gm::{{ interface.ArgClass("range") }} {{ interface.ArgType("range").varName }}(
        {{ interface.ArgType("range").CppValue(-10) }},
        {{ interface.ArgType("range").CppValue(10) }}
    );
{%- if not interface.Arg("value").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}Clamped = gm::{{ function.name }}(
        {{ interface.ArgType("value").varName }},
        {{ interface.ArgType("range").varName }}
    );
{%- if interface.Arg("value").type.isScalar -%}
    {{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}Expected =
        {{ interface.ArgType("value").CppValue(expectedScalar) }};
{%- else -%}
    gm::{{ interface.ArgClass("value") }} {{ interface.ArgType("value").varName }}Expected(
{% for index in range(interface.Arg("value").type.elementSize) -%}
    {{ interface.Arg("value").type.CppValue(expectedScalar) }}
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif -%}
    CHECK( {{ interface.ArgType("value").varName }}Clamped == {{ interface.ArgType("value").varName }}Expected );
}
{% endfor %}
{% endmacro %}

{{ testCase(-15, -10, "lessThanMin") }}
{{ testCase(15, 10, "greaterThanMax") }}
{{ testCase(5, 5, "withinRange") }}
