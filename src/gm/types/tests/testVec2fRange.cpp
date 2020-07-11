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

TEST_CASE( "Vec2fRange_EqualityComparison" )
{
    CHECK( gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) ==
           gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) );
    CHECK( !( gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) ==
              gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) ) );
}

TEST_CASE( "Vec2fRange_InequalityComparison" )
{
    CHECK( gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) !=
           gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) );
    CHECK( !( gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) !=
              gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ) ) );
}

TEST_CASE( "Vec2fRange_IsEmpty" )
{
    CHECK( gm::Vec2fRange( gm::Vec2f( 2.0f, 2.0f ), gm::Vec2f( -2.0f, -2.0f ) ).IsEmpty() );
    CHECK( !gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( -2.0f, -2.0f ) ).IsEmpty() );
    CHECK( !gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ).IsEmpty() );
}

TEST_CASE( "Vec2fRange_ContainsElement" )
{
    gm::Vec2fRange range(
        /* min */ gm::Vec2f( -2.0f, -2.0f ),
        /* max */ gm::Vec2f( 4.0f, 4.0f ) );
    CHECK( range.Contains( gm::Vec2f( -2.0f, -2.0f ) ) );
    CHECK( range.Contains( gm::Vec2f( 0.0f, 0.0f ) ) );
    CHECK( range.Contains( gm::Vec2f( 4.0f, 4.0f ) ) );
    CHECK( !range.Contains( gm::Vec2f( -3.0f, -3.0f ) ) );
    CHECK( !range.Contains( gm::Vec2f( 5.0f, 5.0f ) ) );
}

TEST_CASE( "Vec2fRange_ContainsRange" )
{
    gm::Vec2fRange range(
        /* min */ gm::Vec2f( -2.0f, -2.0f ),
        /* max */ gm::Vec2f( 4.0f, 4.0f ) );
    CHECK( range.Contains( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 3.0f, 3.0f ) ) ) );
    CHECK( range.Contains( gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 2.0f, 2.0f ) ) ) );
    CHECK( !range.Contains( gm::Vec2fRange( gm::Vec2f( -3.0f, -3.0f ), gm::Vec2f( 2.0f, 2.0f ) ) ) );
    CHECK( !range.Contains( gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 5.0f, 5.0f ) ) ) );
    CHECK( !range.Contains( gm::Vec2fRange( gm::Vec2f( 7.0f, 7.0f ), gm::Vec2f( 10.0f, 10.0f ) ) ) );
    CHECK( !range.Contains( gm::Vec2fRange( gm::Vec2f( -5.0f, -5.0f ), gm::Vec2f( -4.0f, -4.0f ) ) ) );
}
