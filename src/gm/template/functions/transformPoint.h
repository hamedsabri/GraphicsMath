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
{% set point      = interface.ArgName("point") %}
{% set pointType  = interface.ArgType("point") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Transform a \p {{ point }} with the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The input matrix to transpose.
///
/// \return Transformed point.
{{- functionUtils.signature(function, interface) -}}
{
    {{ pointType.className }} transformedPoint(
        {{ point }}.X() * {{ matrix }}( 0, 0 ) + {{ point }}.Y() * {{ matrix }}( 0, 1 ) +
            {{ point }}.Z() * {{ matrix }}( 0, 2 ) + {{ matrix }}( 0, 3 ),
        {{ point }}.X() * {{ matrix }}( 1, 0 ) + {{ point }}.Y() * {{ matrix }}( 1, 1 ) +
            {{ point }}.Z() * {{ matrix }}( 1, 2 ) + {{ matrix }}( 1, 3 ),
        {{ point }}.X() * {{ matrix }}( 2, 0 ) + {{ point }}.Y() * {{ matrix }}( 2, 1 ) +
            {{ point }}.Z() * {{ matrix }}( 2, 2 ) + {{ matrix }}( 2, 3 )
    );
    {{ pointType.elementType.className }} homogenousWeight = {{ point }}.X() * {{ matrix }}( 3, 0 ) +
        {{ point }}.Y() * {{ matrix }}( 3, 1 ) + {{ point }}.Z() * {{ matrix }}( 3, 2 ) + {{ matrix }}( 3, 3 );
    if ( homogenousWeight == 1.0 )
    {
        return transformedPoint;
    }
    else
    {
        return transformedPoint / homogenousWeight;
    }
}
{% endfor %}
{% endblock %}
