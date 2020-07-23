//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setRotateX.h>

TEST_CASE( "SetRotateX_float_Mat4f" )
{
    float     angle;
    gm::Mat4f matrix;
    BENCHMARK( "SetRotateX" )
    {
        return gm::SetRotateX( angle, matrix );
    };
}
