//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/longestAxis.h>

TEST_CASE( "LongestAxis_Vec2fRange" )
{
    CHECK( gm::LongestAxis( gm::Vec2fRange( gm::Vec2f( 0.0f, 1.0f ), gm::Vec2f( 0.0f, 2.0f ) ) ) == 1 );
}

TEST_CASE( "LongestAxis_Vec3fRange" )
{
    CHECK( gm::LongestAxis( gm::Vec3fRange( gm::Vec3f( 0.0f, 1.0f, 2.0f ), gm::Vec3f( 0.0f, 2.0f, 4.0f ) ) ) == 2 );
}

TEST_CASE( "LongestAxis_Vec4fRange" )
{
    CHECK( gm::LongestAxis(
               gm::Vec4fRange( gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f ), gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f ) ) ) == 3 );
}

TEST_CASE( "LongestAxis_Vec2iRange" )
{
    CHECK( gm::LongestAxis( gm::Vec2iRange( gm::Vec2i( 0, 1 ), gm::Vec2i( 0, 2 ) ) ) == 1 );
}

TEST_CASE( "LongestAxis_Vec3iRange" )
{
    CHECK( gm::LongestAxis( gm::Vec3iRange( gm::Vec3i( 0, 1, 2 ), gm::Vec3i( 0, 2, 4 ) ) ) == 2 );
}

TEST_CASE( "LongestAxis_Vec4iRange" )
{
    CHECK( gm::LongestAxis( gm::Vec4iRange( gm::Vec4i( 0, 1, 2, 3 ), gm::Vec4i( 0, 2, 4, 6 ) ) ) == 3 );
}
