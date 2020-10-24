{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Trilinear interpolation.
///
/// Interpolate within a 3D grid, bounded by 8 anchoring corner points, with 3 weights
/// (one for each interpolating dimension).
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/linearInterpolation.h>
#include <gm/functions/bilinearInterpolation.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set valueType = interface.ArgType("corner000") %}
{% set corner000 = interface.ArgName("corner000") %}
{% set corner100 = interface.ArgName("corner100") %}
{% set corner010 = interface.ArgName("corner010") %}
{% set corner110 = interface.ArgName("corner110") %}
{% set corner001 = interface.ArgName("corner001") %}
{% set corner101 = interface.ArgName("corner101") %}
{% set corner011 = interface.ArgName("corner011") %}
{% set corner111 = interface.ArgName("corner111") %}
{% set weight    = interface.ArgName("weight") %}
/// Trilinearly interpolate in a rectilinear 3D grid.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ corner000 }} The \p (0, 0, 0) corner point of the grid.
/// \param {{ corner100 }} The \p (0, 0, 1) corner point of the grid.
/// \param {{ corner010 }} The \p (0, 1, 0) corner point of the grid.
/// \param {{ corner110 }} The \p (0, 1, 1) corner point of the grid.
/// \param {{ corner001 }} The \p (1, 0, 0) corner point of the grid.
/// \param {{ corner101 }} The \p (1, 0, 1) corner point of the grid.
/// \param {{ corner011 }} The \p (1, 1, 0) corner point of the grid.
/// \param {{ corner111 }} The \p (1, 1, 1) corner point of the grid.
/// \param {{ weight }} The weight for linearly interpolating across the 3 axis.
///
/// \pre \p {{ weight }}.X(), \p {{ weight }}.Y(), and \p {{ weight }}.Z() must be in the range of [0,1].
///
/// \return Trilinearly interpolated value.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( {{ weight }}.X() >= 0.0f && {{ weight }}.X() <= 1.0f,
                   "Expected {{ weight }}.X() between [0,1], got %f\n",
                   {{ weight }}.X() );
    GM_ASSERT_MSG( {{ weight }}.Y() >= 0.0f && {{ weight }}.X() <= 1.0f,
                   "Expected {{ weight }}.Y() between [0,1], got %f\n",
                   {{ weight }}.Y() );
    GM_ASSERT_MSG( {{ weight }}.Z() >= 0.0f && {{ weight }}.Z() <= 1.0f,
                   "Expected {{ weight }}.Z() between [0,1], got %f\n",
                   {{ weight }}.Z() );

    // Bilinearly interpolate the two sides orthogonal to the Z-axis of the grid.
    {{ valueType.namespacedClassName }} interm0 = BilinearInterpolation(
        {{ corner000 }},
        {{ corner100 }},
        {{ corner010 }},
        {{ corner110 }},
        Vec2f( {{ weight }}.X(), {{ weight }}.Y() )
    );
    {{ valueType.namespacedClassName }} interm1 = BilinearInterpolation(
        {{ corner001 }},
        {{ corner101 }},
        {{ corner011 }},
        {{ corner111 }},
        Vec2f( {{ weight }}.X(), {{ weight }}.Y() )
    );

    // Linearly interpolate the two intermediate values based on the Z weight.
    return LinearInterpolation( interm0, interm1, {{ weight }}.Z() );
}
{% endfor %}
{% endblock %}
