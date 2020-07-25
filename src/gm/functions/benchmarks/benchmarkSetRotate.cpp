//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setRotate.h>

TEST_CASE( "SetRotate_float_Vec3f_Mat4f" )
{
    float     angle;
    gm::Vec3f axis;
    gm::Mat4f matrix;
    BENCHMARK( "SetRotate" )
    {
        return gm::SetRotate( angle, axis, matrix );
    };
}
