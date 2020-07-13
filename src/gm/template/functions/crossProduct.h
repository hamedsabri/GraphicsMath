{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Vector cross product.
///
/// The cross product of two equal-length vectors \f$\textnormal{cross}(u,v)\f$ is defined as a vector
/// \f$w\f$ of the same length, that is orthgonal to both \f$u\f$ and \f$v\f$.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set lhs = interface.ArgName("lhs") %}
{% set rhs = interface.ArgName("rhs") %}
/// Compute the cross product of two \ref {{ interface.ArgClass("lhs") }}, \p {{ lhs }}
/// and \p {{ rhs }}, and return the result.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ lhs }} Left hand side vector.
/// \param {{ rhs }} Right hand side vector.
///
/// \return Cross product of the two vectors.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.ArgClass("lhs") }}(
        ( {{ lhs }}[ 1 ] * {{ rhs }}[ 2 ] - {{ lhs }}[ 2 ] * {{ rhs }}[ 1 ] ),
        ( {{ lhs }}[ 2 ] * {{ rhs }}[ 0 ] - {{ lhs }}[ 0 ] * {{ rhs }}[ 2 ] ),
        ( {{ lhs }}[ 0 ] * {{ rhs }}[ 1 ] - {{ lhs }}[ 1 ] * {{ rhs }}[ 0 ] )
    );
}
{% endfor %}
{% endblock %}
