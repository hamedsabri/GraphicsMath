{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Solve for the roots of a quadratic equation of the form \f$ax^2+bx+c=0\f$
///
/// In other words, find the \em intersections of the parabolic function \f$f(x)=ax^2+bx+c\f$ and the X-axis.
///
/// The quadratic formula is as follows:
///
/// \f$x=\frac{-b\pm\sqrt{b^2-4ac}}{2a}\f$
///
/// Such that \f$x\f$ yields the root(s), if any.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/diagnostic.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set coefficientA = interface.ArgName("a") %}
{% set coefficientB = interface.ArgName("b") %}
{% set coefficientC = interface.ArgName("c") %}
{% set roots        = interface.ArgName("roots") %}
/// Solve for the roots of a quadratic equation.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ coefficientA }} The \f$a\f$ co-efficient.
/// \param {{ coefficientB }} The \f$b\f$ co-efficient.
/// \param {{ coefficientC }} The \f$c\f$ co-efficient.
/// \param {{ roots }} the roots, or solutions.  The first element is only defined if the number of roots is \p 1 or \p 2.  The second element is only defined if the number of roots is \p 2.
///
/// \return The number of roots for the quadratic equation.
///
/// \retval 0 No roots.
/// \retval 1 A single intersection by the vertex of the parabola.
/// \retval 2 Two symmetrical intersections with respect to the vertex.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ coefficientA }} != {{ interface.ArgType("a").CppValue(0) }} );

    float discriminant = ( {{ coefficientB }} * {{ coefficientB }} ) -
                         ( 4.0f * {{ coefficientA }} * {{ coefficientC }} );
    if ( discriminant < 0.0f )
    {
        // No intersections.
        return 0;
    }
    else if ( discriminant > 0.0f )
    {
        // Two roots.
        float reciprocal = 1.0f / ( 2.0f * {{ coefficientA }} );
        {{ roots }}[ 0 ] = ( -{{ coefficientB }} + sqrt( discriminant ) ) * reciprocal;
        {{ roots }}[ 1 ] = ( -{{ coefficientB }} - sqrt( discriminant ) ) * reciprocal;
        // Make the smaller root appear first.
        if ( {{ roots }}[ 0 ] > {{ roots }}[ 1 ] )
        {
            std::swap( {{ roots }}[ 0 ], {{ roots }}[ 1 ] );
        }

        return 2;
    }
    else
    {
        // A single root.
        {{ roots }}[ 0 ] = -{{ coefficientB }} / ( 2.0f * {{ coefficientA }} );
        return 1;
    }
}
{% endfor %}
{% endblock %}
