{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Find the minimum of two input values.
/// If the value type is a vector, the maximum will be computed per-element.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <algorithm>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set valueA = interface.ArgName("valueA") %}
{% set valueB = interface.ArgName("valueB") %}
/// Find the maximum from the inputs \p {{ valueA }} and \p {{ valueB }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ valueA }} The first value to compare.
/// \param {{ valueB }} The second value to compare.
///
/// \return The maximum of the two inputs.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("valueA").type.isScalar -%}
    return std::max( {{ valueA }}, {{ valueB }} );
{%- elif interface.Arg("valueA").type.isVector -%}
    return {{ interface.ArgClass("valueA") }}(
{%- for index in range(interface.Arg("valueA").type.elementSize) %}
        std::max( {{ valueA }}[ {{ index }} ], {{ valueB }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("valueA").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
