//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/isIdentity.h>

// Python bindings for IsIdentity.

GM_NS_USING

void BindIsIdentity( pybind11::module& o_module )
{
    o_module.def( "IsIdentity", []( const Mat3f& i_matrix ) { return IsIdentity( i_matrix ); } );
    o_module.def( "IsIdentity", []( const Mat4f& i_matrix ) { return IsIdentity( i_matrix ); } );
}