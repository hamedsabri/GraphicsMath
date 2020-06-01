#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Floor the input value, by rounding downwards, returning the largest integral number less than the input.
/// If the value type is a vector, the floor will be performed element-wise.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <cmath>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Floor the input \ref {{ interface.ParamCls("value") }} \p {{ interface.ParamArg("value") }} and return it.
///
/// \return the floored input value.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedParameters }} )
{
{% if interface.Param("value").type.isScalar -%}
    return std::floor( {{ interface.ParamArg("value") }} );
{%- elif interface.Param("value").type.isVector -%}
    return {{ interface.ParamCls("value") }}(
{%- for index in range(interface.Param("value").type.elementSize) %}
        std::floor( {{ interface.ParamArg("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Param("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
