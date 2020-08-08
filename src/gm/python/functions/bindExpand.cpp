//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/expand.h>

// Python bindings for Expand.

GM_NS_USING

void BindExpand( pybind11::module& o_module )
{
    o_module.def( "Expand", []( const FloatRange& i_lhs, const FloatRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const FloatRange& i_lhs, const float& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const IntRange& i_lhs, const IntRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const IntRange& i_lhs, const int& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec2fRange& i_lhs, const Vec2fRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec2fRange& i_lhs, const Vec2f& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec3fRange& i_lhs, const Vec3fRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec3fRange& i_lhs, const Vec3f& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec4fRange& i_lhs, const Vec4fRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec4fRange& i_lhs, const Vec4f& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec2iRange& i_lhs, const Vec2iRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec2iRange& i_lhs, const Vec2i& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec3iRange& i_lhs, const Vec3iRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec3iRange& i_lhs, const Vec3i& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec4iRange& i_lhs, const Vec4iRange& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
    o_module.def( "Expand", []( const Vec4iRange& i_lhs, const Vec4i& i_rhs ) { return Expand( i_lhs, i_rhs ); } );
}