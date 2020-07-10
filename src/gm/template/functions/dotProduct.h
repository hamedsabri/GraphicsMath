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
/// Compute the dot product of two \ref {{ interface.ArgClass("lhs") }}, \p {{ interface.ArgName("lhs") }}
/// and \p {{ interface.ArgName("rhs") }}, and return the result.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("lhs") }} Left hand side vector.
/// \param {{ interface.ArgName("rhs") }} Right hand side vector.
///
/// \return Dot product of the two vectors.
{{- functionUtils.signature(function, interface) -}}
{
    return
{% for index in range(interface.Arg("lhs").type.elementSize) -%}
    {{ interface.ArgName("lhs") }}[ {{ index }} ] * {{ interface.ArgName("rhs") }}[ {{ index }} ]
{%- if index + 1 < interface.Arg("lhs").type.elementSize -%}
        +
{%- endif -%}
{%- endfor -%}
    ;
}
{% endfor %}
{% endblock %}
