//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/transpose.h>

// Python bindings for Transpose.

GM_NS_USING

void BindTranspose( pybind11::module& o_module )
{
    o_module.def( "Transpose", []( const Mat3f& i_matrix ) { return Transpose( i_matrix ); } );
    o_module.def( "Transpose", []( const Mat4f& i_matrix ) { return Transpose( i_matrix ); } );
}