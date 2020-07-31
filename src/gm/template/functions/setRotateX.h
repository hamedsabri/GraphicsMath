{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Set a X-axis rotation on a transformation matrix, with respect to the left hand rule.
///
/// An X-axis rotation in degrees \f$\theta\f$ set on a \p 4 by \p 4 identity matrix \f$I\f$ will produce:
/// \f[
/// \begin{bmatrix}
/// 1      & 0         & 0          & 0      \\
/// 0      & cos\theta & -sin\theta & 0      \\
/// 0      & sin\theta & cos\theta  & 0      \\
/// 0      & 0         & 0          & 1
/// \end{bmatrix}
/// \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/radians.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set angle      = interface.ArgName("angle") %}
{% set angleClass = interface.ArgClass("angle") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Set a X-axis rotation of \p {{ angle }} degrees onto the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ angle }} The angle of rotation in degrees.
/// \param {{ matrix }} Transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
    {{ angleClass }} radians = Radians( {{ angle }} );
    {{ angleClass }} sine = std::sin( radians );
    {{ angleClass }} cosine = std::cos( radians );
    {{ matrix }}( 1, 1 ) = cosine;
    {{ matrix }}( 1, 2 ) = -sine;
    {{ matrix }}( 2, 1 ) = sine;
    {{ matrix }}( 2, 2 ) = cosine;
}
{% endfor %}
{% endblock %}
