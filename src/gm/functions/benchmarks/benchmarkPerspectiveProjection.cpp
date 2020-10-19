//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/perspectiveProjection.h>

TEST_CASE( "PerspectiveProjection_float_float_float_float_float_float" )
{
    float left;
    float right;
    float bottom;
    float top;
    float near;
    float far;
    BENCHMARK( "PerspectiveProjection" )
    {
        return gm::PerspectiveProjection( left, right, bottom, top, near, far );
    };
}

TEST_CASE( "PerspectiveProjection_float_float_float_float" )
{
    float fieldOfView;
    float aspectRatio;
    float near;
    float far;
    BENCHMARK( "PerspectiveProjection" )
    {
        return gm::PerspectiveProjection( fieldOfView, aspectRatio, near, far );
    };
}
