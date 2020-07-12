//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/expand.h>

TEST_CASE( "Expand_FloatRange" )
{
    CHECK( gm::Expand( gm::FloatRange( -2.0f, 4.0f ), gm::FloatRange( -3.0f, -1.0f ) ) ==
           gm::FloatRange( -3.0f, 4.0f ) );
    CHECK( gm::Expand( gm::FloatRange( -2.0f, 2.0f ), gm::FloatRange( -1.0f, 1.0f ) ) ==
           gm::FloatRange( -2.0f, 2.0f ) );
}

TEST_CASE( "Expand_IntRange" )
{
    CHECK( gm::Expand( gm::IntRange( -2, 4 ), gm::IntRange( -3, -1 ) ) == gm::IntRange( -3, 4 ) );
    CHECK( gm::Expand( gm::IntRange( -2, 2 ), gm::IntRange( -1, 1 ) ) == gm::IntRange( -2, 2 ) );
}

TEST_CASE( "Expand_Vec2fRange" )
{
    CHECK( gm::Expand( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 4.0f, 4.0f ) ),
                       gm::Vec2fRange( gm::Vec2f( -3.0f, -3.0f ), gm::Vec2f( -1.0f, -1.0f ) ) ) ==
           gm::Vec2fRange( gm::Vec2f( -3.0f, -3.0f ), gm::Vec2f( 4.0f, 4.0f ) ) );
    CHECK( gm::Expand( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ),
                       gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 1.0f, 1.0f ) ) ) ==
           gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ) );
}

TEST_CASE( "Expand_Vec3fRange" )
{
    CHECK( gm::Expand( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 4.0f, 4.0f, 4.0f ) ),
                       gm::Vec3fRange( gm::Vec3f( -3.0f, -3.0f, -3.0f ), gm::Vec3f( -1.0f, -1.0f, -1.0f ) ) ) ==
           gm::Vec3fRange( gm::Vec3f( -3.0f, -3.0f, -3.0f ), gm::Vec3f( 4.0f, 4.0f, 4.0f ) ) );
    CHECK( gm::Expand( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ),
                       gm::Vec3fRange( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 1.0f, 1.0f, 1.0f ) ) ) ==
           gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ) );
}

TEST_CASE( "Expand_Vec4fRange" )
{
    CHECK( gm::Expand(
               gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ) ),
               gm::Vec4fRange( gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ), gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ) ) ==
           gm::Vec4fRange( gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ), gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ) ) );
    CHECK(
        gm::Expand( gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ),
                    gm::Vec4fRange( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ) ) ==
        gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ) );
}

TEST_CASE( "Expand_Vec2iRange" )
{
    CHECK( gm::Expand( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 4, 4 ) ),
                       gm::Vec2iRange( gm::Vec2i( -3, -3 ), gm::Vec2i( -1, -1 ) ) ) ==
           gm::Vec2iRange( gm::Vec2i( -3, -3 ), gm::Vec2i( 4, 4 ) ) );
    CHECK( gm::Expand( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ),
                       gm::Vec2iRange( gm::Vec2i( -1, -1 ), gm::Vec2i( 1, 1 ) ) ) ==
           gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ) );
}

TEST_CASE( "Expand_Vec3iRange" )
{
    CHECK( gm::Expand( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 4, 4, 4 ) ),
                       gm::Vec3iRange( gm::Vec3i( -3, -3, -3 ), gm::Vec3i( -1, -1, -1 ) ) ) ==
           gm::Vec3iRange( gm::Vec3i( -3, -3, -3 ), gm::Vec3i( 4, 4, 4 ) ) );
    CHECK( gm::Expand( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ),
                       gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 1, 1, 1 ) ) ) ==
           gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ) );
}

TEST_CASE( "Expand_Vec4iRange" )
{
    CHECK( gm::Expand( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 4, 4, 4, 4 ) ),
                       gm::Vec4iRange( gm::Vec4i( -3, -3, -3, -3 ), gm::Vec4i( -1, -1, -1, -1 ) ) ) ==
           gm::Vec4iRange( gm::Vec4i( -3, -3, -3, -3 ), gm::Vec4i( 4, 4, 4, 4 ) ) );
    CHECK( gm::Expand( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ),
                       gm::Vec4iRange( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 1, 1, 1, 1 ) ) ) ==
           gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ) );
}
