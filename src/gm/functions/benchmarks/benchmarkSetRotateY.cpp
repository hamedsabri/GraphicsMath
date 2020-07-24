//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setRotateY.h>

TEST_CASE( "SetRotateY_float_Mat4f" )
{
    float     angle;
    gm::Mat4f matrix;
    BENCHMARK( "SetRotateY" )
    {
        return gm::SetRotateY( angle, matrix );
    };
}
