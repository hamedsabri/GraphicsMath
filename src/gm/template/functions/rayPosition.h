#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_rayTracing
///
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

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <gm/functions/length.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// \ingroup GM_group_functions_rayTracing
/// Compute the position along a ray by scalar magnitude \p {{ interface.ArgName("magnitude") }}.
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
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    GM_ASSERT_MSG( Length( {{ interface.ArgName("direction") }} ) ==
                   {{ interface.ArgType("direction").CppValue( 1 ) }},
                   "Direction {{ interface.ArgName("direction") }} is not normalised!" );
    return {{ interface.ArgName("origin") }} +
           ( {{ interface.ArgName("direction") }} * {{ interface.ArgName("magnitude") }} );
}
{% endfor %}

GM_NS_CLOSE
