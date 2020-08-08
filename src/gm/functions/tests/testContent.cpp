//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/content.h>

TEST_CASE( "Content_FloatRange" )
{
    gm::FloatRange range = gm::FloatRange( 0.0f, 2.0f );
    CHECK( gm::Content( range ) == 2.0f );
}

TEST_CASE( "Content_IntRange" )
{
    gm::IntRange range = gm::IntRange( 0, 2 );
    CHECK( gm::Content( range ) == 2 );
}

TEST_CASE( "Content_Vec2fRange" )
{
    gm::Vec2fRange range = gm::Vec2fRange( gm::Vec2f( 0.0f, 0.0f ), gm::Vec2f( 2.0f, 2.0f ) );
    CHECK( gm::Content( range ) == 4.0 );
}

TEST_CASE( "Content_Vec3fRange" )
{
    gm::Vec3fRange range = gm::Vec3fRange( gm::Vec3f( 0.0f, 0.0f, 0.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) );
    CHECK( gm::Content( range ) == 8.0 );
}

TEST_CASE( "Content_Vec4fRange" )
{
    gm::Vec4fRange range = gm::Vec4fRange( gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) );
    CHECK( gm::Content( range ) == 16.0 );
}

TEST_CASE( "Content_Vec2iRange" )
{
    gm::Vec2iRange range = gm::Vec2iRange( gm::Vec2i( 0, 0 ), gm::Vec2i( 2, 2 ) );
    CHECK( gm::Content( range ) == 4.0 );
}

TEST_CASE( "Content_Vec3iRange" )
{
    gm::Vec3iRange range = gm::Vec3iRange( gm::Vec3i( 0, 0, 0 ), gm::Vec3i( 2, 2, 2 ) );
    CHECK( gm::Content( range ) == 8.0 );
}

TEST_CASE( "Content_Vec4iRange" )
{
    gm::Vec4iRange range = gm::Vec4iRange( gm::Vec4i( 0, 0, 0, 0 ), gm::Vec4i( 2, 2, 2, 2 ) );
    CHECK( gm::Content( range ) == 16.0 );
}
