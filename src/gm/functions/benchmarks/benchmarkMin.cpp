//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/min.h>

TEST_CASE( "Min_float_float" )
{
    float valueA;
    float valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_int_int" )
{
    int valueA;
    int valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_bool_bool" )
{
    bool valueA;
    bool valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Mat3f_Mat3f" )
{
    gm::Mat3f valueA;
    gm::Mat3f valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Mat4f_Mat4f" )
{
    gm::Mat4f valueA;
    gm::Mat4f valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec2f_Vec2f" )
{
    gm::Vec2f valueA;
    gm::Vec2f valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec3f_Vec3f" )
{
    gm::Vec3f valueA;
    gm::Vec3f valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec4f_Vec4f" )
{
    gm::Vec4f valueA;
    gm::Vec4f valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec2i_Vec2i" )
{
    gm::Vec2i valueA;
    gm::Vec2i valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec3i_Vec3i" )
{
    gm::Vec3i valueA;
    gm::Vec3i valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}

TEST_CASE( "Min_Vec4i_Vec4i" )
{
    gm::Vec4i valueA;
    gm::Vec4i valueB;
    BENCHMARK( "Min" )
    {
        return gm::Min( valueA, valueB );
    };
}
