//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec2fArray.h>
#include <gm/types/vec2fRange.h>

TEST_CASE( "Vec2fRange_DefaultConstructor" )
{
    gm::Vec2fRange range;
    CHECK( range.Min() == gm::Vec2f( std::numeric_limits< float >::max(), std::numeric_limits< float >::max() ) );
    CHECK( range.Max() == gm::Vec2f( std::numeric_limits< float >::min(), std::numeric_limits< float >::min() ) );
}

TEST_CASE( "Vec2fRange_MinMaxConstructor" )
{
    gm::Vec2fRange range( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 1.0f, 1.0f ) );
    CHECK( range.Min() == gm::Vec2f( -1.0f, -1.0f ) );
    CHECK( range.Max() == gm::Vec2f( 1.0f, 1.0f ) );
}

TEST_CASE( "Vec2fRange_MinAccessor" )
{
    gm::Vec2fRange range;
    range.Min() = gm::Vec2f( -1.0f, -1.0f );
    CHECK( range.Min() == gm::Vec2f( -1.0f, -1.0f ) );
}

TEST_CASE( "Vec2fRange_MaxAccessor" )
{
    gm::Vec2fRange range;
    range.Max() = gm::Vec2f( 1.0f, 1.0f );
    CHECK( range.Max() == gm::Vec2f( 1.0f, 1.0f ) );
}
