//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/solveQuadraticRoots.h>

TEST_CASE( "SolveQuadraticRoots_float_float_float_float_float" )
{
    float a;
    float b;
    float c;
    float firstRoot;
    float secondRoot;
    BENCHMARK( "SolveQuadraticRoots" )
    {
        return gm::SolveQuadraticRoots( a, b, c, firstRoot, secondRoot );
    };
}
