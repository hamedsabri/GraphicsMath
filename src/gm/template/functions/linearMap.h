#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_interpolation
///
/// Linear mapping.
///
/// Map a value from a source range into a target range, such the ratio of the respective values within
/// their ranges remain constant:
///
/// \f[ R*(S_v-S_0)+T_0=T_v\f]
/// \f[ S_v=\textnormal{Source value} \f]
/// \f[ S_0,S_1=\textnormal{Source range} \f]
/// \f[ T_v=\textnormal{Target value} \f]
/// \f[ T_0,T_1=\textnormal{Target range} \f]
/// \f[ R=\frac{T_1-T_0}{S_1-S_0}=\textnormal{Ratio of the target to source range} \f]

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Linearly maps a source value in range \p {{ interface.ArgName("sourceRange") }} into the range \p {{ interface.ArgName("targetRange") }}.
///
/// \param {{ interface.ArgName("sourceValue") }} Value to map from the source range.
/// \param {{ interface.ArgName("sourceRange") }} Source value range to map from.
/// \param {{ interface.ArgName("targetRange") }} Target value range to map to.
///
/// \pre \p {{ interface.ArgName("sourceRange") }}'s min and max values cannot be equal.
///
/// \return Linearly mapped target value.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    GM_ASSERT( {{ interface.ArgName("sourceRange") }}[ 0 ] !=
               {{ interface.ArgName("sourceRange") }}[ 1 ] );
    float ratio = ( {{ interface.ArgName("targetRange") }}[ 1 ] - {{ interface.ArgName("targetRange") }}[ 0 ] ) /
                  ( {{ interface.ArgName("sourceRange") }}[ 1 ] - {{ interface.ArgName("sourceRange") }}[ 0 ] );
{% if interface.Arg("sourceValue").type.isScalar -%}
    return {{ interface.ArgName("targetRange") }}[ 0 ] +
           ( ratio * ( {{ interface.ArgName("sourceValue") }} - {{ interface.ArgName("sourceRange") }}[ 0 ] ) );
{%- elif interface.Arg("sourceValue").type.isVector -%}
    return {{ interface.ArgClass("sourceValue") }}(
{%- for index in range(interface.Arg("sourceValue").type.elementSize) %}
    {{ interface.ArgName("targetRange") }}[ 0 ] +
           ( ratio * ( {{ interface.ArgName("sourceValue") }}[ {{ index }} ] - {{ interface.ArgName("sourceRange") }}[ 0 ] ) )
{%- if index + 1 < interface.Arg("sourceValue").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
