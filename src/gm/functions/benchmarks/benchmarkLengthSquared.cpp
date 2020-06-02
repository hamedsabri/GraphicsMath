//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/lengthSquared.h>

TEST_CASE( "LengthSquared_Vec2f" )
{
    gm::Vec2f vector;
    BENCHMARK( "LengthSquared" )
    {
        return gm::LengthSquared( vector );
    };
}

TEST_CASE( "LengthSquared_Vec3f" )
{
    gm::Vec3f vector;
    BENCHMARK( "LengthSquared" )
    {
        return gm::LengthSquared( vector );
    };
}

TEST_CASE( "LengthSquared_Vec4f" )
{
    gm::Vec4f vector;
    BENCHMARK( "LengthSquared" )
    {
        return gm::LengthSquared( vector );
    };
}
