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
{% for row in range(interface.Arg("matrix").type.shape[0]) -%}
{% for col in range(interface.Arg("matrix").type.shape[1]) -%}
{% if row == col -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) == {{ interface.Arg("matrix").type.CppValue( 1 ) }}
{%- else -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) == {{ interface.Arg("matrix").type.CppValue( 0 ) }}
{%- endif %}
{% if row + 1 < interface.Arg("matrix").type.shape[0] or col + 1 < interface.Arg("matrix").type.shape[ 1 ] -%}
    &&
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    ;
}
{% endfor %}
{% endblock %}
