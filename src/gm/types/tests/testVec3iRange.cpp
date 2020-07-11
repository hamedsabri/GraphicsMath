//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec3iArray.h>
#include <gm/types/vec3iRange.h>

TEST_CASE( "Vec3iRange_DefaultConstructor" )
{
    gm::Vec3iRange range;
    CHECK( range.Min() == gm::Vec3i( std::numeric_limits< int >::max(),
                                     std::numeric_limits< int >::max(),
                                     std::numeric_limits< int >::max() ) );
    CHECK( range.Max() == gm::Vec3i( std::numeric_limits< int >::min(),
                                     std::numeric_limits< int >::min(),
                                     std::numeric_limits< int >::min() ) );
}

TEST_CASE( "Vec3iRange_MinMaxConstructor" )
{
    gm::Vec3iRange range( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 1, 1, 1 ) );
    CHECK( range.Min() == gm::Vec3i( -1, -1, -1 ) );
    CHECK( range.Max() == gm::Vec3i( 1, 1, 1 ) );
}

TEST_CASE( "Vec3iRange_MinAccessor" )
{
    gm::Vec3iRange range;
    range.Min() = gm::Vec3i( -1, -1, -1 );
    CHECK( range.Min() == gm::Vec3i( -1, -1, -1 ) );
}

TEST_CASE( "Vec3iRange_MaxAccessor" )
{
    gm::Vec3iRange range;
    range.Max() = gm::Vec3i( 1, 1, 1 );
    CHECK( range.Max() == gm::Vec3i( 1, 1, 1 ) );
}

TEST_CASE( "Vec3iRange_EqualityComparison" )
{
    CHECK( gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) ==
           gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) );
    CHECK( !( gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) ==
              gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( -2, -2, -2 ) ) ) );
}

TEST_CASE( "Vec3iRange_InequalityComparison" )
{
    CHECK( gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) !=
           gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( -2, -2, -2 ) ) );
    CHECK( !( gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) !=
              gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ) ) );
}

TEST_CASE( "Vec3iRange_IsEmpty" )
{
    CHECK( gm::Vec3iRange( gm::Vec3i( 2, 2, 2 ), gm::Vec3i( -2, -2, -2 ) ).IsEmpty() );
    CHECK( !gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( -2, -2, -2 ) ).IsEmpty() );
    CHECK( !gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ).IsEmpty() );
}

TEST_CASE( "Vec3iRange_ContainsElement" )
{
    gm::Vec3iRange range(
        /* min */ gm::Vec3i( -2, -2, -2 ),
        /* max */ gm::Vec3i( 4, 4, 4 ) );
    CHECK( range.Contains( gm::Vec3i( -2, -2, -2 ) ) );
    CHECK( range.Contains( gm::Vec3i( 0, 0, 0 ) ) );
    CHECK( range.Contains( gm::Vec3i( 4, 4, 4 ) ) );
    CHECK( !range.Contains( gm::Vec3i( -3, -3, -3 ) ) );
    CHECK( !range.Contains( gm::Vec3i( 5, 5, 5 ) ) );
}

TEST_CASE( "Vec3iRange_ContainsRange" )
{
    gm::Vec3iRange range(
        /* min */ gm::Vec3i( -2, -2, -2 ),
        /* max */ gm::Vec3i( 4, 4, 4 ) );
    CHECK( range.Contains( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 3, 3, 3 ) ) ) );
    CHECK( range.Contains( gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 2, 2, 2 ) ) ) );
    CHECK( !range.Contains( gm::Vec3iRange( gm::Vec3i( -3, -3, -3 ), gm::Vec3i( 2, 2, 2 ) ) ) );
    CHECK( !range.Contains( gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 5, 5, 5 ) ) ) );
    CHECK( !range.Contains( gm::Vec3iRange( gm::Vec3i( 7, 7, 7 ), gm::Vec3i( 10, 10, 10 ) ) ) );
    CHECK( !range.Contains( gm::Vec3iRange( gm::Vec3i( -5, -5, -5 ), gm::Vec3i( -4, -4, -4 ) ) ) );
}

