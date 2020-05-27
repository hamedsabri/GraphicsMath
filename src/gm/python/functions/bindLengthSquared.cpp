//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/lengthSquared.h>

// Python bindings for LengthSquared.

GM_NS_USING

void BindLengthSquared( pybind11::module& o_module )
{
    o_module.def( "LengthSquared", []( const Vec2f& i_vector ) { return LengthSquared( i_vector ); } );
    o_module.def( "LengthSquared", []( const Vec3f& i_vector ) { return LengthSquared( i_vector ); } );
    o_module.def( "LengthSquared", []( const Vec4f& i_vector ) { return LengthSquared( i_vector ); } );
}