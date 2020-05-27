//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/dotProduct.h>

// Python bindings for DotProduct.

GM_NS_USING

void BindDotProduct( pybind11::module& o_module )
{
    o_module.def( "DotProduct", []( const Vec2f& i_lhs, const Vec2f& i_rhs ) { return DotProduct( i_lhs, i_rhs ); } );
    o_module.def( "DotProduct", []( const Vec3f& i_lhs, const Vec3f& i_rhs ) { return DotProduct( i_lhs, i_rhs ); } );
    o_module.def( "DotProduct", []( const Vec4f& i_lhs, const Vec4f& i_rhs ) { return DotProduct( i_lhs, i_rhs ); } );
}