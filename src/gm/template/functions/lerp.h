#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Linear interpolation.
///
/// Linearly interpolate between two values with a supplied weight.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Linearly interpolate between \p {{ interface.ArgName("valueA") }} and \p {{ interface.ArgName("valueB") }}, with weight \p {{ interface.ArgName("weight") }}.
///
/// \param {{ interface.ArgName("valueA") }} the source value to interpolate from.
/// \param {{ interface.ArgName("valueB") }} the target value to interpolate to.
/// \param {{ interface.ArgName("weight") }} must be in the range of [0,1].  Describes the percentage of \p {{ interface.ArgName("valueB") }} in the final,
/// interpolated value.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    GM_ASSERT_MSG( {{ interface.ArgName("weight") }} >= 0.0f && {{ interface.ArgName("weight") }} <= 1.0f,
                   "Expected {{ interface.ArgName("weight") }} between [0,1], got %f\n",
                   {{ interface.ArgName("weight") }} );
    return ( ( 1.0f - {{ interface.ArgName("weight") }} ) * {{ interface.ArgName("valueA") }} ) + ( {{ interface.ArgName("weight") }} * {{ interface.ArgName("valueB") }} );
}
{% endfor %}

GM_NS_CLOSE
