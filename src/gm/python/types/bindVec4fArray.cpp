//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec4fArray.h>

// Python bindings for Vec4fArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec4fArray );

void BindVec4fArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec4fArray >( o_module, "Vec4fArray" );
}