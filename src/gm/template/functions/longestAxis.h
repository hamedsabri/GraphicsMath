{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Longest axis of a range.
{%- endblock %}

{% block includes %}
#include <gm/base/diagnostic.h>

{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set rangeType = interface.ArgType("range") %}
{% set rangeArg = interface.ArgName("range") %}
/// Compute the longest axis of a multi-dimensional range.
///
/// \param {{ rangeArg }} The first {{ rangeArg }}.
///
/// \return The longest axis of {{ rangeArg }}.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( !{{ rangeArg }}.IsEmpty() );
    {{ rangeType.elementType.className }} diagonal = {{ rangeArg }}.Max() - {{ rangeArg }}.Min();
    int longestAxis = 0;
    {{ rangeType.elementType.elementType.className }} longestAxisLength = diagonal[ 0 ];
{% for axis in range(1, rangeType.elementType.elementSize) %}
    if ( diagonal[ {{ axis }} ] > longestAxisLength )
    {
{% if axis + 1 < rangeType.elementType.elementSize -%}
        longestAxisLength = diagonal[ {{ axis }} ];
{%- endif %}
        longestAxis = {{ axis }};
    }
{% endfor %}
    return longestAxis;
}
{% endfor %}
{% endblock %}
