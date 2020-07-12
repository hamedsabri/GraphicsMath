//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/contains.h>

TEST_CASE( "Contains_FloatRange_float" )
{
    gm::FloatRange range(
        /* min */ -2.0f,
        /* max */ 4.0f );
    CHECK( gm::Contains( range, -2.0f ) );
    CHECK( gm::Contains( range, 0.0f ) );
    CHECK( gm::Contains( range, 4.0f ) );
    CHECK( !gm::Contains( range, -3.0f ) );
    CHECK( !gm::Contains( range, 5.0f ) );
}

TEST_CASE( "Contains_FloatRange_FloatRange" )
{
    gm::FloatRange range(
        /* min */ -2.0f,
        /* max */ 4.0f );
    CHECK( gm::Contains( range, gm::FloatRange( -2.0f, 3.0f ) ) );
    CHECK( gm::Contains( range, gm::FloatRange( -1.0f, 2.0f ) ) );
    CHECK( !gm::Contains( range, gm::FloatRange( -3.0f, 2.0f ) ) );
    CHECK( !gm::Contains( range, gm::FloatRange( -1.0f, 5.0f ) ) );
    CHECK( !gm::Contains( range, gm::FloatRange( 7.0f, 10.0f ) ) );
    CHECK( !gm::Contains( range, gm::FloatRange( -5.0f, -4.0f ) ) );
}

TEST_CASE( "Contains_IntRange_int" )
{
    gm::IntRange range(
        /* min */ -2,
        /* max */ 4 );
    CHECK( gm::Contains( range, -2 ) );
    CHECK( gm::Contains( range, 0 ) );
    CHECK( gm::Contains( range, 4 ) );
    CHECK( !gm::Contains( range, -3 ) );
    CHECK( !gm::Contains( range, 5 ) );
}

TEST_CASE( "Contains_IntRange_IntRange" )
{
    gm::IntRange range(
        /* min */ -2,
        /* max */ 4 );
    CHECK( gm::Contains( range, gm::IntRange( -2, 3 ) ) );
    CHECK( gm::Contains( range, gm::IntRange( -1, 2 ) ) );
    CHECK( !gm::Contains( range, gm::IntRange( -3, 2 ) ) );
    CHECK( !gm::Contains( range, gm::IntRange( -1, 5 ) ) );
    CHECK( !gm::Contains( range, gm::IntRange( 7, 10 ) ) );
    CHECK( !gm::Contains( range, gm::IntRange( -5, -4 ) ) );
}

TEST_CASE( "Contains_Vec2fRange_Vec2f" )
{
    gm::Vec2fRange range(
        /* min */ gm::Vec2f( -2.0f, -2.0f ),
        /* max */ gm::Vec2f( 4.0f, 4.0f ) );
    CHECK( gm::Contains( range, gm::Vec2f( -2.0f, -2.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec2f( 0.0f, 0.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec2f( 4.0f, 4.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec2f( -3.0f, -3.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec2f( 5.0f, 5.0f ) ) );
}

TEST_CASE( "Contains_Vec2fRange_Vec2fRange" )
{
    gm::Vec2fRange range(
        /* min */ gm::Vec2f( -2.0f, -2.0f ),
        /* max */ gm::Vec2f( 4.0f, 4.0f ) );
    CHECK( gm::Contains( range, gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 3.0f, 3.0f ) ) ) );
    CHECK( gm::Contains( range, gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2fRange( gm::Vec2f( -3.0f, -3.0f ), gm::Vec2f( 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 5.0f, 5.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2fRange( gm::Vec2f( 7.0f, 7.0f ), gm::Vec2f( 10.0f, 10.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2fRange( gm::Vec2f( -5.0f, -5.0f ), gm::Vec2f( -4.0f, -4.0f ) ) ) );
}

TEST_CASE( "Contains_Vec3fRange_Vec3f" )
{
    gm::Vec3fRange range(
        /* min */ gm::Vec3f( -2.0f, -2.0f, -2.0f ),
        /* max */ gm::Vec3f( 4.0f, 4.0f, 4.0f ) );
    CHECK( gm::Contains( range, gm::Vec3f( -2.0f, -2.0f, -2.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec3f( 0.0f, 0.0f, 0.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec3f( 4.0f, 4.0f, 4.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec3f( -3.0f, -3.0f, -3.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec3f( 5.0f, 5.0f, 5.0f ) ) );
}

TEST_CASE( "Contains_Vec3fRange_Vec3fRange" )
{
    gm::Vec3fRange range(
        /* min */ gm::Vec3f( -2.0f, -2.0f, -2.0f ),
        /* max */ gm::Vec3f( 4.0f, 4.0f, 4.0f ) );
    CHECK( gm::Contains( range, gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 3.0f, 3.0f, 3.0f ) ) ) );
    CHECK( gm::Contains( range, gm::Vec3fRange( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3fRange( gm::Vec3f( -3.0f, -3.0f, -3.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3fRange( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 5.0f, 5.0f, 5.0f ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3fRange( gm::Vec3f( 7.0f, 7.0f, 7.0f ), gm::Vec3f( 10.0f, 10.0f, 10.0f ) ) ) );
    CHECK(
        !gm::Contains( range, gm::Vec3fRange( gm::Vec3f( -5.0f, -5.0f, -5.0f ), gm::Vec3f( -4.0f, -4.0f, -4.0f ) ) ) );
}

TEST_CASE( "Contains_Vec4fRange_Vec4f" )
{
    gm::Vec4fRange range(
        /* min */ gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ),
        /* max */ gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ) );
    CHECK( gm::Contains( range, gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f ) ) );
    CHECK( gm::Contains( range, gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ) ) );
    CHECK( !gm::Contains( range, gm::Vec4f( 5.0f, 5.0f, 5.0f, 5.0f ) ) );
}

TEST_CASE( "Contains_Vec4fRange_Vec4fRange" )
{
    gm::Vec4fRange range(
        /* min */ gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ),
        /* max */ gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ) );
    CHECK( gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f ) ) ) );
    CHECK( gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ) ) );
    CHECK( !gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 5.0f, 5.0f, 5.0f, 5.0f ) ) ) );
    CHECK( !gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( 7.0f, 7.0f, 7.0f, 7.0f ), gm::Vec4f( 10.0f, 10.0f, 10.0f, 10.0f ) ) ) );
    CHECK( !gm::Contains(
        range,
        gm::Vec4fRange( gm::Vec4f( -5.0f, -5.0f, -5.0f, -5.0f ), gm::Vec4f( -4.0f, -4.0f, -4.0f, -4.0f ) ) ) );
}

