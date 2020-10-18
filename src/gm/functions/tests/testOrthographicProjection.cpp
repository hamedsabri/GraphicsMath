//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/orthographicProjection.h>

TEST_CASE( "OrthographicProjection" )
{
    {
        gm::Vec3fRange viewingVolume( gm::Vec3f( -2, -2, -2 ), gm::Vec3f( 2, 2, 2 ) );
        gm::Mat4f      matrix = gm::OrthographicProjection( viewingVolume );
        gm::Mat4f      expectedMatrix( 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 );
        CHECK( matrix == expectedMatrix );
    }

    {
        gm::Vec3fRange viewingVolume( gm::Vec3f( -1, -1, -1 ), gm::Vec3f( 3, 3, 3 ) );
        gm::Mat4f      matrix = gm::OrthographicProjection( viewingVolume );
        gm::Mat4f      expectedMatrix( 0.5, 0, 0, -0.5, 0, 0.5, 0, -0.5, 0, 0, 0.5, -0.5, 0, 0, 0, 1 );
        CHECK( matrix == expectedMatrix );
    }
}