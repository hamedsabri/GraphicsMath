//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/raySphereIntersection.h>

TEST_CASE( "RaySphereIntersection_Vec3f_float_Vec3f_Vec3f_Vec2f" )
{
    gm::Vec3f sphereOrigin;
    float     sphereRadius;
    gm::Vec3f rayOrigin;
    gm::Vec3f rayDirection;
    gm::Vec2f intersections;
    BENCHMARK( "RaySphereIntersection" )
    {
        return gm::RaySphereIntersection( sphereOrigin, sphereRadius, rayOrigin, rayDirection, intersections );
    };
}
