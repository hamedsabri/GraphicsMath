#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the \b length, or magnitude, of a vector.
///
/// The length of a vector is defined as the <em>square root</em> of the <em>sum of the squares</em>
/// of <em>each vector element</em>.

#include <gm/gm.h>

{% for type in function.GetTypeSet() -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/lengthSquared.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the length of the vector \p {{ interface.GetParameter("vector").cppName }}.
///
/// \return the length of the vector.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.GetTypedParameters() }} )
{
    return sqrt( LengthSquared( {{ interface.GetParameter("vector").cppName }} ) );
}
{% endfor %}

GM_NS_CLOSE
