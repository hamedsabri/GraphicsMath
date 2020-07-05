//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/clamp.h>

// Python bindings for Clamp.

GM_NS_USING

void BindClamp( pybind11::module& o_module )
{
    o_module.def( "Clamp",
                  []( const float& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp", []( const int& i_value, const IntRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp",
                  []( const Mat3f& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp",
                  []( const Mat4f& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp",
                  []( const Vec2f& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp",
                  []( const Vec3f& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp",
                  []( const Vec4f& i_value, const FloatRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp", []( const Vec2i& i_value, const IntRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp", []( const Vec3i& i_value, const IntRange& i_range ) { return Clamp( i_value, i_range ); } );
    o_module.def( "Clamp", []( const Vec4i& i_value, const IntRange& i_range ) { return Clamp( i_value, i_range ); } );
}