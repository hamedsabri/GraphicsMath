#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>
#include <gm/functions/normalize.h>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("aabb") }}" )
{
    // Bounding volume.
    gm::{{ interface.ArgClass("aabb") }} aabb =
        {{- typeUtils.GenRange( interface.ArgType("aabb"), -2, 2 ) -}};

{% for scaleFactor in [-1, 1] -%}
    // -------------------------------------------------------------------------
    // Test values with applied scaling factor of {{ scaleFactor }}.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenUniformSequence(interface.ArgType("rayOrigin"), -4 * scaleFactor) -}},
            /* rayDirection */ gm::Normalize( {{- typeUtils.GenUniformSequence(interface.ArgType("rayDirection"), 1 * scaleFactor) -}} ),
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }

    // Ray origin inside aabb.
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayOrigin"), -1 * scaleFactor) -}},
            /* rayDirection */ gm::Normalize( {{- typeUtils.GenUniformSequence(interface.ArgType("rayDirection"), 1 * scaleFactor) -}} ),
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }

    // Skim intersection
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayOrigin"), -4 * scaleFactor) -}},
            /* rayDirection */ gm::Normalize( {{- typeUtils.GenUniformSequence(interface.ArgType("rayDirection"), 1 * scaleFactor) -}} ),
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }

    // No intersection.
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( !gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayOrigin"), -5 * scaleFactor) -}},
            /* rayDirection */ gm::Normalize( {{- typeUtils.GenUniformSequence(interface.ArgType("rayDirection"), 1 * scaleFactor) -}} ),
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayOrigin"), -4 * scaleFactor) -}},
            /* rayDirection */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayDirection"), 1 * scaleFactor) -}},
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }

    // No intersection.
    {
        gm::{{ interface.ArgClass("intersections") }} intersections;
        CHECK( !gm::{{ function.name }}(
            /* rayOrigin */ {{- typeUtils.GenUniformSequence(interface.ArgType("rayOrigin"), -4 * scaleFactor) -}},
            /* rayDirection */ {{- typeUtils.GenLeadingValue(interface.ArgType("rayDirection"), 1 * scaleFactor) -}},
            /* aabb */ aabb,
            /* intersections */ intersections )
        );
    }
{%- endfor %}
}
{% endfor %}
