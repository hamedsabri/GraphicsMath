//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/lookAt.h>

TEST_CASE( "LookAt_Mat4f" )
{
    gm::Vec3f position( 0, 0, -1 );
    gm::Vec3f look( 0, 0, 0 );
    gm::Vec3f up( 0, 1, 0 );

    gm::Mat4f cameraToWorld = gm::LookAt( position, look, up );
    CHECK( cameraToWorld == gm::Mat4f( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, -1, 0, 0, 0, 1 ) );
}