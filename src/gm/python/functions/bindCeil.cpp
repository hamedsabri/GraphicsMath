//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/ceil.h>

// Python bindings for Ceil.

GM_NS_USING

void BindCeil( pybind11::module& o_module )
{
    o_module.def( "Ceil", []( const float& i_value ) { return Ceil( i_value ); } );
    o_module.def( "Ceil", []( const Vec2f& i_value ) { return Ceil( i_value ); } );
    o_module.def( "Ceil", []( const Vec3f& i_value ) { return Ceil( i_value ); } );
    o_module.def( "Ceil", []( const Vec4f& i_value ) { return Ceil( i_value ); } );
    o_module.def( "Ceil", []( const Mat3f& i_value ) { return Ceil( i_value ); } );
    o_module.def( "Ceil", []( const Mat4f& i_value ) { return Ceil( i_value ); } );
}