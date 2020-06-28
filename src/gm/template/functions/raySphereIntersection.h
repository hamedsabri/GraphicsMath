#pragma once

/// \file functions/{{ function.headerFileName }}
/// \ingroup GM_group_functions_rayTracing
///
/// Ray sphere intersection test.
///
/// Computes the intersection points between a ray and a sphere.
///
/// \section GM_section_raySphereIntersectionAnalyticProof Analytic proof of Ray Sphere Intersection
///
/// The points along the surface of a 3D sphere (centered at origin) can be defined by the following algebraic equation:
///
/// \f$(1)\f$ \f$x^2+y^2+z^2=R^2\f$
///
/// Such that \f$x\f$, \f$y\f$, and \f$z\f$ are the coordinates of the points along the surface and \f$R\f$ is the
/// radius of the sphere.
///
/// \f$(1)\f$ can be further simplified, by replacement of the sum of squares with the <em>dot product</em> of the
/// surface point:
///
/// \f$(2)\f$ \f$P^2+R^2=0\f$
///
/// The points along the surface of a 3D sphere centered at a arbituary coordinate \f$(c_0,c_1,c_2\f$ can then be written as:
///
/// \f$(3)\f$ \f$(x-c_0)^2+(y-c_1)^2+(z-c_2)^2=R^2\f$
///
/// Applying the same simplication from \f$(1)\f$ to \f$(2)\f$ onto \f$(3)\f$ produces:
///
/// \f$(4)\f$ \f$(P-C)^2-R^2\f$
///
/// Any point \f$P\f$ along a ray is defined by the following function:
///
/// \f$(5)\f$ \f$O+tD=P\f$
///
/// such that \f$O\f$ is the ray origin, \f$D\f$ the ray direction, \f$t\f$ is the ray magnitude.
///
/// Substituting \f$(5)\f$ into \f$(4)\f$ gives:
///
/// \f$(6)\f$ \f$(O+tD-C)^2-R^2=0\f$
///
/// Which can be expanded into:
///
/// \f$(7)\f$ \f$D^2t^2+2(O-C)Dt+(O-C)^2-R^2=0\f$
///
/// Fitting the root quadratic form \f$ax^2+bx+c=0\f$ such that \f$x=t\f$, \f$a=D^2\f$, \f$b=2D(O-C)\f$, and
/// \f$c=(O-C)^2-R^2\f$.
///
/// The roots can be solved, forming the magnitudes which will produce the points of intersection.

#include <gm/gm.h>

#include <gm/base/assert.h>

{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{%- endif %}
{% endfor %}

#include <gm/functions/dotProduct.h>
#include <gm/functions/quadraticRoots.h>
#ifdef GM_DEBUG
#include <gm/functions/length.h>
#endif

GM_NS_OPEN

{% for interface in function.interfaces %}
/// \ingroup GM_group_functions_rayTracing
/// Find the intersection(s) between a ray and a sphere.
///
/// The points of intersection can be computed from the intersection magnitudes
/// \p {{ interface.ArgName("intersections") }} /// via \ref RayPosition.
///
/// Example usage:
/// \code{.cpp}
/// if ( gm::RaySphereIntersection( sphereOrigin,
///                                 sphereRadius,
///                                 rayOrigin,
///                                 rayDirection,
///                                 intersections ) == 2 )
/// {
///     gm::Vec3f firstIntersectionPoint = gm::RayPosition( rayOrigin, rayDirection, intersections[ 0 ] );
///     // ...
/// }
/// \endcode
///
/// \param {{ interface.ArgName("sphereOrigin") }} The origin or center of the sphere.
/// \param {{ interface.ArgName("sphereRadius") }} The radius of the sphere.
/// \param {{ interface.ArgName("rayOrigin") }} The origin of the ray.
/// \param {{ interface.ArgName("rayDirection") }} The direction of the ray.
/// \param {{ interface.ArgName("intersections") }} The magnitudes of the intersections with respect to the ray.
///
/// \return The number of times the ray intersections the sphere.
/// \retval 0 The ray does not intersect the sphere at all.
/// \retval 1 The ray intersects the surface of the sphere exactly.
/// \retval 2 the ray intersects through the volume of the sphere.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    GM_ASSERT_MSG( Length( {{ interface.ArgName("rayDirection") }} ) ==
                   {{ interface.ArgType("rayDirection").CppValue( 1 ) }},
                   "Direction {{ interface.ArgName("rayDirection") }} is not normalised!" );

    // Compute quadratic co-efficients
    Vec3f originDiff = {{ interface.ArgName("rayOrigin") }} - {{ interface.ArgName("sphereOrigin") }};
    float a = DotProduct( {{ interface.ArgName("rayDirection") }}, {{ interface.ArgName("rayDirection") }} );
    float b = 2.0f * DotProduct( {{ interface.ArgName("rayDirection") }}, originDiff );
    float c = DotProduct( originDiff, originDiff ) -
              {{ interface.ArgName("sphereRadius") }} * {{ interface.ArgName("sphereRadius") }};

    // Solve for quadratic roots.
    int numRoots = QuadraticRoots(
        a,
        b,
        c,
        {{ interface.ArgName("intersections") }}
    );

    // Check for number of roots (number of intersections).
    // The conditionals are ordered in terms of likeliness to occur.
    if ( numRoots == 0 )
    {
        // No intersections - immediately return.
        return 0;
    }
    else if ( numRoots == 2 )
    {
        // Two intersections.

        // Store the intersection farther from the ray origin in the second root.
        if ( {{ interface.ArgName("intersections") }}[ 0 ] > {{ interface.ArgName("intersections") }}[ 1 ] )
        {
            std::swap( {{ interface.ArgName("intersections") }}[ 0 ], {{ interface.ArgName("intersections") }}[ 1 ] );
        }

        // Root negative check, as to not intersect with objects behind the ray direction.
        if ( {{ interface.ArgName("intersections") }}[ 0 ] < 0 )
        {
            {{ interface.ArgName("intersections") }}[ 0 ] = {{ interface.ArgName("intersections") }}[ 1 ];
            if ( {{ interface.ArgName("intersections") }}[ 0 ] < 0 )
            {
                // Both roots are negative, count it as no intersection.
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 2;
        }
    }
    else
    {
        // A single intersection.

        if ( {{ interface.ArgName("intersections") }}[ 0 ] < 0 )
        {
            // Do not intersect with spheres opposite of the ray direction.
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
{% endfor %}

GM_NS_CLOSE

