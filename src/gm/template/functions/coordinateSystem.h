{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Construct a local coordinate system from a single input vector.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/normalize.h>
#include <gm/functions/length.h>
#include <gm/functions/crossProduct.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vectorType = interface.ArgType("vectorA") %}
{% set vectorA = interface.ArgName("vectorA") %}
{% set vectorB = interface.ArgName("vectorB") %}
{% set vectorC = interface.ArgName("vectorC") %}
/// Construct a local coordinate system for a single input vector \p {{ vectorA }}, by computing
/// two orthogonal output vectors \p {{ vectorB }} and \p {{ vectorC }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ vectorA }} Input 3D vector.
/// \param {{ vectorB }} The first orthogonal output 3D vector.
/// \param {{ vectorC }} The second orthogonal output 3D vector.
///
/// \return Cross product of the two vectors.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( AlmostEqual( Length( {{ vectorA }} ),
                                {{ interface.ArgType("vectorA").CppValue( 1 ) }} ),
                   "Vector {{ vectorA }} is not normalised!" );

    // The first orthogonal output vector is computed by:
    // 1. Zeroing out one of the components.
    // 2. Swapping the other ones.
    // 3. Negating one of the swapped components.
    if ( std::abs( {{ vectorA }}.X() ) > std::abs( {{ vectorA }}.Y() ) )
    {
        {{ vectorB }} = {{ vectorType.className }}( -{{ vectorA }}.Z(), 0, {{ vectorA }}.X() );
    }
    else
    {
        {{ vectorB }} = {{vectorType.className}}( 0, {{ vectorA }}.Z(), -{{ vectorA }}.Y() );
    }
    {{ vectorB }} = Normalize( {{ vectorB }} );

    // Compute the second orthogonal as the cross product of A and B.
    {{ vectorC }} = CrossProduct( {{ vectorA }}, {{ vectorB }} );
}
{% endfor %}
{% endblock %}
