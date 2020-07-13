{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Find the absolute value of two input values, defined as the magnitude of a real number without its sign.
///
/// If the value type is a vector, the absolute value will be performed on each element.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <algorithm>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set value = interface.ArgName("value") %}
{% set valueType = interface.ArgType("value") %}
/// Find the absolute value of the input \p {{ value }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The absolute value of the input.
{{- functionUtils.signature(function, interface) -}}
{
{% if valueType.isScalar -%}
    return std::abs( {{ value }} );
{%- elif valueType.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(valueType.elementSize) %}
        std::abs( {{ value }}[ {{ index }} ] )
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
