//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/min.h>

// Python bindings for Min.

GM_NS_USING

void BindMin( pybind11::module& o_module )
{
    o_module.def( "Min", []( const float& i_valueA, const float& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const int& i_valueA, const int& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Mat3f& i_valueA, const Mat3f& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Mat4f& i_valueA, const Mat4f& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec2f& i_valueA, const Vec2f& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec3f& i_valueA, const Vec3f& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec4f& i_valueA, const Vec4f& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec2i& i_valueA, const Vec2i& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec3i& i_valueA, const Vec3i& i_valueB ) { return Min( i_valueA, i_valueB ); } );
    o_module.def( "Min", []( const Vec4i& i_valueA, const Vec4i& i_valueB ) { return Min( i_valueA, i_valueB ); } );
}