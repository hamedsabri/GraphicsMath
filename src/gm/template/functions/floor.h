{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Floor the input value, by rounding downwards, returning the largest integral number less than the input.
/// If the value type is a vector, the floor will be performed element-wise.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <cmath>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set value = interface.ArgName("value") %}
{% set valueType = interface.ArgType("value") %}
/// Floor the input \ref {{ interface.ArgClass("value") }} \p {{ value }} and return it.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ value }} Value to floor.
///
/// \return Floored input value.
{{- functionUtils.signature(function, interface) -}}
{
{% if valueType.isScalar -%}
    return std::floor( {{ value }} );
{%- elif valueType.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(valueType.elementSize) %}
        std::floor( {{ value }}[ {{ index }} ] )
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
