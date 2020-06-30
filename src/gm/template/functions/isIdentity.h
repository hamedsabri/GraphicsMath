#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup gm_functions_linearAlgebra
///
/// Check if the input matrix is the identity matrix.

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Check if the matrix \p {{ interface.ArgName("matrix") }} is the identity matrix.
/// \ingroup gm_functions_linearAlgebra
///
/// \return true if \p {{ interface.ArgName("matrix") }} is the identity matrix.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    return
{% for row in range(interface.Arg("matrix").type.dims[0]) -%}
{% for col in range(interface.Arg("matrix").type.dims[1]) -%}
{% if row == col -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) == {{ interface.Arg("matrix").type.CppValue( 1 ) }}
{%- else -%}
    {{ interface.ArgName("matrix") }}( {{ row }}, {{ col }} ) == {{ interface.Arg("matrix").type.CppValue( 0 ) }}
{%- endif %}
{% if row + 1 < interface.Arg("matrix").type.dims[0] or col + 1 < interface.Arg("matrix").type.dims[ 1 ] -%}
    &&
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    ;
}
{% endfor %}

GM_NS_CLOSE
