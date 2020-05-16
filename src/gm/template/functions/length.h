#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the \b length, or magnitude, of a vector.
///
/// The length of a vector is defined as the <em>square root</em> of the <em>sum of the squares</em>
/// of <em>each vector element</em>.

#include <gm/gm.h>

{% for vectorType in function.types -%}
#include <gm/types/{{ vectorType.headerFileName }}>
{% endfor %}

#include <gm/functions/lengthSquared.h>

GM_NS_OPEN

{% for vectorType in function.types %}
/// Compute the length of the vector \p i_vector.
///
/// \return the length of the vector.
GM_HOST_DEVICE inline {{ vectorType.elementType.className }} {{ function.name }}(
    const {{ vectorType.className }}& i_vector )
{
    return sqrt( LengthSquared( i_vector ) );
}
{% endfor %}

GM_NS_CLOSE
