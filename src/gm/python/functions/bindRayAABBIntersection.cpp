//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/rayAABBIntersection.h>

// Python bindings for RayAABBIntersection.

GM_NS_USING

void BindRayAABBIntersection( pybind11::module& o_module )
{
    o_module.def( "RayAABBIntersection",
                  []( const Vec2f&      i_rayOrigin,
                      const Vec2f&      i_rayDirection,
                      const Vec2fRange& i_aabb,
                      FloatRange&       o_intersections ) {
                      return RayAABBIntersection( i_rayOrigin, i_rayDirection, i_aabb, o_intersections );
                  } );
    o_module.def( "RayAABBIntersection",
                  []( const Vec3f&      i_rayOrigin,
                      const Vec3f&      i_rayDirection,
                      const Vec3fRange& i_aabb,
                      FloatRange&       o_intersections ) {
                      return RayAABBIntersection( i_rayOrigin, i_rayDirection, i_aabb, o_intersections );
                  } );
    o_module.def( "RayAABBIntersection",
                  []( const Vec4f&      i_rayOrigin,
                      const Vec4f&      i_rayDirection,
                      const Vec4fRange& i_aabb,
                      FloatRange&       o_intersections ) {
                      return RayAABBIntersection( i_rayOrigin, i_rayDirection, i_aabb, o_intersections );
                  } );
}