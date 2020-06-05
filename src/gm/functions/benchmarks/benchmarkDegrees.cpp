//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/degrees.h>

TEST_CASE( "Degrees_float" )
{
    float angle;
    BENCHMARK( "Degrees" )
    {
        return gm::Degrees( angle );
    };
}
