//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/intersection.h>

// Python bindings for Intersection.

GM_NS_USING

void BindIntersection( pybind11::module& o_module )
{
    o_module.def( "Intersection",
                  []( const FloatRange& i_lhs, const FloatRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const IntRange& i_lhs, const IntRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec2fRange& i_lhs, const Vec2fRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec3fRange& i_lhs, const Vec3fRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec4fRange& i_lhs, const Vec4fRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec2iRange& i_lhs, const Vec2iRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec3iRange& i_lhs, const Vec3iRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
    o_module.def( "Intersection",
                  []( const Vec4iRange& i_lhs, const Vec4iRange& i_rhs ) { return Intersection( i_lhs, i_rhs ); } );
}