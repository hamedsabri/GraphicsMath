//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/content.h>

TEST_CASE( "Content_FloatRange" )
{
    gm::FloatRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_IntRange" )
{
    gm::IntRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec2fRange" )
{
    gm::Vec2fRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec3fRange" )
{
    gm::Vec3fRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec4fRange" )
{
    gm::Vec4fRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec2iRange" )
{
    gm::Vec2iRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec3iRange" )
{
    gm::Vec3iRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}

TEST_CASE( "Content_Vec4iRange" )
{
    gm::Vec4iRange range;
    BENCHMARK( "Content" )
    {
        return gm::Content( range );
    };
}
