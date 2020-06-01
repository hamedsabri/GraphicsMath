#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Set the identity matrix, defined as the neutral element with respect to matrix multiplication.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Set the identity matrix onto \p {{ interface.ParamArg("matrix") }}.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedParameters }} )
{
    {{ interface.ParamArg("matrix") }} = {{ interface.ParamCls("matrix") }}(
{% for row in range(interface.Param("matrix").type.dims[0]) -%}
{% for col in range(interface.Param("matrix").type.dims[1]) -%}
{% if row == col -%}
    {{ interface.Param("matrix").type.CppNumber( 1 ) }}
{%- else -%}
    {{ interface.Param("matrix").type.CppNumber( 0 ) }}
{%- endif %}
{% if row + 1 < interface.Param("matrix").type.dims[0] or col + 1 < interface.Param("matrix").type.dims[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}

GM_NS_CLOSE
