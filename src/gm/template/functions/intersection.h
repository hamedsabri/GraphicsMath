{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Range intersection.
///
/// Computes the intersection, or overlap, of two input ranges.
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
/// Compute the intersecting {{ category }} of \p {{ lhs }} and \p {{ rhs }}.
///
/// \param {{ lhs }} The first {{ category }}.
/// \param {{ rhs }} The second {{ category }}.
///
/// \return The {{ category }} intersection.  An empty {{ category }} will be returned if there is no overlap.
/// \sa \ref {{ interface.ArgClass("lhs") }}::IsEmpty()
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.returnType.className }}(
        Max( {{ lhs }}.Min(), {{ rhs }}.Min() ),
        Min( {{ lhs }}.Max(), {{ rhs }}.Max() )
    );
}
{% endfor %}
{% endblock %}
