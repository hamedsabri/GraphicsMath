//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/inverse.h>

TEST_CASE( "Inverse_Mat4f_Mat4f" )
{
    gm::Mat4f matrix;
    gm::Mat4f inverse;
    BENCHMARK( "Inverse" )
    {
        return gm::Inverse( matrix, inverse );
    };
}
