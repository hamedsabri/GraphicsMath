//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec4fArray.h>
#include <gm/types/vec4fRange.h>

TEST_CASE( "Vec4fRange_DefaultConstructor" )
{
    gm::Vec4fRange range;
    CHECK( range.Min() == gm::Vec4f( std::numeric_limits< float >::max(),
                                     std::numeric_limits< float >::max(),
                                     std::numeric_limits< float >::max(),
                                     std::numeric_limits< float >::max() ) );
    CHECK( range.Max() == gm::Vec4f( std::numeric_limits< float >::min(),
                                     std::numeric_limits< float >::min(),
                                     std::numeric_limits< float >::min(),
                                     std::numeric_limits< float >::min() ) );
}

TEST_CASE( "Vec4fRange_MinMaxConstructor" )
{
    gm::Vec4fRange range( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) );
    CHECK( range.Min() == gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) );
    CHECK( range.Max() == gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) );
}

TEST_CASE( "Vec4fRange_MinAccessor" )
{
    gm::Vec4fRange range;
    range.Min() = gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f );
    CHECK( range.Min() == gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) );
}

TEST_CASE( "Vec4fRange_MaxAccessor" )
{
    gm::Vec4fRange range;
    range.Max() = gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f );
    CHECK( range.Max() == gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) );
}

TEST_CASE( "Vec4fRange_EqualityComparison" )
{
    CHECK( gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) ==
           gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) );
    CHECK( !( gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) ==
              gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) ) );
}

TEST_CASE( "Vec4fRange_InequalityComparison" )
{
    CHECK( gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) !=
           gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) );
    CHECK( !( gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) !=
              gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) ) );
}

TEST_CASE( "Vec4fRange_IsEmpty" )
{
    CHECK( gm::Vec4fRange( gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ).IsEmpty() );
    CHECK(
        !gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ).IsEmpty() );
    CHECK( !gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ).IsEmpty() );
}
