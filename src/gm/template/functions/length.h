#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the \b length, or magnitude, of a vector.
///
/// The length of a vector is defined as the <em>square root</em> of the <em>sum of the squares</em>
/// of <em>each vector element</em>.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/lengthSquared.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the length of the vector \p {{ interface.ParamArg("vector") }}.
///
/// \return the length of the vector.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedParameters }} )
{
    return sqrt( LengthSquared( {{ interface.ParamArg("vector") }} ) );
}
{% endfor %}

GM_NS_CLOSE
