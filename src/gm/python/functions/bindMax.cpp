//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/max.h>

// Python bindings for Max.

GM_NS_USING

void BindMax( pybind11::module& o_module )
{
    o_module.def( "Max", []( const float& i_valueA, const float& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const int& i_valueA, const int& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Mat3f& i_valueA, const Mat3f& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Mat4f& i_valueA, const Mat4f& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec2f& i_valueA, const Vec2f& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec3f& i_valueA, const Vec3f& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec4f& i_valueA, const Vec4f& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec2i& i_valueA, const Vec2i& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec3i& i_valueA, const Vec3i& i_valueB ) { return Max( i_valueA, i_valueB ); } );
    o_module.def( "Max", []( const Vec4i& i_valueA, const Vec4i& i_valueB ) { return Max( i_valueA, i_valueB ); } );
}