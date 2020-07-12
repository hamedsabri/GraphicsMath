//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/contains.h>

TEST_CASE( "Contains_FloatRange_float" )
{
    gm::FloatRange container;
    float          containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_FloatRange_FloatRange" )
{
    gm::FloatRange container;
    gm::FloatRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_IntRange_int" )
{
    gm::IntRange container;
    int          containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_IntRange_IntRange" )
{
    gm::IntRange container;
    gm::IntRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec2fRange_Vec2f" )
{
    gm::Vec2fRange container;
    gm::Vec2f      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec2fRange_Vec2fRange" )
{
    gm::Vec2fRange container;
    gm::Vec2fRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec3fRange_Vec3f" )
{
    gm::Vec3fRange container;
    gm::Vec3f      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec3fRange_Vec3fRange" )
{
    gm::Vec3fRange container;
    gm::Vec3fRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec4fRange_Vec4f" )
{
    gm::Vec4fRange container;
    gm::Vec4f      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec4fRange_Vec4fRange" )
{
    gm::Vec4fRange container;
    gm::Vec4fRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec2iRange_Vec2i" )
{
    gm::Vec2iRange container;
    gm::Vec2i      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec2iRange_Vec2iRange" )
{
    gm::Vec2iRange container;
    gm::Vec2iRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec3iRange_Vec3i" )
{
    gm::Vec3iRange container;
    gm::Vec3i      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec3iRange_Vec3iRange" )
{
    gm::Vec3iRange container;
    gm::Vec3iRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec4iRange_Vec4i" )
{
    gm::Vec4iRange container;
    gm::Vec4i      containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}

TEST_CASE( "Contains_Vec4iRange_Vec4iRange" )
{
    gm::Vec4iRange container;
    gm::Vec4iRange containee;
    BENCHMARK( "Contains" )
    {
        return gm::Contains( container, containee );
    };
}
