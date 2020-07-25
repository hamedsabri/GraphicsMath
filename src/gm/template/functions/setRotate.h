{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Set a rotation for an specified axis on a transformation matrix, with respect to the right-hand rule.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/normalize.h>
#include <gm/functions/radians.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set angle      = interface.ArgName("angle") %}
{% set angleClass = interface.ArgClass("angle") %}
{% set axis       = interface.ArgName("axis") %}
{% set axisClass  = interface.ArgClass("axis") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Set a \p {{ axis }}  rotation of \p {{ angle }} degrees onto the transformation
/// matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ angle }} The angle of rotation in degrees.
/// \param {{ matrix }} Transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
    // Axis must be normalised.
    {{ axisClass }} normAxis = Normalize( {{ axis }} );

    // Compute cosine and sine.
    {{ angleClass }} radians = Radians( {{ angle }} );
    {{ angleClass }} sinTheta = std::sin( radians );
    {{ angleClass }} cosTheta = std::cos( radians );

    o_matrix( 0, 0 ) = normAxis[ 0 ] * normAxis[ 0 ] + (1 - normAxis[ 0 ] * normAxis[ 0 ]) * cosTheta;
    o_matrix( 0, 1 ) = normAxis[ 0 ] * normAxis[ 1 ] * (1 - cosTheta) - normAxis[ 2 ] * sinTheta;
    o_matrix( 0, 2 ) = normAxis[ 0 ] * normAxis[ 2 ] * (1 - cosTheta) + normAxis[ 1 ] * sinTheta;
    o_matrix( 0, 3 ) = 0;

    o_matrix( 1, 0 ) = normAxis[ 0 ] * normAxis[ 1 ] * (1 - cosTheta) + normAxis[ 2 ] * sinTheta;
    o_matrix( 1, 1 ) = normAxis[ 1 ] * normAxis[ 1 ] + (1 - normAxis[ 1 ] * normAxis[ 1 ]) * cosTheta;
    o_matrix( 1, 2 ) = normAxis[ 1 ] * normAxis[ 2 ] * (1 - cosTheta) - normAxis[ 0 ] * sinTheta;
    o_matrix( 1, 3 ) = 0;

    o_matrix( 2, 0 ) = normAxis[ 0 ] * normAxis[ 2 ] * (1 - cosTheta) - normAxis[ 1 ] * sinTheta;
    o_matrix( 2, 1 ) = normAxis[ 1 ] * normAxis[ 2 ] * (1 - cosTheta) + normAxis[ 0 ] * sinTheta;
    o_matrix( 2, 2 ) = normAxis[ 2 ] * normAxis[ 2 ] + (1 - normAxis[ 2 ] * normAxis[ 2 ]) * cosTheta;
    o_matrix( 2, 3 ) = 0;
}
{% endfor %}
{% endblock %}
