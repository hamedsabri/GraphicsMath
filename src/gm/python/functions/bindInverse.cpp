//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/inverse.h>

// Python bindings for Inverse.

GM_NS_USING

void BindInverse( pybind11::module& o_module )
{
    o_module.def( "Inverse", []( const Mat4f& i_matrix, Mat4f& o_inverse ) { return Inverse( i_matrix, o_inverse ); } );
}