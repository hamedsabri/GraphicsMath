{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Dot product, or inner product between two <em>equal-length</em> vectors.
///
/// The corresponding elements of the two vector(s) are multipled, and the products reduced via summation,
/// into a single value.
///
/// This operation can be geometrically represented as the magnitudes between the vectors and the cosine of
/// the angle between them.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set lhs = interface.ArgName("lhs") %}
{% set rhs = interface.ArgName("rhs") %}
{% set vectorType = interface.ArgType("lhs") %}
/// Compute the dot product of two \ref {{ interface.ArgClass("lhs") }}, \p {{ lhs }}
/// and \p {{ rhs }}, and return the result.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ lhs }} Left hand side vector.
/// \param {{ rhs }} Right hand side vector.
///
/// \return Dot product of the two vectors.
{{- functionUtils.signature(function, interface) -}}
{
    return
{% for index in range(vectorType.elementSize) -%}
    {{ lhs }}[ {{ index }} ] * {{ rhs }}[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
        +
{%- endif -%}
{%- endfor -%}
    ;
}
{% endfor %}
{% endblock %}
