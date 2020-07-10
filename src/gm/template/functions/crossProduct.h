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
/// Compute the cross product of two \ref {{ interface.ArgClass("lhs") }}, \p {{ interface.ArgName("lhs") }}
/// and \p {{ interface.ArgName("rhs") }}, and return the result.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("lhs") }} Left hand side vector.
/// \param {{ interface.ArgName("rhs") }} Right hand side vector.
///
/// \return Cross product of the two vectors.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ interface.ArgClass("lhs") }}(
        ( {{ interface.ArgName("lhs" ) }}[ 1 ] * {{ interface.ArgName("rhs") }}[ 2 ] -
          {{ interface.ArgName("lhs" ) }}[ 2 ] * {{ interface.ArgName("rhs") }}[ 1 ] ),
        ( {{ interface.ArgName("lhs" ) }}[ 2 ] * {{ interface.ArgName("rhs") }}[ 0 ] -
          {{ interface.ArgName("lhs" ) }}[ 0 ] * {{ interface.ArgName("rhs") }}[ 2 ] ),
        ( {{ interface.ArgName("lhs" ) }}[ 0 ] * {{ interface.ArgName("rhs") }}[ 1 ] -
          {{ interface.ArgName("lhs" ) }}[ 1 ] * {{ interface.ArgName("rhs") }}[ 0 ] )
    );
}
{% endfor %}
{% endblock %}
