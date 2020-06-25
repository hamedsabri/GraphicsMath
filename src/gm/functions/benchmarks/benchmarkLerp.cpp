//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/lerp.h>

TEST_CASE( "Lerp_float_float_float" )
{
    float valueA;
    float valueB;
    float weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}

TEST_CASE( "Lerp_Mat3f_Mat3f_float" )
{
    gm::Mat3f valueA;
    gm::Mat3f valueB;
    float     weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}

TEST_CASE( "Lerp_Mat4f_Mat4f_float" )
{
    gm::Mat4f valueA;
    gm::Mat4f valueB;
    float     weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}

TEST_CASE( "Lerp_Vec2f_Vec2f_float" )
{
    gm::Vec2f valueA;
    gm::Vec2f valueB;
    float     weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}

TEST_CASE( "Lerp_Vec3f_Vec3f_float" )
{
    gm::Vec3f valueA;
    gm::Vec3f valueB;
    float     weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}

TEST_CASE( "Lerp_Vec4f_Vec4f_float" )
{
    gm::Vec4f valueA;
    gm::Vec4f valueB;
    float     weight;
    BENCHMARK( "Lerp" )
    {
        return gm::Lerp( valueA, valueB, weight );
    };
}
