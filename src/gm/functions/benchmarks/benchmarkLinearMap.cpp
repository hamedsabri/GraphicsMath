//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/linearMap.h>

TEST_CASE( "LinearMap_float_FloatRange_FloatRange" )
{
    float          sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Mat3f_FloatRange_FloatRange" )
{
    gm::Mat3f      sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Mat4f_FloatRange_FloatRange" )
{
    gm::Mat4f      sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec2f_FloatRange_FloatRange" )
{
    gm::Vec2f      sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec3f_FloatRange_FloatRange" )
{
    gm::Vec3f      sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}

TEST_CASE( "LinearMap_Vec4f_FloatRange_FloatRange" )
{
    gm::Vec4f      sourceValue;
    gm::FloatRange sourceRange;
    gm::FloatRange targetRange;
    BENCHMARK( "LinearMap" )
    {
        return gm::LinearMap( sourceValue, sourceRange, targetRange );
    };
}
