#include <catch2/catch.hpp>

#include <gm/functions/orthographicProjection.h>

TEST_CASE( "OrthographicProjection" )
{
    {
        gm::Mat4f matrix = gm::OrthographicProjection( -2, 2, -2, 2, -2, 2 );
        gm::Mat4f expectedMatrix(
            0.5, 0,   0,   0,
            0,   0.5, 0,   0,
            0,   0,   0.5, 0,
            0,   0,   0,   1
        );
        CHECK( matrix == expectedMatrix );
    }

    {
        gm::Mat4f matrix = gm::OrthographicProjection( -1, 3, -1, 3, -1, 3 );
        gm::Mat4f expectedMatrix(
            0.5, 0,   0,   -0.5,
            0,   0.5, 0,   -0.5,
            0,   0,   0.5, -0.5,
            0,   0,   0,   1
        );
        CHECK( matrix == expectedMatrix );
    }
}
