//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/linearInterpolation.h>

TEST_CASE( "LinearInterpolation_float_float_float" )
{
    float source;
    float target;
    float weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Mat3f_Mat3f_float" )
{
    gm::Mat3f source;
    gm::Mat3f target;
    float     weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Mat4f_Mat4f_float" )
{
    gm::Mat4f source;
    gm::Mat4f target;
    float     weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec2f_Vec2f_float" )
{
    gm::Vec2f source;
    gm::Vec2f target;
    float     weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec3f_Vec3f_float" )
{
    gm::Vec3f source;
    gm::Vec3f target;
    float     weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec4f_Vec4f_float" )
{
    gm::Vec4f source;
    gm::Vec4f target;
    float     weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec2fRange_Vec2fRange_float" )
{
    gm::Vec2fRange source;
    gm::Vec2fRange target;
    float          weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec3fRange_Vec3fRange_float" )
{
    gm::Vec3fRange source;
    gm::Vec3fRange target;
    float          weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_Vec4fRange_Vec4fRange_float" )
{
    gm::Vec4fRange source;
    gm::Vec4fRange target;
    float          weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}

TEST_CASE( "LinearInterpolation_FloatRange_FloatRange_float" )
{
    gm::FloatRange source;
    gm::FloatRange target;
    float          weight;
    BENCHMARK( "LinearInterpolation" )
    {
        return gm::LinearInterpolation( source, target, weight );
    };
}
