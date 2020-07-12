{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Ray axis-aligned bounding box (AABB) intersection test.
///
/// \section gm_section_rayABBIntersection1DProof Solving Ray AABB intersection in one dimension
///
/// Any position \f$P\f$ along a ray is defined by the following function:
///
/// \f$(1)\f$ \f$P(t)=O+tD\f$
///
/// such that \f$O\f$ is the ray origin, \f$D\f$ the ray direction, \f$t\f$ is a zero or positive ray magnitude.
///
/// An one-dimensional AABB could be thought of as a line segment with minimum and maximum endpoints \f$(X_0,X_1)\f$.
///
/// The ray AABB intersections are the ray positions such that \f$P(t)\in{X_0,X_1}\f$.
///
/// Both unknown \f$t\f$ can be computed in the following equations:
///
/// \f$X_0=O+t_0D\f$, thus \f$t_0=\frac{X_0-O}{D}\f$
///
/// \f$X_1=O+t_1D\f$, thus \f$t_1=\frac{X_1-O}{D}\f$
///
/// If both \f$t_0\f$ and \f$t_1\f$ equates to \f$0\f$ negative numbers, then there is no intersection.
///
/// Substituting either \f$t\f$ into \f$(1)\f$ should produced the associated endpoint.
///
/// \section gm_section_rayABBIntersectionExtension Solving Ray AABB intersection in N dimensions
///
/// By using the applying 1D solution in each axis, we obtain the min and max ray magnitudes
/// which intersects the AABB on its respective axis.
///
/// For the ray to intersect the AABB in N dimensions, each of the axis intersections much overlap
/// with one another.

{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/assert.h>
#ifdef GM_DEBUG
#include <gm/base/almost.h>
#include <gm/functions/length.h>
#endif
#include <gm/functions/rayPosition.h>
#include <gm/functions/intersection.h>
#include <gm/functions/min.h>
#include <gm/functions/max.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Check if a ray intersects a axis-aligned bounding box (AABB).
///
/// \param {{ interface.ArgName("rayOrigin") }} The origin of the ray.
/// \param {{ interface.ArgName("rayDirection") }} The direction of the ray.
/// \param {{ interface.ArgName("aabb") }} The axis-aligned bounding box.
/// \param {{ interface.ArgName("intersections") }} The output ray magnitudes intersecting the AABB.
/// If there are no intersections, then {{ interface.ArgName("intersections") }} will be undefined.
///
/// \retval true The ray intersects the AABB.
/// \retval false The ray does not intersect the AABB.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT_MSG( AlmostEqual( Length( {{ interface.ArgName("rayDirection") }} ),
                                {{ interface.ArgType("rayDirection").CppValue( 1 ) }} ),
                   "Direction {{ interface.ArgName("rayDirection") }} is not normalised!" );

    // Initialize intersection magnitudes to ray limits.
    {{ interface.ArgName("intersections") }}.Min() = 0.0f;
    {{ interface.ArgName("intersections") }}.Max() =
        std::numeric_limits< {{ interface.ArgType("intersections").elementType.className }} >::max();

{% for axis in range(interface.ArgType("rayDirection").elementSize) -%}
    // Compute local minimum & maximum magnitudes for axis {{ axis }}, to intersect (find overlap)
    // against other axis.
    {
        {{ interface.ArgType("rayDirection").elementType.className }} inverseAxisDir =
            {{ interface.ArgType("rayDirection").elementType.CppValue(1.0) }} /
            {{ interface.ArgName("rayDirection") }}[ {{ axis }} ];

        gm::{{ interface.ArgClass("intersections") }} axisIntersections(
            ( {{ interface.ArgName("aabb") }}.Min()[ {{ axis }} ] -
              {{ interface.ArgName("rayOrigin") }}[ {{ axis }} ] ) * inverseAxisDir,
            ( {{ interface.ArgName("aabb") }}.Max()[ {{ axis }} ] -
              {{ interface.ArgName("rayOrigin") }}[ {{ axis }} ] ) * inverseAxisDir
        );

        // Handle negative ray direction on this particular axis.
        if ( inverseAxisDir < {{ interface.ArgType("rayDirection").elementType.CppValue(0) }} )
        {
            std::swap( axisIntersections.Min(), axisIntersections.Max() );
        }

        // Find the intersection of the local axis and global magnitudes.  This "narrows" the bounded region.
        {{ interface.ArgName("intersections") }} = gm::Intersection(
            {{ interface.ArgName("intersections") }},
            axisIntersections
        );

        // If there is no overlap, then intersections will be empty.
        if ( {{ interface.ArgName("intersections") }}.IsEmpty() )
        {
            return false;
        }
    }

{% endfor-%}

    return true;
}
{% endfor %}
{% endblock %}
