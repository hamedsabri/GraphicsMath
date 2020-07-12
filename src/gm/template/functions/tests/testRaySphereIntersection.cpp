#include <catch2/catch.hpp>

#include <gm/functions/normalize.h>
#include <gm/functions/{{ function.headerFileName }}>

TEST_CASE( "RaySphereIntersection_float" )
{
    {
        // No intersections.
        gm::Vec3f sphereOrigin( 0, 0, -1.0f );
        float     sphereRadius = 0.5f;
        gm::Vec3f rayOrigin( 0, 0, 0.0f );
        gm::Vec3f rayDirection( 0, 1.0, -1.0f );
        rayDirection = gm::Normalize( rayDirection );
        gm::FloatRange intersections;
        CHECK( gm::RaySphereIntersection( sphereOrigin, sphereRadius, rayOrigin, rayDirection, intersections ) == 0 );
    }

    {
        // 2 intersection(s).
        gm::Vec3f sphereOrigin( 0, 0, -1.0f );
        float     sphereRadius = 0.5f;
        gm::Vec3f rayOrigin( 0, 0, 0.0f );
        gm::Vec3f rayDirection( 0, 0, -1.0f );
        rayDirection = gm::Normalize( rayDirection );
        gm::FloatRange intersections;
        CHECK( gm::RaySphereIntersection( sphereOrigin, sphereRadius, rayOrigin, rayDirection, intersections ) == 2 );
        CHECK( intersections.Min() == 0.5f );
        CHECK( intersections.Max() == 1.5f );
    }
}
