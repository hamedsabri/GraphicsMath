//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec2fArray.h>

// Python bindings for Vec2fArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec2fArray );

void BindVec2fArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec2fArray >( o_module, "Vec2fArray" );
}