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
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Compute the position along a ray by scalar magnitude \p {{ interface.ArgName("magnitude") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \pre \p {{ interface.ArgName("direction") }} must be a normalized vector.
///
/// \sa \ref Normalize for vector normalization.
///
/// \param {{ interface.ArgName("origin") }} The origin of the ray.
/// \param {{ interface.ArgName("direction") }} The direction of the ray.
/// \param {{ interface.ArgName("magnitude") }} The magnitude to project the ray.
///
/// \return the position along the curve.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( Length( {{ interface.ArgName("direction") }} ) ==
                   {{ interface.ArgType("direction").CppValue( 1 ) }},
                   "Direction {{ interface.ArgName("direction") }} is not normalised!" );
    return {{ interface.ArgName("origin") }} +
           ( {{ interface.ArgName("direction") }} * {{ interface.ArgName("magnitude") }} );
}
{% endfor %}
{% endblock %}
