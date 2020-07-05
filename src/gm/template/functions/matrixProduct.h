{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Matrix multiplication.
///
/// Mathematically described as the composition of two linear maps.
///
/// For matrices A and B, their product AB is only defined if <em># columns of A</em> equals <em># rows of B</em>,
/// The matrix product AB will assume the shape (# rows of A, # cols of B).
///
/// Each entry (i, j) in the matrix product AB can be computed as the dot (or inner) product of the \em i'th
/// row vector of A and the \em j'th column vector of B.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Multiply input matrices \p {{ interface.ArgName("lhs") }} and \p {{ interface.ArgName("rhs") }}
/// to produce their matrix product.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("lhs") }} Left hand side matrix.
/// \param {{ interface.ArgName("rhs") }} Right hand side matrix.
///
/// \return The matrix product.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.ArgType("lhs").className }}(
{%- for row in range(interface.ArgType("lhs").shape[0] ) -%}
{%- for col in range(interface.ArgType("lhs").shape[1] ) -%}
{%- for index in range( interface.ArgType("lhs").shape[0] ) -%}
    {{ interface.ArgName("lhs") }}( {{ row }}, {{ index }} ) * {{ interface.ArgName("rhs") }}( {{ index }}, {{ col }} )
{%- if index + 1 < interface.ArgType("lhs").shape[0] -%}
    +
{%- elif (index + 1 == interface.ArgType("lhs").shape[1]) and (row + 1 < interface.ArgType("lhs").shape[0] or col + 1 < interface.ArgType("lhs").shape[1])-%}
    ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}
{% endblock %}
