//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setIdentity.h>

// Python bindings for SetIdentity.

GM_NS_USING

void BindSetIdentity( pybind11::module& o_module )
{
    o_module.def( "SetIdentity", []( Mat3f& o_matrix ) { SetIdentity( o_matrix ); } );
    o_module.def( "SetIdentity", []( Mat4f& o_matrix ) { SetIdentity( o_matrix ); } );
}