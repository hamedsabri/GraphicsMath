//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec2iRange.h>

#include <vector>

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

TEST_CASE( "Vec2iRange_MinAccessor" )
{
    gm::Vec2iRange range;
    range.Min() = gm::Vec2i( -1, -1 );
    CHECK( range.Min() == gm::Vec2i( -1, -1 ) );
}

TEST_CASE( "Vec2iRange_MaxAccessor" )
{
    gm::Vec2iRange range;
    range.Max() = gm::Vec2i( 1, 1 );
    CHECK( range.Max() == gm::Vec2i( 1, 1 ) );
}

TEST_CASE( "Vec2iRange_EqualityComparison" )
{
    CHECK( gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) ==
           gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) );
    CHECK( !( gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) ==
              gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( -2, -2 ) ) ) );
}

TEST_CASE( "Vec2iRange_InequalityComparison" )
{
    CHECK( gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) !=
           gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( -2, -2 ) ) );
    CHECK( !( gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) !=
              gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ) ) );
}

TEST_CASE( "Vec2iRange_IsEmpty" )
{
    CHECK( gm::Vec2iRange( gm::Vec2i( 2, 2 ), gm::Vec2i( -2, -2 ) ).IsEmpty() );
    CHECK( !gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( -2, -2 ) ).IsEmpty() );
    CHECK( !gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ).IsEmpty() );
}

TEST_CASE( "Vec2iRange_RangeIteration" )
{
    gm::Vec2iRange           range( gm::Vec2i( -2, -2 ), gm::Vec2i( 4, 4 ) );
    std::vector< gm::Vec2i > array;
    for ( const gm::Vec2i& value : range )
    {
        array.push_back( value );
    }

    std::vector< gm::Vec2i > expectedArray = {
        gm::Vec2i( -2, -2 ), gm::Vec2i( -1, -2 ), gm::Vec2i( 0, -2 ),  gm::Vec2i( 1, -2 ), gm::Vec2i( 2, -2 ),
        gm::Vec2i( 3, -2 ),  gm::Vec2i( -2, -1 ), gm::Vec2i( -1, -1 ), gm::Vec2i( 0, -1 ), gm::Vec2i( 1, -1 ),
        gm::Vec2i( 2, -1 ),  gm::Vec2i( 3, -1 ),  gm::Vec2i( -2, 0 ),  gm::Vec2i( -1, 0 ), gm::Vec2i( 0, 0 ),
        gm::Vec2i( 1, 0 ),   gm::Vec2i( 2, 0 ),   gm::Vec2i( 3, 0 ),   gm::Vec2i( -2, 1 ), gm::Vec2i( -1, 1 ),
        gm::Vec2i( 0, 1 ),   gm::Vec2i( 1, 1 ),   gm::Vec2i( 2, 1 ),   gm::Vec2i( 3, 1 ),  gm::Vec2i( -2, 2 ),
        gm::Vec2i( -1, 2 ),  gm::Vec2i( 0, 2 ),   gm::Vec2i( 1, 2 ),   gm::Vec2i( 2, 2 ),  gm::Vec2i( 3, 2 ),
        gm::Vec2i( -2, 3 ),  gm::Vec2i( -1, 3 ),  gm::Vec2i( 0, 3 ),   gm::Vec2i( 1, 3 ),  gm::Vec2i( 2, 3 ),
        gm::Vec2i( 3, 3 )};
    CHECK( array == expectedArray );
}
