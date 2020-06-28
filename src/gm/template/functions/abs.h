#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_basic
///
/// Find the absolute value of two input values, defined as the magnitude of a real number without its sign.
///
/// If the value type is a vector, the absolute value will be performed on each element.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <algorithm>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Find the absolute value of the input \p {{ interface.ArgName("value") }}.
/// \ingroup GM_group_functions_basic
///
/// \return the absolute value of the input.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
{% if interface.Arg("value").type.isScalar -%}
    return std::abs( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::abs( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
