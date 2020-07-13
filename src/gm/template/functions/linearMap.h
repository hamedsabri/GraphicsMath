{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Linear mapping.
///
/// Map a value from a source range into a target range, such the ratio of the respective values within
/// their ranges remain constant:
///
/// \f[ R*(S_v-S_0)+T_0=T_v\f]
/// \f[ S_v=\textnormal{Source value} \f]
/// \f[ S_0,S_1=\textnormal{Source range} \f]
/// \f[ T_v=\textnormal{Target value} \f]
/// \f[ T_0,T_1=\textnormal{Target range} \f]
/// \f[ R=\frac{T_1-T_0}{S_1-S_0}=\textnormal{Ratio of the target to source range} \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set sourceValue = interface.ArgName("sourceValue") %}
{% set sourceRange = interface.ArgName("sourceRange") %}
{% set targetRange = interface.ArgName("targetRange") %}
/// Linearly maps a source value in range \p {{ sourceRange }} into the range \p {{ targetRange }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ sourceValue }} Value to map from the source range.
/// \param {{ sourceRange }} Source value range to map from.
/// \param {{ targetRange }} Target value range to map to.
///
/// \pre \p {{ sourceRange }}'s min and max values cannot be equal.
///
/// \return Linearly mapped target value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ sourceRange }}.Min() != {{ sourceRange }}.Max() );
    float ratio = ( {{ targetRange }}.Max() - {{ targetRange }}.Min() ) /
                  ( {{ sourceRange }}.Max() - {{ sourceRange }}.Min() );
{% if interface.Arg("sourceValue").type.isScalar -%}
    return {{ targetRange }}.Min() + ( ratio * ( {{ sourceValue }} - {{ sourceRange }}.Min() ) );
{%- elif interface.Arg("sourceValue").type.isVector -%}
    return {{ interface.ArgClass("sourceValue") }}(
{%- for index in range(interface.Arg("sourceValue").type.elementSize) %}
    {{ targetRange }}.Min() + ( ratio * ( {{ sourceValue }}[ {{ index }} ] - {{ sourceRange }}.Min() ) )
{%- if index + 1 < interface.Arg("sourceValue").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
