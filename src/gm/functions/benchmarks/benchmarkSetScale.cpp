//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setScale.h>

TEST_CASE( "SetScale_Vec2f_Mat3f" )
{
    gm::Vec2f vector;
    gm::Mat3f matrix;
    BENCHMARK( "SetScale" )
    {
        return gm::SetScale( vector, matrix );
    };
}

TEST_CASE( "SetScale_Vec3f_Mat4f" )
{
    gm::Vec3f vector;
    gm::Mat4f matrix;
    BENCHMARK( "SetScale" )
    {
        return gm::SetScale( vector, matrix );
    };
}
