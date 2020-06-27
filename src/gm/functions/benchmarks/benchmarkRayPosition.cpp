//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/rayPosition.h>

TEST_CASE( "RayPosition_Vec2f_Vec2f_float" )
{
    gm::Vec2f origin;
    gm::Vec2f direction;
    float     magnitude;
    BENCHMARK( "RayPosition" )
    {
        return gm::RayPosition( origin, direction, magnitude );
    };
}

TEST_CASE( "RayPosition_Vec3f_Vec3f_float" )
{
    gm::Vec3f origin;
    gm::Vec3f direction;
    float     magnitude;
    BENCHMARK( "RayPosition" )
    {
        return gm::RayPosition( origin, direction, magnitude );
    };
}
