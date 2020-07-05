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
/// Set the scale \p {{ interface.ArgName("vector") }} onto the transformation matrix \p {{ interface.ArgName("matrix") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("vector") }} Scale vector.
/// \param {{ interface.ArgName("matrix") }} Transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
{% for row in range(interface.ArgType("matrix").shape[0]) -%}
{% for col in range(interface.ArgType("matrix").shape[1]) -%}
{% if row == col and row + 1 < interface.ArgType("matrix").shape[0] -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) = {{ interface.ArgName("vector") }}[ {{ row }} ];
{%- endif %}
{%- endfor -%}
{%- endfor -%}
}
{% endfor %}
{% endblock %}
