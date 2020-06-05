//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/distance.h>

TEST_CASE( "Distance_Vec2f_Vec2f" )
{
    gm::Vec2f pointA;
    gm::Vec2f pointB;
    BENCHMARK( "Distance" )
    {
        return gm::Distance( pointA, pointB );
    };
}

TEST_CASE( "Distance_Vec3f_Vec3f" )
{
    gm::Vec3f pointA;
    gm::Vec3f pointB;
    BENCHMARK( "Distance" )
    {
        return gm::Distance( pointA, pointB );
    };
}
