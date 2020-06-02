//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/dotProduct.h>

TEST_CASE( "DotProduct_Vec2f_Vec2f" )
{
    gm::Vec2f lhs;
    gm::Vec2f rhs;
    BENCHMARK( "DotProduct" )
    {
        return gm::DotProduct( lhs, rhs );
    };
}

TEST_CASE( "DotProduct_Vec3f_Vec3f" )
{
    gm::Vec3f lhs;
    gm::Vec3f rhs;
    BENCHMARK( "DotProduct" )
    {
        return gm::DotProduct( lhs, rhs );
    };
}

TEST_CASE( "DotProduct_Vec4f_Vec4f" )
{
    gm::Vec4f lhs;
    gm::Vec4f rhs;
    BENCHMARK( "DotProduct" )
    {
        return gm::DotProduct( lhs, rhs );
    };
}
