//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/ceil.h>

TEST_CASE( "Ceil_float" )
{
    float value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}

TEST_CASE( "Ceil_Vec2f" )
{
    gm::Vec2f value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}

TEST_CASE( "Ceil_Vec3f" )
{
    gm::Vec3f value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}

TEST_CASE( "Ceil_Vec4f" )
{
    gm::Vec4f value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}

TEST_CASE( "Ceil_Mat3f" )
{
    gm::Mat3f value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}

TEST_CASE( "Ceil_Mat4f" )
{
    gm::Mat4f value;
    BENCHMARK( "Ceil" )
    {
        return gm::Ceil( value );
    };
}
