{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Look-at transformation, for a left-handed coordinate system.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/normalize.h>
#include <gm/functions/crossProduct.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set position = interface.ArgName("position") %}
{% set look     = interface.ArgName("look") %}
{% set up       = interface.ArgName("up") %}
{% set vectorType = interface.ArgType("position") %}
{% set matrixType = interface.returnType %}
/// Construct a transformation for placing a camera in a scene provided a
/// position, look at point, and up vector.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ position }} Position of the camera.
/// \param {{ look }} Point in space for the camera to look at.
/// \param {{ up }} The up vector of the camera, for orientation purposes.
///
/// \return Transformation for positioning and orienting the camera.
{{- functionUtils.signature(function, interface) -}}
{
    {{ vectorType.className }} lookDir = Normalize( {{ look }} - {{ position }} );
    {{ vectorType.className }} right = Normalize( CrossProduct( Normalize( {{ up }} ), lookDir ) );
    {{ vectorType.className }} newUp = CrossProduct( lookDir, right );

    // Construct matrix.
    {{ matrixType.className }} matrix;

    // First column.
    matrix( 0, 0 ) = right.X();
    matrix( 1, 0 ) = right.Y();
    matrix( 2, 0 ) = right.Z();
    matrix( 3, 0 ) = 0;

    // Second column.
    matrix( 0, 1 ) = newUp.X();
    matrix( 1, 1 ) = newUp.Y();
    matrix( 2, 1 ) = newUp.Z();
    matrix( 3, 1 ) = 0;

    // Third column.
    matrix( 0, 2 ) = lookDir.X();
    matrix( 1, 2 ) = lookDir.Y();
    matrix( 2, 2 ) = lookDir.Z();
    matrix( 3, 2 ) = 0;

    // Fourth column.
    matrix( 0, 3 ) = {{ position }}.X();
    matrix( 1, 3 ) = {{ position }}.Y();
    matrix( 2, 3 ) = {{ position }}.Z();
    matrix( 3, 3 ) = 1;

    return matrix;
}

{% endfor %}
{% endblock %}
