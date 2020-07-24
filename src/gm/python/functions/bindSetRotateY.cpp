//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setRotateY.h>

// Python bindings for SetRotateY.

GM_NS_USING

void BindSetRotateY( pybind11::module& o_module )
{
    o_module.def( "SetRotateY", []( const float& i_angle, Mat4f& o_matrix ) { SetRotateY( i_angle, o_matrix ); } );
}