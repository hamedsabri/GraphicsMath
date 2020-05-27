//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/length.h>

// Python bindings for Length.

GM_NS_USING

void BindLength( pybind11::module& o_module )
{
    o_module.def( "Length", []( const Vec2f& i_vector ) { return Length( i_vector ); } );
    o_module.def( "Length", []( const Vec3f& i_vector ) { return Length( i_vector ); } );
    o_module.def( "Length", []( const Vec4f& i_vector ) { return Length( i_vector ); } );
}