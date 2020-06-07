#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Matrix transpose.
///
/// Roughly speaking, transposing a matrix flips it across its main diagonal.
///
/// Or, more precisely:
/// - the rows of the original matrix become the columns of the transposed matrix.
/// - for each entry specified by (i, j) in the original matrix, the corresponding entryin the transposed resides in (j, i).

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Transpose the input matrix \p {{ interface.ArgName("matrix") }}.
///
/// \return the transposed matrix.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    return {{ interface.ArgType("matrix").className }}(
{% for row in range(interface.ArgType("matrix").dims[0]) -%}
{% for col in range(interface.ArgType("matrix").dims[1]) -%}
    {{ interface.ArgName("matrix") }}( {{ col }}, {{ row }} )
{% if row + 1 < interface.ArgType("matrix").dims[0] or col + 1 < interface.ArgType("matrix").dims[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}

GM_NS_CLOSE
