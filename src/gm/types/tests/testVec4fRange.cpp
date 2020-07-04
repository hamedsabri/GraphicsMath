//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

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
    gm::Vec4fRange range( gm::Vec4f( -1, -1, -1, -1 ), gm::Vec4f( 1, 1, 1, 1 ) );
    CHECK( range.Min() == gm::Vec4f( -1, -1, -1, -1 ) );
    CHECK( range.Max() == gm::Vec4f( 1, 1, 1, 1 ) );
}