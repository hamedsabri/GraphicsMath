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
    bool leftEmpty = {{ lhs }}.IsEmpty();
{%- if interface.ArgType("rhs").isRange -%}
    bool rightEmpty = {{ rhs }}.IsEmpty();
    if ( leftEmpty && rightEmpty )
    {
        return {{ interface.returnType.className }}();
    }
    else if ( leftEmpty )
    {
        return {{ rhs }};
    }
    else if ( rightEmpty )
    {
        return {{ lhs }};
    }

    return {{ interface.returnType.className }}(
        Min( {{ lhs }}.Min(), {{ rhs }}.Min() ),
        Max( {{ lhs }}.Max(), {{ rhs }}.Max() )
    );
{%- else -%}
    if ( leftEmpty )
    {
        return {{ interface.returnType.className }}( {{ rhs }}, {{ rhs }} );
    }

    return {{ interface.returnType.className }}(
        Min( {{ lhs }}.Min(), {{ rhs }} ),
        Max( {{ lhs }}.Max(), {{ rhs }} )
    );
{%- endif -%}
}
{% endfor %}
{% endblock %}
