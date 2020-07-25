#include <catch2/catch.hpp>

#include <gm/functions/setRotateZ.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "{{ function.name }}_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 90, matrix );
    CHECK( matrix == gm::Mat4f(
        0,  -1, 0,  0,
        1,  0,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    ) );

    gm::{{ function.name }}( 45, matrix );
    CHECK( matrix == gm::Mat4f(
        0.707107,  -0.707107, 0, 0,
        0.707107,  0.707107,  0, 0,
        0,         0,         1, 0,
        0,         0,         0, 1
    ) );
}
