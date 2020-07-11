//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/intersection.h>

TEST_CASE( "Intersection_FloatRange_FloatRange" )
{
    gm::FloatRange lhs;
    gm::FloatRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_IntRange_IntRange" )
{
    gm::IntRange lhs;
    gm::IntRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec2fRange_Vec2fRange" )
{
    gm::Vec2fRange lhs;
    gm::Vec2fRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec3fRange_Vec3fRange" )
{
    gm::Vec3fRange lhs;
    gm::Vec3fRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec4fRange_Vec4fRange" )
{
    gm::Vec4fRange lhs;
    gm::Vec4fRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec2iRange_Vec2iRange" )
{
    gm::Vec2iRange lhs;
    gm::Vec2iRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec3iRange_Vec3iRange" )
{
    gm::Vec3iRange lhs;
    gm::Vec3iRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}

TEST_CASE( "Intersection_Vec4iRange_Vec4iRange" )
{
    gm::Vec4iRange lhs;
    gm::Vec4iRange rhs;
    BENCHMARK( "Intersection" )
    {
        return gm::Intersection( lhs, rhs );
    };
}
