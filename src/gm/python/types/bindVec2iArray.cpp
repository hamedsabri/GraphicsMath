//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/vec2iArray.h>

// Python bindings for Vec2iArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( Vec2iArray );

void BindVec2iArray( pybind11::module& o_module )
{
    pybind11::bind_vector< Vec2iArray >( o_module, "Vec2iArray" );
}