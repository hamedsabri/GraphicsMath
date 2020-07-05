{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Matrix transpose.
///
/// Roughly speaking, transposing a matrix flips it across its main diagonal.
///
/// Or, more precisely:
/// - the rows of the original matrix become the columns of the transposed matrix.
/// - for each entry specified by (i, j) in the original matrix, the corresponding entryin the transposed resides in (j, i).
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Transpose the input matrix \p {{ interface.ArgName("matrix") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("matrix") }} The input matrix to transpose.
///
/// \return Transposed matrix.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.ArgType("matrix").className }}(
{% for row in range(interface.ArgType("matrix").shape[0]) -%}
{% for col in range(interface.ArgType("matrix").shape[1]) -%}
    {{ interface.ArgName("matrix") }}( {{ col }}, {{ row }} )
{% if row + 1 < interface.ArgType("matrix").shape[0] or col + 1 < interface.ArgType("matrix").shape[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}
{% endblock %}
