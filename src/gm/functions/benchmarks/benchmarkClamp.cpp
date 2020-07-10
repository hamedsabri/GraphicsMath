//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/clamp.h>

TEST_CASE( "Clamp_float_FloatRange" )
{
    float          value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_int_IntRange" )
{
    int          value;
    gm::IntRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec2f_FloatRange" )
{
    gm::Vec2f      value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec3f_FloatRange" )
{
    gm::Vec3f      value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec4f_FloatRange" )
{
    gm::Vec4f      value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec2i_IntRange" )
{
    gm::Vec2i    value;
    gm::IntRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec3i_IntRange" )
{
    gm::Vec3i    value;
    gm::IntRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Vec4i_IntRange" )
{
    gm::Vec4i    value;
    gm::IntRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Mat3f_FloatRange" )
{
    gm::Mat3f      value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}

TEST_CASE( "Clamp_Mat4f_FloatRange" )
{
    gm::Mat4f      value;
    gm::FloatRange range;
    BENCHMARK( "Clamp" )
    {
        return gm::Clamp( value, range );
    };
}
