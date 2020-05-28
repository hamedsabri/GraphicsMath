#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the length squared of a vector, defined as the <em>sum of the squares</em> of <em>each vector element</em>.
///
/// Can also be represented as the dot product (see \ref functions/dotProduct.h) of the vector with itself.

#include <gm/gm.h>

{% for type in function.GetTypeSet() -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/dotProduct.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the length squared of the vector \p {{ interface.GetParameter("vector").cppName }}.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.GetTypedParameters() }} )
{
    return DotProduct( {{ interface.GetParameter("vector").cppName }},
                       {{ interface.GetParameter("vector").cppName }} );
}
{% endfor %}

GM_NS_CLOSE
