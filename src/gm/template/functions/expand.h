{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Range expansion.
///
/// The expanded range encompasses both input ranges.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/min.h>
#include <gm/functions/max.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set category = interface.ArgType("lhs").CATEGORY %}
{% set lhs = interface.ArgName("lhs") %}
{% set rhs = interface.ArgName("rhs") %}
/// Compute the expanded {{ category }} of \p {{ lhs }} and \p {{ rhs }}.
///
/// \param {{ lhs }} The first {{ category }}.
/// \param {{ rhs }} The second {{ category }}.
///
/// \return The expanded {{ category }}.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.returnType.className }}(
        Min( {{ lhs }}.Min(), {{ rhs }}.Min() ),
        Max( {{ lhs }}.Max(), {{ rhs }}.Max() )
    );
}
{% endfor %}
{% endblock %}
