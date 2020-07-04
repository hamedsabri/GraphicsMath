//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec4iArray.h>

// Python bindings for Vec4iArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec4iArray );

void BindVec4iArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec4iArray >( o_module, "Vec4iArray" );
}