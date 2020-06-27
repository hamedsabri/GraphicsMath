//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/raySphereIntersection.h>

TEST_CASE( "RaySphereIntersection_Vec3f_float_Vec3f_Vec3f_float_float" )
{
    gm::Vec3f sphereOrigin;
    float     sphereRadius;
    gm::Vec3f rayOrigin;
    gm::Vec3f rayDirection;
    float     firstIntersection;
    float     secondIntersection;
    BENCHMARK( "RaySphereIntersection" )
    {
        return gm::RaySphereIntersection( sphereOrigin,
                                          sphereRadius,
                                          rayOrigin,
                                          rayDirection,
                                          firstIntersection,
                                          secondIntersection );
    };
}
