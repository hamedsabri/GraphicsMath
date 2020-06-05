#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Compute the \b distance between two points.
///
/// The \b distance is computed by taking the \em length of the the <em>vector difference</em> between the two points.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/length.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Compute the distance of between points \p {{ interface.ArgName("pointA") }} and \p {{ interface.ArgName("pointB") }}.
///
/// \return the distance between the two points.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    return Length( {{ interface.ArgName("pointA") }} - {{ interface.ArgName("pointB") }} );
}
{% endfor %}

GM_NS_CLOSE