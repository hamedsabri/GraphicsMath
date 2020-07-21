//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/longestAxis.h>

// Python bindings for LongestAxis.

GM_NS_USING

void BindLongestAxis( pybind11::module& o_module )
{
    o_module.def( "LongestAxis", []( const Vec2fRange& i_range ) { return LongestAxis( i_range ); } );
    o_module.def( "LongestAxis", []( const Vec3fRange& i_range ) { return LongestAxis( i_range ); } );
    o_module.def( "LongestAxis", []( const Vec4fRange& i_range ) { return LongestAxis( i_range ); } );
    o_module.def( "LongestAxis", []( const Vec2iRange& i_range ) { return LongestAxis( i_range ); } );
    o_module.def( "LongestAxis", []( const Vec3iRange& i_range ) { return LongestAxis( i_range ); } );
    o_module.def( "LongestAxis", []( const Vec4iRange& i_range ) { return LongestAxis( i_range ); } );
}