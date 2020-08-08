//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/expand.h>

TEST_CASE( "Expand_FloatRange_FloatRange" )
{
    gm::FloatRange lhs;
    gm::FloatRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_FloatRange_float" )
{
    gm::FloatRange lhs;
    float          rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_IntRange_IntRange" )
{
    gm::IntRange lhs;
    gm::IntRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_IntRange_int" )
{
    gm::IntRange lhs;
    int          rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec2fRange_Vec2fRange" )
{
    gm::Vec2fRange lhs;
    gm::Vec2fRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec2fRange_Vec2f" )
{
    gm::Vec2fRange lhs;
    gm::Vec2f      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec3fRange_Vec3fRange" )
{
    gm::Vec3fRange lhs;
    gm::Vec3fRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec3fRange_Vec3f" )
{
    gm::Vec3fRange lhs;
    gm::Vec3f      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec4fRange_Vec4fRange" )
{
    gm::Vec4fRange lhs;
    gm::Vec4fRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec4fRange_Vec4f" )
{
    gm::Vec4fRange lhs;
    gm::Vec4f      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec2iRange_Vec2iRange" )
{
    gm::Vec2iRange lhs;
    gm::Vec2iRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec2iRange_Vec2i" )
{
    gm::Vec2iRange lhs;
    gm::Vec2i      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec3iRange_Vec3iRange" )
{
    gm::Vec3iRange lhs;
    gm::Vec3iRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec3iRange_Vec3i" )
{
    gm::Vec3iRange lhs;
    gm::Vec3i      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec4iRange_Vec4iRange" )
{
    gm::Vec4iRange lhs;
    gm::Vec4iRange rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}

TEST_CASE( "Expand_Vec4iRange_Vec4i" )
{
    gm::Vec4iRange lhs;
    gm::Vec4i      rhs;
    BENCHMARK( "Expand" )
    {
        return gm::Expand( lhs, rhs );
    };
}