TEST_CASE( "Contains_Vec2iRange_Vec2i" )
{
    gm::Vec2iRange range(
        /* min */ gm::Vec2i( -2, -2 ),
        /* max */ gm::Vec2i( 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec2i( -2, -2 ) ) );
    CHECK( gm::Contains( range, gm::Vec2i( 0, 0 ) ) );
    CHECK( gm::Contains( range, gm::Vec2i( 4, 4 ) ) );
    CHECK( !gm::Contains( range, gm::Vec2i( -3, -3 ) ) );
    CHECK( !gm::Contains( range, gm::Vec2i( 5, 5 ) ) );
}

TEST_CASE( "Contains_Vec2iRange_Vec2iRange" )
{
    gm::Vec2iRange range(
        /* min */ gm::Vec2i( -2, -2 ),
        /* max */ gm::Vec2i( 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 3, 3 ) ) ) );
    CHECK( gm::Contains( range, gm::Vec2iRange( gm::Vec2i( -1, -1 ), gm::Vec2i( 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2iRange( gm::Vec2i( -3, -3 ), gm::Vec2i( 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2iRange( gm::Vec2i( -1, -1 ), gm::Vec2i( 5, 5 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2iRange( gm::Vec2i( 7, 7 ), gm::Vec2i( 10, 10 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec2iRange( gm::Vec2i( -5, -5 ), gm::Vec2i( -4, -4 ) ) ) );
}

TEST_CASE( "Contains_Vec3iRange_Vec3i" )
{
    gm::Vec3iRange range(
        /* min */ gm::Vec3i( -2, -2, -2 ),
        /* max */ gm::Vec3i( 4, 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec3i( -2, -2, -2 ) ) );
    CHECK( gm::Contains( range, gm::Vec3i( 0, 0, 0 ) ) );
    CHECK( gm::Contains( range, gm::Vec3i( 4, 4, 4 ) ) );
    CHECK( !gm::Contains( range, gm::Vec3i( -3, -3, -3 ) ) );
    CHECK( !gm::Contains( range, gm::Vec3i( 5, 5, 5 ) ) );
}

TEST_CASE( "Contains_Vec3iRange_Vec3iRange" )
{
    gm::Vec3iRange range(
        /* min */ gm::Vec3i( -2, -2, -2 ),
        /* max */ gm::Vec3i( 4, 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 3, 3, 3 ) ) ) );
    CHECK( gm::Contains( range, gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 2, 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3iRange( gm::Vec3i( -3, -3, -3 ), gm::Vec3i( 2, 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 5, 5, 5 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3iRange( gm::Vec3i( 7, 7, 7 ), gm::Vec3i( 10, 10, 10 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec3iRange( gm::Vec3i( -5, -5, -5 ), gm::Vec3i( -4, -4, -4 ) ) ) );
}

TEST_CASE( "Contains_Vec4iRange_Vec4i" )
{
    gm::Vec4iRange range(
        /* min */ gm::Vec4i( -2, -2, -2, -2 ),
        /* max */ gm::Vec4i( 4, 4, 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec4i( -2, -2, -2, -2 ) ) );
    CHECK( gm::Contains( range, gm::Vec4i( 0, 0, 0, 0 ) ) );
    CHECK( gm::Contains( range, gm::Vec4i( 4, 4, 4, 4 ) ) );
    CHECK( !gm::Contains( range, gm::Vec4i( -3, -3, -3, -3 ) ) );
    CHECK( !gm::Contains( range, gm::Vec4i( 5, 5, 5, 5 ) ) );
}

TEST_CASE( "Contains_Vec4iRange_Vec4iRange" )
{
    gm::Vec4iRange range(
        /* min */ gm::Vec4i( -2, -2, -2, -2 ),
        /* max */ gm::Vec4i( 4, 4, 4, 4 ) );
    CHECK( gm::Contains( range, gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 3, 3, 3, 3 ) ) ) );
    CHECK( gm::Contains( range, gm::Vec4iRange( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 2, 2, 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec4iRange( gm::Vec4i( -3, -3, -3, -3 ), gm::Vec4i( 2, 2, 2, 2 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec4iRange( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 5, 5, 5, 5 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec4iRange( gm::Vec4i( 7, 7, 7, 7 ), gm::Vec4i( 10, 10, 10, 10 ) ) ) );
    CHECK( !gm::Contains( range, gm::Vec4iRange( gm::Vec4i( -5, -5, -5, -5 ), gm::Vec4i( -4, -4, -4, -4 ) ) ) );
}
