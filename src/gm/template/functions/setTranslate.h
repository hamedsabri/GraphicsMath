{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Set a translation on a transformation matrix.
///
/// The translate vector \f$T=(T_x,T_y,T_z)\f$ set on a \p 4 by \p 4 identity matrix \f$I\f$ will produce:
/// \f[
/// \begin{bmatrix}
/// 1      & 0      & 0       & T_x    \\
/// 0      & 1      & 0       & T_y    \\
/// 0      & 0      & 1       & T_z    \\
/// 0      & 0      & 0       & 1
/// \end{bmatrix}
/// \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Set the translation \p {{ interface.ArgName("vector") }} onto the transformation matrix \p {{ interface.ArgName("matrix") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("vector") }} Translate vector.
/// \param {{ interface.ArgName("matrix") }} Transformation matrix.
{{- functionUtils.signature(function, interface) -}}
{
{% for row in range(interface.ArgType("matrix").shape[0]) -%}
{% for col in range(interface.ArgType("matrix").shape[1]) -%}
{% if row + 1 < interface.ArgType("matrix").shape[0] and col + 1 == interface.ArgType("matrix").shape[1] -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) = {{ interface.ArgName("vector") }}[ {{ row }} ];
{%- endif %}
{%- endfor -%}
{%- endfor -%}
}
{% endfor %}
{% endblock %}
