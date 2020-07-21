//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/longestAxis.h>

TEST_CASE( "LongestAxis_Vec2fRange" )
{
    gm::Vec2fRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}

TEST_CASE( "LongestAxis_Vec3fRange" )
{
    gm::Vec3fRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}

TEST_CASE( "LongestAxis_Vec4fRange" )
{
    gm::Vec4fRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}

TEST_CASE( "LongestAxis_Vec2iRange" )
{
    gm::Vec2iRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}

TEST_CASE( "LongestAxis_Vec3iRange" )
{
    gm::Vec3iRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}

TEST_CASE( "LongestAxis_Vec4iRange" )
{
    gm::Vec4iRange range;
    BENCHMARK( "LongestAxis" )
    {
        return gm::LongestAxis( range );
    };
}
