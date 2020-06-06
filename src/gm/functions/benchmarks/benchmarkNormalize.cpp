//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/normalize.h>

TEST_CASE( "Normalize_Vec2f" )
{
    gm::Vec2f vector;
    BENCHMARK( "Normalize" )
    {
        return gm::Normalize( vector );
    };
}

TEST_CASE( "Normalize_Vec3f" )
{
    gm::Vec3f vector;
    BENCHMARK( "Normalize" )
    {
        return gm::Normalize( vector );
    };
}

TEST_CASE( "Normalize_Vec4f" )
{
    gm::Vec4f vector;
    BENCHMARK( "Normalize" )
    {
        return gm::Normalize( vector );
    };
}
