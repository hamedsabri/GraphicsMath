//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/orthographicProjection.h>

TEST_CASE( "OrthographicProjection_float_float_float_float_float_float" )
{
    float left;
    float right;
    float bottom;
    float top;
    float near;
    float far;
    BENCHMARK( "OrthographicProjection" )
    {
        return gm::OrthographicProjection( left, right, bottom, top, near, far );
    };
}
