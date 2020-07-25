//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>
#include <gm/functions/setRotateZ.h>

TEST_CASE( "SetRotateZ_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    gm::SetRotateZ( 90, matrix );
    CHECK( matrix == gm::Mat4f( 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );

    gm::SetRotateZ( 45, matrix );
    CHECK( matrix == gm::Mat4f( 0.707107, -0.707107, 0, 0, 0.707107, 0.707107, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );
}