TEST_CASE( "Vec3iRange_RangeIteration" )
{
    gm::Vec3iRange range( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 4, 4, 4 ) );
    gm::Vec3iArray array;
    for ( const gm::Vec3i& value : range )
    {
        array.push_back( value );
    }

    gm::Vec3iArray expectedArray = {
        gm::Vec3i( -2, -2, -2 ), gm::Vec3i( -1, -2, -2 ), gm::Vec3i( 0, -2, -2 ),  gm::Vec3i( 1, -2, -2 ),
        gm::Vec3i( 2, -2, -2 ),  gm::Vec3i( 3, -2, -2 ),  gm::Vec3i( -2, -1, -2 ), gm::Vec3i( -1, -1, -2 ),
        gm::Vec3i( 0, -1, -2 ),  gm::Vec3i( 1, -1, -2 ),  gm::Vec3i( 2, -1, -2 ),  gm::Vec3i( 3, -1, -2 ),
        gm::Vec3i( -2, 0, -2 ),  gm::Vec3i( -1, 0, -2 ),  gm::Vec3i( 0, 0, -2 ),   gm::Vec3i( 1, 0, -2 ),
        gm::Vec3i( 2, 0, -2 ),   gm::Vec3i( 3, 0, -2 ),   gm::Vec3i( -2, 1, -2 ),  gm::Vec3i( -1, 1, -2 ),
        gm::Vec3i( 0, 1, -2 ),   gm::Vec3i( 1, 1, -2 ),   gm::Vec3i( 2, 1, -2 ),   gm::Vec3i( 3, 1, -2 ),
        gm::Vec3i( -2, 2, -2 ),  gm::Vec3i( -1, 2, -2 ),  gm::Vec3i( 0, 2, -2 ),   gm::Vec3i( 1, 2, -2 ),
        gm::Vec3i( 2, 2, -2 ),   gm::Vec3i( 3, 2, -2 ),   gm::Vec3i( -2, 3, -2 ),  gm::Vec3i( -1, 3, -2 ),
        gm::Vec3i( 0, 3, -2 ),   gm::Vec3i( 1, 3, -2 ),   gm::Vec3i( 2, 3, -2 ),   gm::Vec3i( 3, 3, -2 ),
        gm::Vec3i( -2, -2, -1 ), gm::Vec3i( -1, -2, -1 ), gm::Vec3i( 0, -2, -1 ),  gm::Vec3i( 1, -2, -1 ),
        gm::Vec3i( 2, -2, -1 ),  gm::Vec3i( 3, -2, -1 ),  gm::Vec3i( -2, -1, -1 ), gm::Vec3i( -1, -1, -1 ),
        gm::Vec3i( 0, -1, -1 ),  gm::Vec3i( 1, -1, -1 ),  gm::Vec3i( 2, -1, -1 ),  gm::Vec3i( 3, -1, -1 ),
        gm::Vec3i( -2, 0, -1 ),  gm::Vec3i( -1, 0, -1 ),  gm::Vec3i( 0, 0, -1 ),   gm::Vec3i( 1, 0, -1 ),
        gm::Vec3i( 2, 0, -1 ),   gm::Vec3i( 3, 0, -1 ),   gm::Vec3i( -2, 1, -1 ),  gm::Vec3i( -1, 1, -1 ),
        gm::Vec3i( 0, 1, -1 ),   gm::Vec3i( 1, 1, -1 ),   gm::Vec3i( 2, 1, -1 ),   gm::Vec3i( 3, 1, -1 ),
        gm::Vec3i( -2, 2, -1 ),  gm::Vec3i( -1, 2, -1 ),  gm::Vec3i( 0, 2, -1 ),   gm::Vec3i( 1, 2, -1 ),
        gm::Vec3i( 2, 2, -1 ),   gm::Vec3i( 3, 2, -1 ),   gm::Vec3i( -2, 3, -1 ),  gm::Vec3i( -1, 3, -1 ),
        gm::Vec3i( 0, 3, -1 ),   gm::Vec3i( 1, 3, -1 ),   gm::Vec3i( 2, 3, -1 ),   gm::Vec3i( 3, 3, -1 ),
        gm::Vec3i( -2, -2, 0 ),  gm::Vec3i( -1, -2, 0 ),  gm::Vec3i( 0, -2, 0 ),   gm::Vec3i( 1, -2, 0 ),
        gm::Vec3i( 2, -2, 0 ),   gm::Vec3i( 3, -2, 0 ),   gm::Vec3i( -2, -1, 0 ),  gm::Vec3i( -1, -1, 0 ),
        gm::Vec3i( 0, -1, 0 ),   gm::Vec3i( 1, -1, 0 ),   gm::Vec3i( 2, -1, 0 ),   gm::Vec3i( 3, -1, 0 ),
        gm::Vec3i( -2, 0, 0 ),   gm::Vec3i( -1, 0, 0 ),   gm::Vec3i( 0, 0, 0 ),    gm::Vec3i( 1, 0, 0 ),
        gm::Vec3i( 2, 0, 0 ),    gm::Vec3i( 3, 0, 0 ),    gm::Vec3i( -2, 1, 0 ),   gm::Vec3i( -1, 1, 0 ),
        gm::Vec3i( 0, 1, 0 ),    gm::Vec3i( 1, 1, 0 ),    gm::Vec3i( 2, 1, 0 ),    gm::Vec3i( 3, 1, 0 ),
        gm::Vec3i( -2, 2, 0 ),   gm::Vec3i( -1, 2, 0 ),   gm::Vec3i( 0, 2, 0 ),    gm::Vec3i( 1, 2, 0 ),
        gm::Vec3i( 2, 2, 0 ),    gm::Vec3i( 3, 2, 0 ),    gm::Vec3i( -2, 3, 0 ),   gm::Vec3i( -1, 3, 0 ),
        gm::Vec3i( 0, 3, 0 ),    gm::Vec3i( 1, 3, 0 ),    gm::Vec3i( 2, 3, 0 ),    gm::Vec3i( 3, 3, 0 ),
        gm::Vec3i( -2, -2, 1 ),  gm::Vec3i( -1, -2, 1 ),  gm::Vec3i( 0, -2, 1 ),   gm::Vec3i( 1, -2, 1 ),
        gm::Vec3i( 2, -2, 1 ),   gm::Vec3i( 3, -2, 1 ),   gm::Vec3i( -2, -1, 1 ),  gm::Vec3i( -1, -1, 1 ),
        gm::Vec3i( 0, -1, 1 ),   gm::Vec3i( 1, -1, 1 ),   gm::Vec3i( 2, -1, 1 ),   gm::Vec3i( 3, -1, 1 ),
        gm::Vec3i( -2, 0, 1 ),   gm::Vec3i( -1, 0, 1 ),   gm::Vec3i( 0, 0, 1 ),    gm::Vec3i( 1, 0, 1 ),
        gm::Vec3i( 2, 0, 1 ),    gm::Vec3i( 3, 0, 1 ),    gm::Vec3i( -2, 1, 1 ),   gm::Vec3i( -1, 1, 1 ),
        gm::Vec3i( 0, 1, 1 ),    gm::Vec3i( 1, 1, 1 ),    gm::Vec3i( 2, 1, 1 ),    gm::Vec3i( 3, 1, 1 ),
        gm::Vec3i( -2, 2, 1 ),   gm::Vec3i( -1, 2, 1 ),   gm::Vec3i( 0, 2, 1 ),    gm::Vec3i( 1, 2, 1 ),
        gm::Vec3i( 2, 2, 1 ),    gm::Vec3i( 3, 2, 1 ),    gm::Vec3i( -2, 3, 1 ),   gm::Vec3i( -1, 3, 1 ),
        gm::Vec3i( 0, 3, 1 ),    gm::Vec3i( 1, 3, 1 ),    gm::Vec3i( 2, 3, 1 ),    gm::Vec3i( 3, 3, 1 ),
        gm::Vec3i( -2, -2, 2 ),  gm::Vec3i( -1, -2, 2 ),  gm::Vec3i( 0, -2, 2 ),   gm::Vec3i( 1, -2, 2 ),
        gm::Vec3i( 2, -2, 2 ),   gm::Vec3i( 3, -2, 2 ),   gm::Vec3i( -2, -1, 2 ),  gm::Vec3i( -1, -1, 2 ),
        gm::Vec3i( 0, -1, 2 ),   gm::Vec3i( 1, -1, 2 ),   gm::Vec3i( 2, -1, 2 ),   gm::Vec3i( 3, -1, 2 ),
        gm::Vec3i( -2, 0, 2 ),   gm::Vec3i( -1, 0, 2 ),   gm::Vec3i( 0, 0, 2 ),    gm::Vec3i( 1, 0, 2 ),
        gm::Vec3i( 2, 0, 2 ),    gm::Vec3i( 3, 0, 2 ),    gm::Vec3i( -2, 1, 2 ),   gm::Vec3i( -1, 1, 2 ),
        gm::Vec3i( 0, 1, 2 ),    gm::Vec3i( 1, 1, 2 ),    gm::Vec3i( 2, 1, 2 ),    gm::Vec3i( 3, 1, 2 ),
        gm::Vec3i( -2, 2, 2 ),   gm::Vec3i( -1, 2, 2 ),   gm::Vec3i( 0, 2, 2 ),    gm::Vec3i( 1, 2, 2 ),
        gm::Vec3i( 2, 2, 2 ),    gm::Vec3i( 3, 2, 2 ),    gm::Vec3i( -2, 3, 2 ),   gm::Vec3i( -1, 3, 2 ),
        gm::Vec3i( 0, 3, 2 ),    gm::Vec3i( 1, 3, 2 ),    gm::Vec3i( 2, 3, 2 ),    gm::Vec3i( 3, 3, 2 ),
        gm::Vec3i( -2, -2, 3 ),  gm::Vec3i( -1, -2, 3 ),  gm::Vec3i( 0, -2, 3 ),   gm::Vec3i( 1, -2, 3 ),
        gm::Vec3i( 2, -2, 3 ),   gm::Vec3i( 3, -2, 3 ),   gm::Vec3i( -2, -1, 3 ),  gm::Vec3i( -1, -1, 3 ),
        gm::Vec3i( 0, -1, 3 ),   gm::Vec3i( 1, -1, 3 ),   gm::Vec3i( 2, -1, 3 ),   gm::Vec3i( 3, -1, 3 ),
        gm::Vec3i( -2, 0, 3 ),   gm::Vec3i( -1, 0, 3 ),   gm::Vec3i( 0, 0, 3 ),    gm::Vec3i( 1, 0, 3 ),
        gm::Vec3i( 2, 0, 3 ),    gm::Vec3i( 3, 0, 3 ),    gm::Vec3i( -2, 1, 3 ),   gm::Vec3i( -1, 1, 3 ),
        gm::Vec3i( 0, 1, 3 ),    gm::Vec3i( 1, 1, 3 ),    gm::Vec3i( 2, 1, 3 ),    gm::Vec3i( 3, 1, 3 ),
        gm::Vec3i( -2, 2, 3 ),   gm::Vec3i( -1, 2, 3 ),   gm::Vec3i( 0, 2, 3 ),    gm::Vec3i( 1, 2, 3 ),
        gm::Vec3i( 2, 2, 3 ),    gm::Vec3i( 3, 2, 3 ),    gm::Vec3i( -2, 3, 3 ),   gm::Vec3i( -1, 3, 3 ),
        gm::Vec3i( 0, 3, 3 ),    gm::Vec3i( 1, 3, 3 ),    gm::Vec3i( 2, 3, 3 ),    gm::Vec3i( 3, 3, 3 ),
    };
    CHECK( array == expectedArray );
}
