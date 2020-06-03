#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Ceil the input value, by rounding upwards to the nearest integral value.
/// If the value type is a vector, the ceil will be performed element-wise.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <cmath>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Ceil the input \ref {{ interface.ArgClass("value") }} \p {{ interface.ArgName("value") }} and return it.
///
/// \return the rounded input value.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
{% if interface.Arg("value").type.isScalar -%}
    return std::ceil( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::ceil( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
