#include <catch2/catch.hpp>

#include <gm/functions/setRotateY.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "SetRotateY_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    gm::SetRotateY( 90, matrix );
    CHECK( matrix == gm::Mat4f(
        0,  -1, 0,  0,
        1,  0,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    ) );

    gm::SetRotateY( 45, matrix );
    CHECK( matrix == gm::Mat4f(
        0.707107,  -0.707107, 0, 0,
        0.707107,  0.707107,  0, 0,
        0,         0,         1, 0,
        0,         0,         0, 1
    ) );
}
