//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/raySphereIntersection.h>

// Python bindings for RaySphereIntersection.

GM_NS_USING

void BindRaySphereIntersection( pybind11::module& o_module )
{
    o_module.def( "RaySphereIntersection",
                  []( const Vec3f& i_sphereOrigin,
                      const float& i_sphereRadius,
                      const Vec3f& i_rayOrigin,
                      const Vec3f& i_rayDirection,
                      float&       o_firstIntersection,
                      float&       o_secondIntersection ) {
                      return RaySphereIntersection( i_sphereOrigin,
                                                    i_sphereRadius,
                                                    i_rayOrigin,
                                                    i_rayDirection,
                                                    o_firstIntersection,
                                                    o_secondIntersection );
                  } );
}