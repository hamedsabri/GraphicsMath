#include <catch2/catch.hpp>

#include <gm/functions/setRotate.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "{{ function.name }}_Mat4f" )
{
    gm::Mat4f matrix;

    // X-axis
    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 90, gm::Vec3f( 1, 0, 0 ), matrix );
    CHECK( matrix == gm::Mat4f(
        1, 0,  0,  0,
        0, 0,  -1, 0,
        0, 1,  0,  0,
        0, 0,  0,  1
    ) );

    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 45, gm::Vec3f( 1, 0, 0 ), matrix );
    CHECK( matrix == gm::Mat4f(
        1, 0,          0,        0,
        0, 0.707107,  -0.707107, 0,
        0, 0.707107,   0.707107, 0,
        0, 0,          0,        1
    ) );

    // Y-axis
    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 90, gm::Vec3f( 0, 1, 0 ), matrix );
    CHECK( matrix == gm::Mat4f(
        0,  0,  1,  0,
        0,  1,  0,  0,
        -1, 0,  0, 0,
        0,  0,  0,  1
    ) );

    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 45, gm::Vec3f( 0, 1, 0 ), matrix );
    CHECK( matrix == gm::Mat4f(
        0.707107,  0, 0.707107, 0,
        0,         1, 0,        0,
        -0.707107, 0, 0.707107, 0,
        0,         0, 0,        1
    ) );

    // Z-axis
    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 90, gm::Vec3f( 0, 0, 1 ), matrix );
    CHECK( matrix == gm::Mat4f(
        0,  -1, 0,  0,
        1,  0,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    ) );

    gm::SetIdentity( matrix );
    gm::{{ function.name }}( 45, gm::Vec3f( 0, 0, 1 ), matrix );
    CHECK( matrix == gm::Mat4f(
        0.707107,  -0.707107, 0, 0,
        0.707107,  0.707107,  0, 0,
        0,         0,         1, 0,
        0,         0,         0, 1
    ) );
}
