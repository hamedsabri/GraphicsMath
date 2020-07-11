{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Range intersection.
///
/// Computes the intersection, or overlapping range from two input ranges.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/min.h>
#include <gm/functions/max.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Compute the intersecting range of \p {{ interface.ArgName("lhs") }} and \p {{ interface.ArgName("rhs") }}.
///
/// \param i_range The range to compare against.
///
/// \return The intersecting range.  An empty range will be returned if there is no overlap.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.returnType.className }}(
        Max( {{ interface.ArgName("lhs") }}.Min(), {{ interface.ArgName("rhs") }}.Min() ),
        Min( {{ interface.ArgName("lhs") }}.Max(), {{ interface.ArgName("rhs") }}.Max() )
    );
}
{% endfor %}
{% endblock %}
