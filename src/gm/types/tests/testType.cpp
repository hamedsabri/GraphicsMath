#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/base/log.h>

#include <gm/types/bounds2i.h>
#include <gm/types/vec2iArray.h>
#include <gm/types/vec2iRange.h>

TEST_CASE( "testVec2iRange" )
{
    gm::Bounds2i bounds( gm::Vec2i( 0, 0 ), gm::Vec2i( 5, 5 ) );

    gm::Vec2iArray array;
    for ( const gm::Vec2i& point : gm::Vec2iRange( bounds.Min(), bounds.Max() ) )
    {
        array.push_back( point );
    }

    gm::Vec2iArray expectedArray = {
        gm::Vec2i( 0, 0 ), gm::Vec2i( 1, 0 ), gm::Vec2i( 2, 0 ), gm::Vec2i( 3, 0 ), gm::Vec2i( 4, 0 ),
        gm::Vec2i( 0, 1 ), gm::Vec2i( 1, 1 ), gm::Vec2i( 2, 1 ), gm::Vec2i( 3, 1 ), gm::Vec2i( 4, 1 ),
        gm::Vec2i( 0, 2 ), gm::Vec2i( 1, 2 ), gm::Vec2i( 2, 2 ), gm::Vec2i( 3, 2 ), gm::Vec2i( 4, 2 ),
        gm::Vec2i( 0, 3 ), gm::Vec2i( 1, 3 ), gm::Vec2i( 2, 3 ), gm::Vec2i( 3, 3 ), gm::Vec2i( 4, 3 ),
        gm::Vec2i( 0, 4 ), gm::Vec2i( 1, 4 ), gm::Vec2i( 2, 4 ), gm::Vec2i( 3, 4 ), gm::Vec2i( 4, 4 )};

    CHECK( array == expectedArray );
}
