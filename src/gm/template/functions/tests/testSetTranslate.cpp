#include <catch2/catch.hpp>

#include <gm/functions/setTranslate.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "SetTranslate_Mat3f" )
{
    gm::Mat3f matrix;
    gm::SetIdentity( matrix );
    gm::SetTranslate( gm::Vec2f( 2, 3 ), matrix );
    CHECK( matrix == gm::Mat3f(
        1, 0, 2,
        0, 1, 3,
        0, 0, 1
    ) );
}

TEST_CASE( "SetTranslate_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    gm::SetTranslate( gm::Vec3f( 2, 3, 4 ), matrix );
    CHECK( matrix == gm::Mat4f(
        1, 0, 0, 2,
        0, 1, 0, 3,
        0, 0, 1, 4,
        0, 0, 0, 1
    ) );
}
