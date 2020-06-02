//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/length.h>

TEST_CASE( "Length_Vec2f" )
{
    gm::Vec2f vector;
    BENCHMARK( "Length" )
    {
        return gm::Length( vector );
    };
}

TEST_CASE( "Length_Vec3f" )
{
    gm::Vec3f vector;
    BENCHMARK( "Length" )
    {
        return gm::Length( vector );
    };
}

TEST_CASE( "Length_Vec4f" )
{
    gm::Vec4f vector;
    BENCHMARK( "Length" )
    {
        return gm::Length( vector );
    };
}
