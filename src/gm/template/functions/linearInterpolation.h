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
/// Linearly interpolate between \p {{ interface.ArgName("source") }} and \p {{ interface.ArgName("target") }}, with weight \p {{ interface.ArgName("weight") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("source") }} Source value to interpolate from.
/// \param {{ interface.ArgName("target") }} Target value to interpolate to.
/// \param {{ interface.ArgName("weight") }} Describes the percentage of \p {{ interface.ArgName("target") }} in the final, interpolated value.
///
/// \pre \p {{ interface.ArgName("weight") }} must be in the range of [0,1].
///
/// \return Linearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ interface.ArgName("weight") }} >= 0.0f && {{ interface.ArgName("weight") }} <= 1.0f,
                   "Expected {{ interface.ArgName("weight") }} between [0,1], got %f\n",
                   {{ interface.ArgName("weight") }} );
    return ( ( 1.0f - {{ interface.ArgName("weight") }} ) * {{ interface.ArgName("source") }} ) + ( {{ interface.ArgName("weight") }} * {{ interface.ArgName("target") }} );
}
{% endfor %}
{% endblock %}
