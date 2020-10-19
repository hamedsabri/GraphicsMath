#include <catch2/catch.hpp>

#include <gm/functions/perspectiveProjection.h>

TEST_CASE( "PerspectiveProjection" )
{
    {
        gm::Mat4f matrix = gm::PerspectiveProjection( -2, 2, -2, 2, 0.1, 100 );
        gm::Mat4f expectedMatrix(
            0.05, 0,    0,      0,
            0,    0.05, 0,      0,
            0,    0,    -1.002, -0.2002,
            0,    0,    1,      0
        );
        CHECK( matrix == expectedMatrix );
    }

    {
        gm::Mat4f matrix = gm::PerspectiveProjection( /* fov */ 60, /* aspectRatio */ 1.5, 0.1, 100 );
        gm::Mat4f expectedMatrix(
            4, 0,       0,        0.288675,
            0, -8.6188, 0,        0.804145,
            0, 0,       -1.00116, -0.115537,
            0, 0,       1,        0
        );
        CHECK( matrix == expectedMatrix );
    }
}
