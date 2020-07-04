//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/mat3fArray.h>

// Python bindings for Mat3fArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Mat3fArray );

void BindMat3fArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Mat3fArray >( o_module, "Mat3fArray" );
}