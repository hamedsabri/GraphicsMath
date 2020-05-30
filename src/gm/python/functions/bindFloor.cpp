//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/floor.h>

// Python bindings for Floor.

GM_NS_USING

void BindFloor( pybind11::module& o_module )
{
    o_module.def( "Floor", []( const float& i_value ) { return Floor( i_value ); } );
    o_module.def( "Floor", []( const Vec2f& i_value ) { return Floor( i_value ); } );
    o_module.def( "Floor", []( const Vec3f& i_value ) { return Floor( i_value ); } );
    o_module.def( "Floor", []( const Vec4f& i_value ) { return Floor( i_value ); } );
    o_module.def( "Floor", []( const Mat3f& i_value ) { return Floor( i_value ); } );
    o_module.def( "Floor", []( const Mat4f& i_value ) { return Floor( i_value ); } );
}