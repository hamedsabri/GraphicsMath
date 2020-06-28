//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/quadraticRoots.h>

TEST_CASE( "QuadraticRoots_float_float_float_float_float" )
{
    float a;
    float b;
    float c;
    float firstRoot;
    float secondRoot;
    BENCHMARK( "QuadraticRoots" )
    {
        return gm::QuadraticRoots( a, b, c, firstRoot, secondRoot );
    };
}
