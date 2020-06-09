//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setTranslate.h>

TEST_CASE( "SetTranslate_Vec2f_Mat3f" )
{
    gm::Vec2f vector;
    gm::Mat3f matrix;
    BENCHMARK( "SetTranslate" )
    {
        return gm::SetTranslate( vector, matrix );
    };
}

TEST_CASE( "SetTranslate_Vec3f_Mat4f" )
{
    gm::Vec3f vector;
    gm::Mat4f matrix;
    BENCHMARK( "SetTranslate" )
    {
        return gm::SetTranslate( vector, matrix );
    };
}
