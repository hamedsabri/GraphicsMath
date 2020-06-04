//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/abs.h>

// Python bindings for Abs.

GM_NS_USING

void BindAbs( pybind11::module& o_module )
{
    o_module.def( "Abs", []( const float& i_value ) { return Abs( i_value ); } );
    o_module.def( "Abs", []( const Vec2f& i_value ) { return Abs( i_value ); } );
    o_module.def( "Abs", []( const Vec3f& i_value ) { return Abs( i_value ); } );
    o_module.def( "Abs", []( const Vec4f& i_value ) { return Abs( i_value ); } );
    o_module.def( "Abs", []( const Mat3f& i_value ) { return Abs( i_value ); } );
    o_module.def( "Abs", []( const Mat4f& i_value ) { return Abs( i_value ); } );
}