//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/normalize.h>
#include <gm/functions/rayAABBIntersection.h>

TEST_CASE( "RayAABBIntersection_Vec2fRange" )
{
    // Bounding volume.
    gm::Vec2fRange aabb = gm::Vec2fRange(
        gm::Vec2f( -2.0f, -2.0f ),
        gm::Vec2f( 2.0f, 2.0f ) ); // -------------------------------------------------------------------------
    // Test values with applied scaling factor of -1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 4.0f, 4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 1.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 4.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 5.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 4.0f, 0.0f ),
            /* rayDirection */ gm::Vec2f( -1.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( 4.0f, 4.0f ),
            /* rayDirection */ gm::Vec2f( -1.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    } // -------------------------------------------------------------------------
    // Test values with applied scaling factor of 1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -4.0f, -4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -1.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -4.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -5.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec2f( 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -4.0f, 0.0f ),
            /* rayDirection */ gm::Vec2f( 1.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec2f( -4.0f, -4.0f ),
            /* rayDirection */ gm::Vec2f( 1.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }
}

TEST_CASE( "RayAABBIntersection_Vec3fRange" )
{
    // Bounding volume.
    gm::Vec3fRange aabb = gm::Vec3fRange(
        gm::Vec3f( -2.0f, -2.0f, -2.0f ),
        gm::Vec3f( 2.0f, 2.0f, 2.0f ) ); // -------------------------------------------------------------------------
    // Test values with applied scaling factor of -1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 4.0f, 4.0f, 4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 1.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 4.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 5.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 4.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Vec3f( -1.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( 4.0f, 4.0f, 4.0f ),
            /* rayDirection */ gm::Vec3f( -1.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    } // -------------------------------------------------------------------------
    // Test values with applied scaling factor of 1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -4.0f, -4.0f, -4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -1.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -4.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -5.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec3f( 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -4.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Vec3f( 1.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec3f( -4.0f, -4.0f, -4.0f ),
            /* rayDirection */ gm::Vec3f( 1.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }
}

TEST_CASE( "RayAABBIntersection_Vec4fRange" )
{
    // Bounding volume.
    gm::Vec4fRange aabb = gm::Vec4fRange(
        gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ),
        gm::Vec4f( 2.0f,
                   2.0f,
                   2.0f,
                   2.0f ) ); // -------------------------------------------------------------------------
    // Test values with applied scaling factor of -1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 1.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 4.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 5.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( -1.0f, -1.0f, -1.0f, -1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 4.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Vec4f( -1.0f, 0.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f ),
            /* rayDirection */ gm::Vec4f( -1.0f, 0.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    } // -------------------------------------------------------------------------
    // Test values with applied scaling factor of 1.
    // -------------------------------------------------------------------------

    //
    // Multi-axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -4.0f, -4.0f, -4.0f, -4.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Ray origin inside aabb.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -1.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // Skim intersection
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -4.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -5.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Normalize( gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f ) ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    //
    // Single axis.
    //

    // Volume intersection.
    {
        gm::FloatRange intersections;
        CHECK( gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -4.0f, 0.0f, 0.0f, 0.0f ),
            /* rayDirection */ gm::Vec4f( 1.0f, 0.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }

    // No intersection.
    {
        gm::FloatRange intersections;
        CHECK( !gm::RayAABBIntersection(
            /* rayOrigin */ gm::Vec4f( -4.0f, -4.0f, -4.0f, -4.0f ),
            /* rayDirection */ gm::Vec4f( 1.0f, 0.0f, 0.0f, 0.0f ),
            /* aabb */ aabb,
            /* intersections */ intersections ) );
    }
}
