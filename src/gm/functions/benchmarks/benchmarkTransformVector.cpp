//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/transformVector.h>

TEST_CASE( "TransformVector_Mat3f_Vec2f" )
{
    gm::Mat3f matrix;
    gm::Vec2f vector;
    BENCHMARK( "TransformVector" )
    {
        return gm::TransformVector( matrix, vector );
    };
}

TEST_CASE( "TransformVector_Mat4f_Vec3f" )
{
    gm::Mat4f matrix;
    gm::Vec3f vector;
    BENCHMARK( "TransformVector" )
    {
        return gm::TransformVector( matrix, vector );
    };
}
