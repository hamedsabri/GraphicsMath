{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Content for an N-dimensional range.
///
/// Content is the generalized term for "length" (1D), "area" (2D), or "volume" (3D).
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/min.h>
#include <gm/functions/max.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set category  = interface.ArgType("range").CATEGORY %}
{% set rangeArg  = interface.ArgName("range") %}
{% set rangeType = interface.ArgType("range") %}
/// Compute the content of the {{ category }} \p {{ rangeArg }}.
///
/// \param {{ rangeArg }} The range to compute the content for.
///
/// \return The content quantity.
{{- functionUtils.signature(function, interface) -}}
{
    return
{% if rangeType.elementType.isVector -%}
{%- for index in range(rangeType.elementType.elementSize) -%}
    ( {{ rangeArg }}.Max()[ {{ index }} ] - {{ rangeArg }}.Min()[ {{ index }} ] )
{%- if index + 1 < rangeType.elementType.elementSize -%}
        *
{%- endif -%}
{%- endfor -%}
{%- elif rangeType.elementType.isScalar -%}
    {{ rangeArg }}.Max() - {{ rangeArg }}.Min()
{%- endif -%}
    ;
}
{% endfor %}
{% endblock %}
