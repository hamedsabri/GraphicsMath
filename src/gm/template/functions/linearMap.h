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
/// Linearly maps a source value in range \p {{ interface.ArgName("sourceRange") }} into the range \p {{ interface.ArgName("targetRange") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("sourceValue") }} Value to map from the source range.
/// \param {{ interface.ArgName("sourceRange") }} Source value range to map from.
/// \param {{ interface.ArgName("targetRange") }} Target value range to map to.
///
/// \pre \p {{ interface.ArgName("sourceRange") }}'s min and max values cannot be equal.
///
/// \return Linearly mapped target value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ interface.ArgName("sourceRange") }}.Min() !=
               {{ interface.ArgName("sourceRange") }}.Max() );
    float ratio = ( {{ interface.ArgName("targetRange") }}.Max() - {{ interface.ArgName("targetRange") }}.Min() ) /
                  ( {{ interface.ArgName("sourceRange") }}.Max() - {{ interface.ArgName("sourceRange") }}.Min() );
{% if interface.Arg("sourceValue").type.isScalar -%}
    return {{ interface.ArgName("targetRange") }}.Min() +
           ( ratio * ( {{ interface.ArgName("sourceValue") }} - {{ interface.ArgName("sourceRange") }}.Min() ) );
{%- elif interface.Arg("sourceValue").type.isVector -%}
    return {{ interface.ArgClass("sourceValue") }}(
{%- for index in range(interface.Arg("sourceValue").type.elementSize) %}
    {{ interface.ArgName("targetRange") }}.Min() +
           ( ratio * ( {{ interface.ArgName("sourceValue") }}[ {{ index }} ] - {{ interface.ArgName("sourceRange") }}.Min() ) )
{%- if index + 1 < interface.Arg("sourceValue").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
