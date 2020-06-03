#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Find the minimum of two input values.
/// If the value type is a vector, the minimum will be performed element-wise.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}

#include <algorithm>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Find the minumum from the inputs \p {{ interface.ArgName("valueA") }} and \p {{ interface.ArgName("valueB") }}.
///
/// \return the minimum of the inputs.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
{% if interface.Arg("valueA").type.isScalar -%}
    return std::min( {{ interface.ArgName("valueA") }}, {{ interface.ArgName("valueB") }} );
{%- elif interface.Arg("valueA").type.isVector -%}
    return {{ interface.ArgClass("valueA") }}(
{%- for index in range(interface.Arg("valueA").type.elementSize) %}
        std::min( {{ interface.ArgName("valueA") }}[ {{ index }} ], {{ interface.ArgName("valueB") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("valueA").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}

GM_NS_CLOSE
