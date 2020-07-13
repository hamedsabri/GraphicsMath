{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Position along a ray.
///
/// Computed as the scalar \em multiplication of a \b direction vector \em added to a point \b origin.
///
/// \ref RayPosition can be used to find the exact intersection points against objects in the scene.
///
/// Equation of a position \f$P\f$ along a ray:
///
/// \f[ O+tD=P                              \f]
/// \f[ O=\textnormal{Ray origin vector}    \f]
/// \f[ t=\textnormal{Magnitude scalar}     \f]
/// \f[ D=\textnormal{Ray direction vector} \f]
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/length.h>
#include <gm/base/almost.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set origin    = interface.ArgName("origin") %}
{% set direction = interface.ArgName("direction") %}
{% set magnitude = interface.ArgName("magnitude") %}
/// Compute the position along a ray by scalar magnitude \p {{ magnitude }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \pre \p {{ direction }} must be a normalized vector.
///
/// \sa \ref Normalize for vector normalization.
///
/// \param {{ origin }} The origin of the ray.
/// \param {{ direction }} The direction of the ray.
/// \param {{ magnitude }} The magnitude to project the ray.
///
/// \return the position along the curve.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( AlmostEqual( Length( {{ direction }} ),
                                {{ interface.ArgType("direction").CppValue( 1 ) }} ),
                   "Direction {{ direction }} is not normalised!" );
    return {{ origin }} + ( {{ direction }} * {{ magnitude }} );
}
{% endfor %}
{% endblock %}
