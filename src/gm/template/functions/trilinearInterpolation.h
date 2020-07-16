{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Trilinear interpolation.
///
/// Interpolate within a 3D rectilinear grid, bounded by 8 anchoring values, with 3 weights
/// (one for each interpolating dimension).
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/linearInterpolation.h>
#include <gm/functions/bilinearInterpolation.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set valueType = interface.ArgType("value000") %}
{% set value000  = interface.ArgName("value000") %}
{% set value001  = interface.ArgName("value001") %}
{% set value010  = interface.ArgName("value010") %}
{% set value011  = interface.ArgName("value011") %}
{% set value100  = interface.ArgName("value100") %}
{% set value101  = interface.ArgName("value101") %}
{% set value110  = interface.ArgName("value110") %}
{% set value111  = interface.ArgName("value111") %}
{% set weightX   = interface.ArgName("weightX") %}
{% set weightY   = interface.ArgName("weightY") %}
{% set weightZ   = interface.ArgName("weightZ") %}
/// Trilinearly interpolate in a rectilinear 3D grid.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ value000 }} The value at (0, 0, 0).
/// \param {{ value001 }} The value at (0, 0, 1).
/// \param {{ value010 }} The value at (0, 1, 0).
/// \param {{ value011 }} The value at (0, 1, 1).
/// \param {{ value100 }} The value at (1, 0, 0).
/// \param {{ value101 }} The value at (1, 0, 1).
/// \param {{ value110 }} The value at (1, 1, 0).
/// \param {{ value111 }} The value at (1, 1, 1).
/// \param {{ weightX }} The weight for linearly interpolating across the X coordinates.
/// \param {{ weightY }} The weight for linearly interpolating across the Y coordinates.
/// \param {{ weightZ }} The weight for linearly interpolating across the Z coordinates.
///
/// \pre \p {{ weightX }}, \p {{ weightY }}, and \p {{ weightZ }} must be in the range of [0,1].
///
/// \return Trilinearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ weightX }} >= 0.0f && {{ weightX }} <= 1.0f,
                   "Expected {{ weightX }} between [0,1], got %f\n",
                   {{ weightX }} );
    GM_ASSERT_MSG( {{ weightY }} >= 0.0f && {{ weightX }} <= 1.0f,
                   "Expected {{ weightY }} between [0,1], got %f\n",
                   {{ weightY }} );
    GM_ASSERT_MSG( {{ weightZ }} >= 0.0f && {{ weightZ }} <= 1.0f,
                   "Expected {{ weightZ }} between [0,1], got %f\n",
                   {{ weightZ }} );

    {{ valueType.namespacedClassName }} value0 = gm::BilinearInterpolation(
        {{ value000 }},
        {{ value001 }},
        {{ value010 }},
        {{ value011 }},
        {{ weightX }},
        {{ weightY }}
    );
    {{ valueType.namespacedClassName }} value1 = gm::BilinearInterpolation(
        {{ value100 }},
        {{ value101 }},
        {{ value110 }},
        {{ value111 }},
        {{ weightX }},
        {{ weightY }}
    );
    return gm::LinearInterpolation( value0, value1, {{ weightZ }} );
}
{% endfor %}
{% endblock %}
