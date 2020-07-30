{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Point transformation.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vector     = interface.ArgName("vector") %}
{% set vectorType = interface.ArgType("vector") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Transform a \p {{ vector }} with the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The input matrix to transpose.
///
/// \return Transformed vector.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ vectorType.className }}(
        {{ vector }}.X() * {{ matrix }}( 0, 0 ) + {{ vector }}.Y() * {{ matrix }}( 0, 1 ) +
            {{ vector }}.Z() * {{ matrix }}( 0, 2 ),
        {{ vector }}.X() * {{ matrix }}( 1, 0 ) + {{ vector }}.Y() * {{ matrix }}( 1, 1 ) +
            {{ vector }}.Z() * {{ matrix }}( 1, 2 ),
        {{ vector }}.X() * {{ matrix }}( 2, 0 ) + {{ vector }}.Y() * {{ matrix }}( 2, 1 ) +
            {{ vector }}.Z() * {{ matrix }}( 2, 2 ) );
}
{% endfor %}
{% endblock %}
