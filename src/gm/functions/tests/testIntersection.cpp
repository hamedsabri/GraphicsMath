//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/intersection.h>

TEST_CASE( "Intersection_FloatRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::FloatRange( -2.0f, 2.0f ), gm::FloatRange( -3.0f, -1.0f ) ) ==
           gm::FloatRange( -2.0f, -1.0f ) );
    CHECK( gm::Intersection( gm::FloatRange( -2.0f, 2.0f ), gm::FloatRange( -1.0f, 1.0f ) ) ==
           gm::FloatRange( -1.0f, 1.0f ) );

    // Empty.
    CHECK( gm::Intersection( gm::FloatRange( -2.0f, 2.0f ), gm::FloatRange( -5.0f, -3.0f ) ).IsEmpty() );
    CHECK( gm::Intersection( gm::FloatRange( -2.0f, 2.0f ), gm::FloatRange( 1.0f, -1.0f ) ).IsEmpty() );
}

TEST_CASE( "Intersection_IntRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::IntRange( -2, 2 ), gm::IntRange( -3, -1 ) ) == gm::IntRange( -2, -1 ) );
    CHECK( gm::Intersection( gm::IntRange( -2, 2 ), gm::IntRange( -1, 1 ) ) == gm::IntRange( -1, 1 ) );

    // Empty.
    CHECK( gm::Intersection( gm::IntRange( -2, 2 ), gm::IntRange( -5, -3 ) ).IsEmpty() );
    CHECK( gm::Intersection( gm::IntRange( -2, 2 ), gm::IntRange( 1, -1 ) ).IsEmpty() );
}

TEST_CASE( "Intersection_Vec2fRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ),
                             gm::Vec2fRange( gm::Vec2f( -3.0f, -3.0f ), gm::Vec2f( -1.0f, -1.0f ) ) ) ==
           gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( -1.0f, -1.0f ) ) );
    CHECK( gm::Intersection( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ),
                             gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 1.0f, 1.0f ) ) ) ==
           gm::Vec2fRange( gm::Vec2f( -1.0f, -1.0f ), gm::Vec2f( 1.0f, 1.0f ) ) );

    // Empty.
    CHECK( gm::Intersection( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ),
                             gm::Vec2fRange( gm::Vec2f( -5.0f, -5.0f ), gm::Vec2f( -3.0f, -3.0f ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection( gm::Vec2fRange( gm::Vec2f( -2.0f, -2.0f ), gm::Vec2f( 2.0f, 2.0f ) ),
                             gm::Vec2fRange( gm::Vec2f( 1.0f, 1.0f ), gm::Vec2f( -1.0f, -1.0f ) ) )
               .IsEmpty() );
}

TEST_CASE( "Intersection_Vec3fRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ),
                             gm::Vec3fRange( gm::Vec3f( -3.0f, -3.0f, -3.0f ), gm::Vec3f( -1.0f, -1.0f, -1.0f ) ) ) ==
           gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( -1.0f, -1.0f, -1.0f ) ) );
    CHECK( gm::Intersection( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ),
                             gm::Vec3fRange( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 1.0f, 1.0f, 1.0f ) ) ) ==
           gm::Vec3fRange( gm::Vec3f( -1.0f, -1.0f, -1.0f ), gm::Vec3f( 1.0f, 1.0f, 1.0f ) ) );

    // Empty.
    CHECK( gm::Intersection( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ),
                             gm::Vec3fRange( gm::Vec3f( -5.0f, -5.0f, -5.0f ), gm::Vec3f( -3.0f, -3.0f, -3.0f ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection( gm::Vec3fRange( gm::Vec3f( -2.0f, -2.0f, -2.0f ), gm::Vec3f( 2.0f, 2.0f, 2.0f ) ),
                             gm::Vec3fRange( gm::Vec3f( 1.0f, 1.0f, 1.0f ), gm::Vec3f( -1.0f, -1.0f, -1.0f ) ) )
               .IsEmpty() );
}

TEST_CASE( "Intersection_Vec4fRange" )
{
    // Overlaps.
    CHECK( gm::Intersection(
               gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ),
               gm::Vec4fRange( gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ), gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ) ) ==
           gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ) );
    CHECK( gm::Intersection(
               gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ),
               gm::Vec4fRange( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ) ) ==
           gm::Vec4fRange( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ), gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ) );

    // Empty.
    CHECK( gm::Intersection(
               gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ),
               gm::Vec4fRange( gm::Vec4f( -5.0f, -5.0f, -5.0f, -5.0f ), gm::Vec4f( -3.0f, -3.0f, -3.0f, -3.0f ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection(
               gm::Vec4fRange( gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ), gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ),
               gm::Vec4fRange( gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ), gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ) )
               .IsEmpty() );
}

