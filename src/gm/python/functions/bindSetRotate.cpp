//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setRotate.h>

// Python bindings for SetRotate.

GM_NS_USING

void BindSetRotate( pybind11::module& o_module )
{
    o_module.def( "SetRotate", []( const float& i_angle, const Vec3f& i_axis, Mat4f& o_matrix ) {
        SetRotate( i_angle, i_axis, o_matrix );
    } );
}