//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/transpose.h>

TEST_CASE( "Transpose_Mat3f" )
{
    gm::Mat3f matrix;
    BENCHMARK( "Transpose" )
    {
        return gm::Transpose( matrix );
    };
}

TEST_CASE( "Transpose_Mat4f" )
{
    gm::Mat4f matrix;
    BENCHMARK( "Transpose" )
    {
        return gm::Transpose( matrix );
    };
}
