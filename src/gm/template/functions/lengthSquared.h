#pragma once

/// \file functions/{{ context.headerFileName }}
///
/// Compute the length squared of a vector, defined as the <em>sum of the squares</em> of <em>each vector element</em>.
///
/// Can also be represented as the dot product (see \ref functions/dotProduct.h) of the vector with itself.

#include <gm/gm.h>

{% for vectorType in context.types -%}
#include <gm/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <gm/functions/lengthSquared.h>

GM_NS_OPEN

{% for vectorType in context.types %}
/// Compute the length squared of the vector \p i_vector.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline {{ vectorType.elementType.className }} {{ context.functionName }}(
    const {{ vectorType.className }}& i_vector )
{
    return DotProduct( i_vector, i_vector );
}
{% endfor %}

PBR_NAMESPACE_END
