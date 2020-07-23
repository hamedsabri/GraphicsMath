//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setRotateX.h>

// Python bindings for SetRotateX.

GM_NS_USING

void BindSetRotateX( pybind11::module& o_module )
{
    o_module.def( "SetRotateX", []( const float& i_angle, Mat4f& o_matrix ) { SetRotateX( i_angle, o_matrix ); } );
}