//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/normalize.h>

// Python bindings for Normalize.

GM_NS_USING

void BindNormalize( pybind11::module& o_module )
{
    o_module.def( "Normalize", []( const Vec2f& i_vector ) { return Normalize( i_vector ); } );
    o_module.def( "Normalize", []( const Vec3f& i_vector ) { return Normalize( i_vector ); } );
    o_module.def( "Normalize", []( const Vec4f& i_vector ) { return Normalize( i_vector ); } );
}