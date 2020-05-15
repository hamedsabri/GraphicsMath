#pragma once

/// \file functions/{{ context.headerFileName }}
///
/// Dot product, or scalar product between two <em>equal-length</em> vectors.
///
/// The corresponding elements of the two vector(s) are multipled, and the products reduced via summation,
/// into a single value.
///
/// This operation can be geometrically represented as the magnitudes between the vectors and the cosine of
/// the angle between them.

#include <gm/gm.h>

{% for vectorType in context.types -%}
#include <gm/types/{{ vectorType.headerFileName }}>
{% endfor %}

GM_NS_OPEN

{% for vectorType in context.types %}
/// Compute the dot product of two \ref {{ vectorType.className }}, \p i_lhs and \p i_rhs, and return the result.
///
/// \return computed dot product.
GM_HOST_DEVICE
inline {{ vectorType.elementType.className }} {{ context.functionName }}( const {{ vectorType.className }}& i_lhs,
                                                                          const {{ vectorType.className }}& i_rhs )
{
    {{ vectorType.elementType.className }} product;
{% for index in range(vectorType.elementSize) -%}
    product += i_lhs[ {{ index }} ] * i_rhs[ {{ index }} ];
{%- endfor %}
    return product;
}
{% endfor %}

GM_NS_CLOSE
