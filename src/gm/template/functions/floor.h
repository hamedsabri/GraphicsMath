#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup gm_functions_basic
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
/// Floor the input \ref {{ interface.ArgClass("value") }} \p {{ interface.ArgName("value") }} and return it.
/// \ingroup gm_functions_basic
///
/// \return the floored input value.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
{% if interface.Arg("value").type.isScalar -%}
    return std::floor( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::floor( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
