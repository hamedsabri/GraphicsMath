//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec3fArray.h>

// Python bindings for Vec3fArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec3fArray );

void BindVec3fArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec3fArray >( o_module, "Vec3fArray" );
}