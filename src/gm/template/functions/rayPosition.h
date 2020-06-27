#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Ray position computation.
///
/// Compute the position of the ray from an \b origin, offset by a \b direction and \b magnitude.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <gm/functions/length.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the ray position from \p i_origin project into direction \p i_direction with magnitude \p i_magnitude.
///
/// \param {{ interface.ArgName("origin") }} The origin of the ray.
/// \param {{ interface.ArgName("direction") }} The direction of the ray.
/// \param {{ interface.ArgName("magnitude") }} The magnitude to project the ray.
///
/// \return the projected ray position.
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
