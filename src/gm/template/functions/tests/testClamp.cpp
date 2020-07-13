#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

{% macro testCase(inputScalar, expectedScalar, testCaseName) %}
{% for interface in function.interfaces %}
{% set value                = interface.ArgName("value") %}
{% set valueType            = interface.ArgType("value") %}
{% set valueClass           = interface.ArgClass("value") %}
{% set namespacedValueClass = valueType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ valueClass }}_{{ testCaseName }}" )
{
    {{ namespacedValueClass }} {{ valueType.varName }} = {{ typeUtils.GenUniformValue(valueType, inputScalar) }};
    gm::{{ interface.ArgClass("range") }} {{ interface.ArgType("range").varName }}(
        {{ interface.ArgType("range").CppValue(-10) }},
        {{ interface.ArgType("range").CppValue(10) }}
    );
    {{ namespacedValueClass }} {{ valueType.varName }}Clamped = gm::{{ function.name }}(
        {{ valueType.varName }},
        {{ interface.ArgType("range").varName }}
    );
    {{ namespacedValueClass }} {{ valueType.varName }}Expected =
        {{ typeUtils.GenUniformValue(valueType, expectedScalar) }};
    CHECK( {{ valueType.varName }}Clamped == {{ valueType.varName }}Expected );
}
{% endfor %}
{% endmacro %}

{{ testCase(-15, -10, "lessThanMin") }}
{{ testCase(15, 10, "greaterThanMax") }}
{{ testCase(5, 5, "withinRange") }}
