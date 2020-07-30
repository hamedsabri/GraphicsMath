//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/transformPoint.h>

TEST_CASE( "TransformPoint_Mat4f_Vec3f" )
{
    gm::Mat4f matrix;
    gm::Vec3f point;
    BENCHMARK( "TransformPoint" )
    {
        return gm::TransformPoint( matrix, point );
    };
}
