#include <catch2/catch.hpp>

#include <gm/functions/quadraticRoots.h>

TEST_CASE( "QuadraticRoots_float" )
{
    {
        // No roots.
        float a = 1.0f;
        float b = -3.0f;
        float c = 4.0f;
        gm::Vec2f roots;
        CHECK( gm::QuadraticRoots( a, b, c, roots ) == 0 );
    }

    {
        // One root.
        float a = -4.0f;
        float b = 12.0f;
        float c = -9.0f;
        gm::Vec2f roots;
        CHECK( gm::QuadraticRoots( a, b, c, roots ) == 1 );
        CHECK( roots[ 0 ] == 1.5f );
    }

    {
        // Two roots.
        float a = 2.0f;
        float b = -11.0f;
        float c = 5.0f;
        gm::Vec2f roots;
        CHECK( gm::QuadraticRoots( a, b, c, roots ) == 2 );
        CHECK( roots[ 0 ] == 0.5f );
        CHECK( roots[ 1 ] == 5.0f );
    }
}