TEST_CASE( "Intersection_Vec2iRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ),
                             gm::Vec2iRange( gm::Vec2i( -3, -3 ), gm::Vec2i( -1, -1 ) ) ) ==
           gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( -1, -1 ) ) );
    CHECK( gm::Intersection( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ),
                             gm::Vec2iRange( gm::Vec2i( -1, -1 ), gm::Vec2i( 1, 1 ) ) ) ==
           gm::Vec2iRange( gm::Vec2i( -1, -1 ), gm::Vec2i( 1, 1 ) ) );

    // Empty.
    CHECK( gm::Intersection( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ),
                             gm::Vec2iRange( gm::Vec2i( -5, -5 ), gm::Vec2i( -3, -3 ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection( gm::Vec2iRange( gm::Vec2i( -2, -2 ), gm::Vec2i( 2, 2 ) ),
                             gm::Vec2iRange( gm::Vec2i( 1, 1 ), gm::Vec2i( -1, -1 ) ) )
               .IsEmpty() );
}

TEST_CASE( "Intersection_Vec3iRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ),
                             gm::Vec3iRange( gm::Vec3i( -3, -3, -3 ), gm::Vec3i( -1, -1, -1 ) ) ) ==
           gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( -1, -1, -1 ) ) );
    CHECK( gm::Intersection( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ),
                             gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 1, 1, 1 ) ) ) ==
           gm::Vec3iRange( gm::Vec3i( -1, -1, -1 ), gm::Vec3i( 1, 1, 1 ) ) );

    // Empty.
    CHECK( gm::Intersection( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ),
                             gm::Vec3iRange( gm::Vec3i( -5, -5, -5 ), gm::Vec3i( -3, -3, -3 ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection( gm::Vec3iRange( gm::Vec3i( -2, -2, -2 ), gm::Vec3i( 2, 2, 2 ) ),
                             gm::Vec3iRange( gm::Vec3i( 1, 1, 1 ), gm::Vec3i( -1, -1, -1 ) ) )
               .IsEmpty() );
}

TEST_CASE( "Intersection_Vec4iRange" )
{
    // Overlaps.
    CHECK( gm::Intersection( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ),
                             gm::Vec4iRange( gm::Vec4i( -3, -3, -3, -3 ), gm::Vec4i( -1, -1, -1, -1 ) ) ) ==
           gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( -1, -1, -1, -1 ) ) );
    CHECK( gm::Intersection( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ),
                             gm::Vec4iRange( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 1, 1, 1, 1 ) ) ) ==
           gm::Vec4iRange( gm::Vec4i( -1, -1, -1, -1 ), gm::Vec4i( 1, 1, 1, 1 ) ) );

    // Empty.
    CHECK( gm::Intersection( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ),
                             gm::Vec4iRange( gm::Vec4i( -5, -5, -5, -5 ), gm::Vec4i( -3, -3, -3, -3 ) ) )
               .IsEmpty() );
    CHECK( gm::Intersection( gm::Vec4iRange( gm::Vec4i( -2, -2, -2, -2 ), gm::Vec4i( 2, 2, 2, 2 ) ),
                             gm::Vec4iRange( gm::Vec4i( 1, 1, 1, 1 ), gm::Vec4i( -1, -1, -1, -1 ) ) )
               .IsEmpty() );
}
