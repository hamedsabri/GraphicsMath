//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/radians.h>

TEST_CASE( "Radians_float" )
{
    float angle;
    BENCHMARK( "Radians" )
    {
        return gm::Radians( angle );
    };
}
