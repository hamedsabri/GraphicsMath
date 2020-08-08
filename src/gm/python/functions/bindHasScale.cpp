//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/hasScale.h>

// Python bindings for HasScale.

GM_NS_USING

void BindHasScale( pybind11::module& o_module )
{
    o_module.def( "HasScale", []( const Mat3f& i_matrix ) { return HasScale( i_matrix ); } );
    o_module.def( "HasScale", []( const Mat4f& i_matrix ) { return HasScale( i_matrix ); } );
}