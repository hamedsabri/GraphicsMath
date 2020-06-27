#include <catch2/catch.hpp>

#include <gm/functions/normalize.h>
#include <gm/functions/raySphereIntersection.h>

TEST_CASE( "RaySphereIntersection_float" )
{
    {
        // No intersections.
        gm::Vec3f sphereOrigin( 0, 0, -1.0f );
        float     sphereRadius = 0.5f;
        gm::Vec3f rayOrigin( 0, 0, 0.0f );
        gm::Vec3f rayDirection( 0, 1.0, -1.0f );
        rayDirection = gm::Normalize( rayDirection );
        float firstIntersection, secondIntersection;
        CHECK( gm::RaySphereIntersection( sphereOrigin,
                                          sphereRadius,
                                          rayOrigin,
                                          rayDirection,
                                          firstIntersection,
                                          secondIntersection ) == 0 );
    }

    {
        // 2 intersection(s).
        gm::Vec3f sphereOrigin( 0, 0, -1.0f );
        float     sphereRadius = 0.5f;
        gm::Vec3f rayOrigin( 0, 0, 0.0f );
        gm::Vec3f rayDirection( 0, 0, -1.0f );
        rayDirection = gm::Normalize( rayDirection );
        float firstIntersection, secondIntersection;
        CHECK( gm::RaySphereIntersection( sphereOrigin,
                                          sphereRadius,
                                          rayOrigin,
                                          rayDirection,
                                          firstIntersection,
                                          secondIntersection ) == 2 );
        CHECK( firstIntersection == 0.5f );
        CHECK( secondIntersection == 1.5f );
    }
}
