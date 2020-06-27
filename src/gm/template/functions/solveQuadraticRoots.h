#pragma once

/// \file functions/{{ function.headerFileName }}
///
/// Solve for the roots of a quadratic equation of the form \f$ax^2+bx+c=0\f$
///
/// In other words, find the \em intersections of the parabolic function \f$f(x)=ax^2+bx+c\f$ and the X-axis.
///
/// The quadratic formula is as follows:
///
/// \f$x=\frac{-b\pm\sqrt{b^2-4ac}}{2a}\f$
///
/// Such that \f$x\f$ yields the root(s), if any.

#include <gm/gm.h>

#include <gm/base/assert.h>

GM_NS_OPEN

{% for interface in function.interfaces %}
/// Solve for the roots of a quadratic equation.
///
/// \param {{ interface.ArgName("a") }} The \f$a\f$ co-efficient.
/// \param {{ interface.ArgName("b") }} The \f$b\f$ co-efficient.
/// \param {{ interface.ArgName("c") }} The \f$c\f$ co-efficient.
/// \param {{ interface.ArgName("firstRoot") }} the first root. This value is only defined if the number of roots is \p 1 or \p 2.
/// \param {{ interface.ArgName("secondRoot") }} the second root. This value is only defined if the number of roots is \p 2.
///
/// \return The number of roots for the quadratic equation.
///
/// \retval 0 No roots.
/// \retval 1 A single intersection by the vertex of the parabola.
/// \retval 2 Two symmetrical intersections with respect to the vertex.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    GM_ASSERT( {{ interface.ArgName("a") }} != {{ interface.ArgType("a").CppValue(0) }} );

    float discriminant = ( {{ interface.ArgName("b") }} * {{ interface.ArgName("b") }} ) -
                         ( 4.0f * {{ interface.ArgName("a") }} * {{ interface.ArgName("c") }} );
    if ( discriminant < 0.0f )
    {
        // No intersections.
        return 0;
    }
    else if ( discriminant > 0.0f )
    {
        // Two roots.
        float reciprocal = 1.0f / ( 2.0f * {{ interface.ArgName("a") }} );
        {{ interface.ArgName("firstRoot") }} = ( -{{ interface.ArgName("b") }} + sqrt( discriminant ) ) * reciprocal;
        {{ interface.ArgName("secondRoot") }} = ( -{{ interface.ArgName("b") }} - sqrt( discriminant ) ) * reciprocal;
        // Make the smaller root appear first.
        if ( {{ interface.ArgName("firstRoot") }} > {{ interface.ArgName("firstRoot") }} )
        {
            std::swap( {{ interface.ArgName("firstRoot") }}, {{ interface.ArgName("firstRoot") }} );
        }

        return 2;
    }
    else
    {
        // A single root.
        {{ interface.ArgName("firstRoot") }} = -{{ interface.ArgName("b") }} / ( 2.0f * {{ interface.ArgName("a") }} );
        return 1;
    }
}
{% endfor %}

GM_NS_CLOSE
