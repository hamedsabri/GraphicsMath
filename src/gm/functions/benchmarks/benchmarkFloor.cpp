//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/floor.h>

TEST_CASE( "Floor_float" )
{
    float value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}

TEST_CASE( "Floor_Vec2f" )
{
    gm::Vec2f value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}

TEST_CASE( "Floor_Vec3f" )
{
    gm::Vec3f value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}

TEST_CASE( "Floor_Vec4f" )
{
    gm::Vec4f value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}

TEST_CASE( "Floor_Mat3f" )
{
    gm::Mat3f value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}

TEST_CASE( "Floor_Mat4f" )
{
    gm::Mat4f value;
    BENCHMARK( "Floor" )
    {
        return gm::Floor( value );
    };
}
