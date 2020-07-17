{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Bilinear interpolation.
///
/// Interpolate within a 2D rectilinear grid, bounded by 4 anchoring corner points, with two weights along the
/// two axis.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/linearInterpolation.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set valueType = interface.ArgType("corner00") %}
{% set corner00  = interface.ArgName("corner00") %}
{% set corner10  = interface.ArgName("corner10") %}
{% set corner01  = interface.ArgName("corner01") %}
{% set corner11  = interface.ArgName("corner11") %}
{% set weight    = interface.ArgName("weight") %}
/// Bilinearly interpolate in a 2D rectilinear grid.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ corner00 }} The corner at (0, 0).
/// \param {{ corner10 }} The corner at (1, 0).
/// \param {{ corner01 }} The corner at (0, 1).
/// \param {{ corner11 }} The corner at (1, 1).
/// \param {{ weight }} The weights for interpolating in the X and Y axis.
///
/// \pre \p {{ weight }}.X() and \p {{ weight }}.Y() must be in the range of [0,1].
///
/// \return Bilinearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ weight }}.X() >= 0.0f && {{ weight }}.X() <= 1.0f,
                   "Expected {{ weight }}.X() between [0,1], got %f\n",
                   {{ weight }}.X() );
    GM_ASSERT_MSG( {{ weight }}.Y() >= 0.0f && {{ weight }}.X() <= 1.0f,
                   "Expected {{ weight }}.Y() between [0,1], got %f\n",
                   {{ weight }}.Y() );

    // Linearly interpolate along the X axis to produce two intermediate values.
    {{ valueType.namespacedClassName }} interm0 = gm::LinearInterpolation( {{ corner00 }}, {{ corner10 }}, {{ weight }}.X() );
    {{ valueType.namespacedClassName }} interm1 = gm::LinearInterpolation( {{ corner01 }}, {{ corner11 }}, {{ weight }}.X() );

    // Linearly interpolate the intermediate values along the Y axis.
    return gm::LinearInterpolation( interm0, interm1, {{ weight }}.Y() );
}
{% endfor %}
{% endblock %}
