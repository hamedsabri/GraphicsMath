#include <catch2/catch.hpp>

#include <gm/functions/setScale.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "SetScale_Mat3f" )
{
    gm::Mat3f matrix;
    gm::SetIdentity( matrix );
    gm::SetScale( gm::Vec2f( 2, 3 ), matrix );
    CHECK( matrix == gm::Mat3f(
        2, 0, 0,
        0, 3, 0,
        0, 0, 1
    ) );
}

TEST_CASE( "SetScale_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    gm::SetScale( gm::Vec3f( 2, 3, 4 ), matrix );
    CHECK( matrix == gm::Mat4f(
        2, 0, 0, 0,
        0, 3, 0, 0,
        0, 0, 4, 0,
        0, 0, 0, 1
    ) );
}
