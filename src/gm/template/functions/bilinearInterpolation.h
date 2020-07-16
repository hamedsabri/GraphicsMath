{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Bilinear interpolation.
///
/// Interpolate within a 2D rectilinear grid, bounded by 4 anchoring values, with two weights.
///
/// Linearly interpolating across the \em first dimension using the \em first weight will result in two values.
/// These two values are then linearly interpolated as a function of the \em second weight.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/linearInterpolation.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set valueType = interface.ArgType("value00") %}
{% set value00   = interface.ArgName("value00") %}
{% set value01   = interface.ArgName("value01") %}
{% set value10   = interface.ArgName("value10") %}
{% set value11   = interface.ArgName("value11") %}
{% set weightX   = interface.ArgName("weightX") %}
{% set weightY   = interface.ArgName("weightY") %}
/// Bilinearly interpolate in a rectilinear grid.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ value00 }} The value at (0, 0).
/// \param {{ value01 }} The value at (0, 1).
/// \param {{ value10 }} The value at (1, 0).
/// \param {{ value11 }} The value at (1, 1).
/// \param {{ weightX }} The weight for linearly interpolating across the X coordinates.
/// \param {{ weightY }} The weight for linearly interpolating across the Y coordinates.
///
/// \pre \p {{ weightX }} and \p {{ weightY }} must be in the range of [0,1].
///
/// \return Linearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ weightX }} >= 0.0f && {{ weightX }} <= 1.0f,
                   "Expected {{ weightX }} between [0,1], got %f\n",
                   {{ weightX }} );
    GM_ASSERT_MSG( {{ weightY }} >= 0.0f && {{ weightX }} <= 1.0f,
                   "Expected {{ weightY }} between [0,1], got %f\n",
                   {{ weightY }} );

    {{ valueType.namespacedClassName }} value0 = gm::LinearInterpolation( {{ value00 }}, {{ value01 }}, {{ weightX }} );
    {{ valueType.namespacedClassName }} value1 = gm::LinearInterpolation( {{ value10 }}, {{ value11 }}, {{ weightX }} );
    return gm::LinearInterpolation( value0, value1, {{ weightY }} );
}
{% endfor %}
{% endblock %}
