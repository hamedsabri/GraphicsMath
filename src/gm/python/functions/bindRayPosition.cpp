//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/rayPosition.h>

// Python bindings for RayPosition.

GM_NS_USING

void BindRayPosition( pybind11::module& o_module )
{
    o_module.def( "RayPosition", []( const Vec2f& i_origin, const Vec2f& i_direction, const float& i_magnitude ) {
        return RayPosition( i_origin, i_direction, i_magnitude );
    } );
    o_module.def( "RayPosition", []( const Vec3f& i_origin, const Vec3f& i_direction, const float& i_magnitude ) {
        return RayPosition( i_origin, i_direction, i_magnitude );
    } );
}