//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec3iArray.h>

// Python bindings for Vec3iArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec3iArray );

void BindVec3iArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec3iArray >( o_module, "Vec3iArray" );
}