#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_linearAlgebra
///
/// Vector normalization.
///
/// The computation divides each of its elements by the vector length/magnitude.  The normalized vector is defined as a unit vector.

#include <gm/gm.h>

#include <gm/base/assert.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/length.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the normalised vector from the input vector \p {{ interface.ArgName("vector") }}.
/// \ingroup GM_group_functions_linearAlgebra
///
/// \return the normalised vector.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    {{ interface.ArgType("vector").elementType.className }} length = Length( {{ interface.ArgName("vector") }} );
    GM_ASSERT( length != {{ interface.ArgType("vector").CppValue( 0 ) }} );
    return {{ interface.ArgName("vector") }} / length;
}
{% endfor %}

GM_NS_CLOSE
