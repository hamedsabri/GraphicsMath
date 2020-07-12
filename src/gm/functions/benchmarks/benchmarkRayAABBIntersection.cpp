//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/rayAABBIntersection.h>

TEST_CASE( "RayAABBIntersection_Vec2f_Vec2f_Vec2fRange_FloatRange" )
{
    gm::Vec2f      rayOrigin;
    gm::Vec2f      rayDirection;
    gm::Vec2fRange aabb;
    gm::FloatRange intersections;
    BENCHMARK( "RayAABBIntersection" )
    {
        return gm::RayAABBIntersection( rayOrigin, rayDirection, aabb, intersections );
    };
}

TEST_CASE( "RayAABBIntersection_Vec3f_Vec3f_Vec3fRange_FloatRange" )
{
    gm::Vec3f      rayOrigin;
    gm::Vec3f      rayDirection;
    gm::Vec3fRange aabb;
    gm::FloatRange intersections;
    BENCHMARK( "RayAABBIntersection" )
    {
        return gm::RayAABBIntersection( rayOrigin, rayDirection, aabb, intersections );
    };
}

TEST_CASE( "RayAABBIntersection_Vec4f_Vec4f_Vec4fRange_FloatRange" )
{
    gm::Vec4f      rayOrigin;
    gm::Vec4f      rayDirection;
    gm::Vec4fRange aabb;
    gm::FloatRange intersections;
    BENCHMARK( "RayAABBIntersection" )
    {
        return gm::RayAABBIntersection( rayOrigin, rayDirection, aabb, intersections );
    };
}
