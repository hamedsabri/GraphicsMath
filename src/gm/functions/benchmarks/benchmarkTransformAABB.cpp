//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/transformAABB.h>

TEST_CASE( "TransformAABB_Mat4f_Vec3fRange" )
{
    gm::Mat4f      matrix;
    gm::Vec3fRange aabb;
    BENCHMARK( "TransformAABB" )
    {
        return gm::TransformAABB( matrix, aabb );
    };
}
