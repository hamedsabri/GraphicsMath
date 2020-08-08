//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/hasScale.h>

TEST_CASE( "HasScale_Mat3f" )
{
    gm::Mat3f matrix;
    BENCHMARK( "HasScale" )
    {
        return gm::HasScale( matrix );
    };
}

TEST_CASE( "HasScale_Mat4f" )
{
    gm::Mat4f matrix;
    BENCHMARK( "HasScale" )
    {
        return gm::HasScale( matrix );
    };
}
