//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/mat4fArray.h>

// Python bindings for Mat4fArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Mat4fArray );

void BindMat4fArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Mat4fArray >( o_module, "Mat4fArray" );
}