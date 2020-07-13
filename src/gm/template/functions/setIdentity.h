{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Set the \em identity matrix \f$I\f$, defined as the neutral element with respect to matrix multiplication:
/// \f[ AI=A\f]
/// \f[ A=\textnormal{Any matrix} \f]
/// \f[ I=\textnormal{Identity matrix} \f]
///
/// The identity matrix is square(\f$M\textnormal{x}N\f$) with \f$1\f$s down the main diagonal,
/// and \f$0\f$s for all other entries.
/// \f[
/// \begin{bmatrix}
/// 1      & 0      & \cdots  &        & 0      \\
/// 0      & 1      &         &        &        \\
/// \vdots &        & \ddots  &        & \vdots \\
///        &        &         & 1      & 0      \\
/// 0      &        & \cdots  & 0      & 1
/// \end{bmatrix}
/// \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Set the identity matrix onto \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The matrix to set as the identity.
{{- functionUtils.signature(function, interface) -}}
{
    {{ matrix }} = {{ interface.ArgClass("matrix") }}(
{% for row in range(matrixType.shape[0]) -%}
{% for col in range(matrixType.shape[1]) -%}
{% if row == col -%}
    {{ matrixType.CppValue( 1 ) }}
{%- else -%}
    {{ matrixType.CppValue( 0 ) }}
{%- endif %}
{% if row + 1 < matrixType.shape[0] or col + 1 < matrixType.shape[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}
{% endblock %}
