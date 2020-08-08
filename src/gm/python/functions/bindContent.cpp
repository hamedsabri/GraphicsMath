//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/content.h>

// Python bindings for Content.

GM_NS_USING

void BindContent( pybind11::module& o_module )
{
    o_module.def( "Content", []( const FloatRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const IntRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec2fRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec3fRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec4fRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec2iRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec3iRange& i_range ) { return Content( i_range ); } );
    o_module.def( "Content", []( const Vec4iRange& i_range ) { return Content( i_range ); } );
}