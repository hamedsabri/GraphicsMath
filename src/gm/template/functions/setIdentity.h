#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup gm_functions_linearAlgebra
///
/// Set the \em identity matrix \f$I\f$, defined as the neutral element with respect to matrix multiplication:
/// \f[ AI=A\f]
/// \f[ A=\textnormal{Any matrix}\neq0 \f]
/// \f[ I=\textnormal{Identity matrix} \f]
///
/// The identity matrix is square(\f$M\textnormal{x}N\f$) with \f$1\f$s down the main diagonal,
/// and \f$0\f$s for all other entries.
/// \f[
/// \begin{bmatrix}
/// 1      & 0      & \cdots  &        & 0      \\
/// 0      & 1      &         &        &        \\
/// \vdots &        & \ddots  &        & \vdots \\
///        &        &         & 1      & 0      \\
/// 0      &        & \cdots  & 0      & 1
/// \end{bmatrix}
/// \f]
///

#include <gm/gm.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Set the identity matrix onto \p {{ interface.ArgName("matrix") }}.
/// \ingroup gm_functions_linearAlgebra
///
/// \param {{ interface.ArgName("matrix") }} the matrix to set to the identity.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    {{ interface.ArgName("matrix") }} = {{ interface.ArgClass("matrix") }}(
{% for row in range(interface.Arg("matrix").type.dims[0]) -%}
{% for col in range(interface.Arg("matrix").type.dims[1]) -%}
{% if row == col -%}
    {{ interface.Arg("matrix").type.CppValue( 1 ) }}
{%- else -%}
    {{ interface.Arg("matrix").type.CppValue( 0 ) }}
{%- endif %}
{% if row + 1 < interface.Arg("matrix").type.dims[0] or col + 1 < interface.Arg("matrix").type.dims[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
    );
}
{% endfor %}

GM_NS_CLOSE
