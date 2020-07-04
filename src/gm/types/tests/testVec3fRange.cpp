//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec3fRange.h>

TEST_CASE( "Vec3fRange_DefaultConstructor" )
{
    gm::Vec3fRange range;
    CHECK( range.Min() == gm::Vec3f( std::numeric_limits< float >::max(),
                                     std::numeric_limits< float >::max(),
                                     std::numeric_limits< float >::max() ) );
    CHECK( range.Max() == gm::Vec3f( std::numeric_limits< float >::min(),
                                     std::numeric_limits< float >::min(),
                                     std::numeric_limits< float >::min() ) );
}

TEST_CASE( "Vec3fRange_MinMaxConstructor" )
{
    gm::Vec3fRange range( gm::Vec3f( -1, -1, -1 ), gm::Vec3f( 1, 1, 1 ) );
    CHECK( range.Min() == gm::Vec3f( -1, -1, -1 ) );
    CHECK( range.Max() == gm::Vec3f( 1, 1, 1 ) );
}