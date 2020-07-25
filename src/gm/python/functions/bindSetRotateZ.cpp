//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setRotateZ.h>

// Python bindings for SetRotateZ.

GM_NS_USING

void BindSetRotateZ( pybind11::module& o_module )
{
    o_module.def( "SetRotateZ", []( const float& i_angle, Mat4f& o_matrix ) { SetRotateZ( i_angle, o_matrix ); } );
}