{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Set a scaling transform on a transformation matrix.
///
/// The scale vector \f$S=(S_x,S_y,S_z)\f$ set on a \p 4 by \p 4 identity matrix \f$I\f$ will produce:
/// \f[
/// \begin{bmatrix}
/// S_x    & 0      & 0       & 0      \\
/// 0      & S_y    & 0       & 0      \\
/// 0      & 0      & S_z     & 0      \\
/// 0      & 0      & 0       & 1
/// \end{bmatrix}
/// \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vector     = interface.ArgName("vector") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Set the scale \p {{ vector }} onto the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ vector }} Scale vector.
/// \param {{ matrix }} Transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
{% for row in range(matrixType.shape[0]) -%}
{% for col in range(matrixType.shape[1]) -%}
{% if row == col and row + 1 < matrixType.shape[0] -%}
    {{ matrix }}( {{ row }}, {{ col }} ) = {{ vector }}[ {{ row }} ];
{%- endif %}
{%- endfor -%}
{%- endfor -%}
}
{% endfor %}
{% endblock %}
