//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec3fArray.h>
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
    gm::Vec3fRange range( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 1.0f, 1.0f, 1.0f ) );
    CHECK( range.Min() == gm::Vec3f( -1.0f, -1.0f, -1.0f ) );
    CHECK( range.Max() == gm::Vec3f( 1.0f, 1.0f, 1.0f ) );
}

TEST_CASE( "Vec3fRange_MinAccessor" )
{
    gm::Vec3fRange range;
    range.Min() = gm::Vec3f( -1.0f, -1.0f, -1.0f );
    CHECK( range.Min() == gm::Vec3f( -1.0f, -1.0f, -1.0f ) );
}

TEST_CASE( "Vec3fRange_MaxAccessor" )
{
    gm::Vec3fRange range;
    range.Max() = gm::Vec3f( 1.0f, 1.0f, 1.0f );
    CHECK( range.Max() == gm::Vec3f( 1.0f, 1.0f, 1.0f ) );
}
