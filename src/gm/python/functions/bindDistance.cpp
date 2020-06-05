//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/distance.h>

// Python bindings for Distance.

GM_NS_USING

void BindDistance( pybind11::module& o_module )
{
    o_module.def( "Distance",
                  []( const Vec2f& i_pointA, const Vec2f& i_pointB ) { return Distance( i_pointA, i_pointB ); } );
    o_module.def( "Distance",
                  []( const Vec3f& i_pointA, const Vec3f& i_pointB ) { return Distance( i_pointA, i_pointB ); } );
}