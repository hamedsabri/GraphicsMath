//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/lookAt.h>

TEST_CASE( "LookAt_Mat4f" )
{
    gm::Vec3f position( 1, 0, 0 );
    gm::Vec3f look( 0, 0, 0 );
    gm::Vec3f up( 0, 1, 0 );

    CHECK( gm::LookAt( position, look, up ) == gm::Mat4f( 0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, 1, 0, 0, 0, 1 ) );
}