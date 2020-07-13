{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Check if the input matrix is the identity matrix.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Check if the matrix \p {{ interface.ArgName("matrix") }} is the identity matrix.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("matrix") }} Input matrix.
///
/// \retval true If \p {{ interface.ArgName("matrix") }} is the identity matrix.
/// \retval false If \p {{ interface.ArgName("matrix") }} is not the identity matrix.
{{- functionUtils.signature(function, interface) -}}
{
    return
{% for row in range(matrixType.shape[0]) -%}
{% for col in range(matrixType.shape[1]) -%}
{% if row == col -%}
    {{ matrix }}( {{ row }}, {{ col }} ) == {{ matrixType.CppValue(1) }}
{%- else -%}
    {{ matrix }}( {{ row }}, {{ col }} ) == {{ matrixType.CppValue(0) }}
{%- endif %}
{% if row + 1 < matrixType.shape[0] or col + 1 < matrixType.shape[1] -%}
    &&
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    ;
}
{% endfor %}
{% endblock %}
