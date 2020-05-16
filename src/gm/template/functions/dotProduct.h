#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Dot product, or scalar product between two <em>equal-length</em> vectors.
///
/// The corresponding elements of the two vector(s) are multipled, and the products reduced via summation,
/// into a single value.
///
/// This operation can be geometrically represented as the magnitudes between the vectors and the cosine of
/// the angle between them.

#include <gm/gm.h>

{% for vectorType in function.types -%}
#include <gm/types/{{ vectorType.headerFileName }}>
{% endfor %}

GM_NS_OPEN

{% for vectorType in function.types %}
/// Compute the dot product of two \ref {{ vectorType.className }}, \p i_lhs and \p i_rhs, and return the result.
///
/// \return computed dot product.
GM_HOST_DEVICE inline {{ vectorType.elementType.className }} {{ function.name }}(
    const {{ vectorType.className }}& i_lhs,
    const {{ vectorType.className }}& i_rhs )
{
    return
{% for index in range(vectorType.elementSize) -%}
    i_lhs[ {{ index }} ] * i_rhs[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
        +
{%- endif -%}
{%- endfor -%}
    ;
}
{% endfor %}

GM_NS_CLOSE
