//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec2iRange.h>

TEST_CASE( "Vec2iRange_DefaultConstructor" )
{
    gm::Vec2iRange range;
    CHECK( range.Min() == gm::Vec2i( std::numeric_limits< int >::max(), std::numeric_limits< int >::max() ) );
    CHECK( range.Max() == gm::Vec2i( std::numeric_limits< int >::min(), std::numeric_limits< int >::min() ) );
}

TEST_CASE( "Vec2iRange_MinMaxConstructor" )
{
    gm::Vec2iRange range( gm::Vec2i( -1, -1 ), gm::Vec2i( 1, 1 ) );
    CHECK( range.Min() == gm::Vec2i( -1, -1 ) );
    CHECK( range.Max() == gm::Vec2i( 1, 1 ) );
}