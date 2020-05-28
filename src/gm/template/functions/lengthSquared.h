#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the length squared of a vector, defined as the <em>sum of the squares</em> of <em>each vector element</em>.
///
/// Can also be represented as the dot product (see \ref functions/dotProduct.h) of the vector with itself.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/dotProduct.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the length squared of the vector \p {{ interface.Param("vector").variableName }}.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedParameters }} )
{
    return DotProduct( {{ interface.Param("vector").variableName }},
                       {{ interface.Param("vector").variableName }} );
}
{% endfor %}

GM_NS_CLOSE
