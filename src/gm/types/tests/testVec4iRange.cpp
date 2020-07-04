//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec4iRange.h>

TEST_CASE( "Vec4iRange_DefaultConstructor" )
{
    gm::Vec4iRange range;
    CHECK( range.Min() == gm::Vec4i( std::numeric_limits< int >::max(),
                                     std::numeric_limits< int >::max(),
                                     std::numeric_limits< int >::max(),
                                     std::numeric_limits< int >::max() ) );
    CHECK( range.Max() == gm::Vec4i( std::numeric_limits< int >::min(),
                                     std::numeric_limits< int >::min(),
                                     std::numeric_limits< int >::min(),
                                     std::numeric_limits< int >::min() ) );
}

TEST_CASE( "Vec4iRange_MinMaxConstructor" )
{
    gm::Vec4iRange range( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 1, 1, 1, 1 ) );
    CHECK( range.Min() == gm::Vec4i( -1, -1, -1, -1 ) );
    CHECK( range.Max() == gm::Vec4i( 1, 1, 1, 1 ) );
}