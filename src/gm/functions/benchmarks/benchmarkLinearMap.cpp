//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/linearMap.h>

TEST_CASE( "LinearMap_float_Vec2f_Vec2f" )
{
    float     sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Mat3f_Vec2f_Vec2f" )
{
    gm::Mat3f sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Mat4f_Vec2f_Vec2f" )
{
    gm::Mat4f sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec2f_Vec2f_Vec2f" )
{
    gm::Vec2f sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec3f_Vec2f_Vec2f" )
{
    gm::Vec3f sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec4f_Vec2f_Vec2f" )
{
    gm::Vec4f sourceValue;
    gm::Vec2f sourceRange;
    gm::Vec2f targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}
