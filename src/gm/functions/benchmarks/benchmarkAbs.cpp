//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/abs.h>

TEST_CASE( "Abs_float" )
{
    float value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}

TEST_CASE( "Abs_Vec2f" )
{
    gm::Vec2f value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}

TEST_CASE( "Abs_Vec3f" )
{
    gm::Vec3f value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}

TEST_CASE( "Abs_Vec4f" )
{
    gm::Vec4f value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}

TEST_CASE( "Abs_Mat3f" )
{
    gm::Mat3f value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}

TEST_CASE( "Abs_Mat4f" )
{
    gm::Mat4f value;
    BENCHMARK( "Abs" )
    {
        return gm::Abs( value );
    };
}
