{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Linear interpolation.
///
/// Linearly interpolate from a source to target value with a supplied weight:
///
/// \f[ ((1.0-w)*S)+(w*T)=V \f]
/// \f[ w=\textnormal{Weight} \f]
/// \f[ S=\textnormal{Source value} \f]
/// \f[ T=\textnormal{Target value} \f]
/// \f[ V=\textnormal{Interpolated value} \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set source = interface.ArgName("source") %}
{% set target = interface.ArgName("target") %}
{% set weight = interface.ArgName("weight") %}
/// Linearly interpolate between \p {{ source }} and \p {{ target }}, with weight \p {{ weight }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ source }} Source value to interpolate from.
/// \param {{ target }} Target value to interpolate to.
/// \param {{ weight }} Describes the percentage of \p {{ target }} in the final, interpolated value.
///
/// \pre \p {{ weight }} must be in the range of [0,1].
///
/// \return Linearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ weight }} >= 0.0f && {{ weight }} <= 1.0f,
                   "Expected {{ weight }} between [0,1], got %f\n",
                   {{ weight }} );
    return ( ( 1.0f - {{ weight }} ) * {{ source }} ) + ( {{ weight }} * {{ target }} );
}
{% endfor %}
{% endblock %}
