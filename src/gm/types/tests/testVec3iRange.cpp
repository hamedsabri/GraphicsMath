//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

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