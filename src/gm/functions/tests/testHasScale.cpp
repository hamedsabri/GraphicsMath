//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/hasScale.h>
#include <gm/functions/setScale.h>

TEST_CASE( "HasScale_Mat3f" )
{
    gm::Mat3f matrix = gm::Mat3f::Identity();

    gm::SetScale( gm::Vec2f( 1.0f, 1.0f ), matrix );
    CHECK( !gm::HasScale( matrix ) );

    gm::SetScale( gm::Vec2f( 2.0f, 2.0f ), matrix );
    CHECK( gm::HasScale( matrix ) );

    gm::SetScale( gm::Vec2f( 0.0f, 3.0f ), matrix );
    CHECK( gm::HasScale( matrix ) );
}

TEST_CASE( "HasScale_Mat4f" )
{
    gm::Mat4f matrix = gm::Mat4f::Identity();

    gm::SetScale( gm::Vec3f( 1.0f, 1.0f, 1.0f ), matrix );
    CHECK( !gm::HasScale( matrix ) );

    gm::SetScale( gm::Vec3f( 2.0f, 2.0f, 2.0f ), matrix );
    CHECK( gm::HasScale( matrix ) );

    gm::SetScale( gm::Vec3f( 0.0f, 3.0f, 6.0f ), matrix );
    CHECK( gm::HasScale( matrix ) );
}
