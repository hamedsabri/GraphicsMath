#include <catch2/catch.hpp>

#include <gm/functions/solveQuadraticRoots.h>

TEST_CASE( "SolveQuadraticRoots_float" )
{
    {
        // No roots.
        float a = 1.0f;
        float b = -3.0f;
        float c = 4.0f;
        float firstRoot, secondRoot;
        CHECK( gm::SolveQuadraticRoots( a, b, c, firstRoot, secondRoot ) == 0 );
    }

    {
        // One root.
        float a = -4.0f;
        float b = 12.0f;
        float c = -9.0f;
        float firstRoot, secondRoot;
        CHECK( gm::SolveQuadraticRoots( a, b, c, firstRoot, secondRoot ) == 1 );
        CHECK( firstRoot == 1.5f );
    }

    {
        // Two roots.
        float a = 2.0f;
        float b = -11.0f;
        float c = 5.0f;
        float firstRoot, secondRoot;
        CHECK( gm::SolveQuadraticRoots( a, b, c, firstRoot, secondRoot ) == 2 );
        CHECK( firstRoot == 0.5f );
        CHECK( secondRoot == 5.0f );
    }
}
