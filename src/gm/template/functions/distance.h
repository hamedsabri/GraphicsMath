{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Compute the \b distance between two points.
///
/// The \b distance is computed by taking the \em length of the the <em>vector difference</em> between the two points.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/length.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set pointA = interface.ArgName("pointA") %}
{% set pointB = interface.ArgName("pointB") %}
/// Compute the distance of between points \p {{ pointA }} and \p {{ pointB }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The distance between the two points.
{{- functionUtils.signature(function, interface) -}}
{
    return Length( {{ pointA }} - {{ pointB }} );
}
{% endfor %}
{% endblock %}
