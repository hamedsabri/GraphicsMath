//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/viewportTransform.h>

TEST_CASE( "ViewportTransform" )
{
    {
        gm::Mat4f matrix = gm::ViewportTransform( gm::Vec2f( 300, 200 ), gm::Vec2f( 0, 0 ) );
        gm::Mat4f expectedMatrix( 150, 0, 0, 150, 0, 100, 0, 100, 0, 0, 1, 0, 0, 0, 0, 1 );
        CHECK( matrix == expectedMatrix );
    }

    {
        gm::Mat4f matrix = gm::ViewportTransform( gm::Vec2f( 300, 200 ), gm::Vec2f( 50, 75 ) );
        gm::Mat4f expectedMatrix( 150, 0, 0, 200, 0, 100, 0, 175, 0, 0, 1, 0, 0, 0, 0, 1 );
        CHECK( matrix == expectedMatrix );
    }
}