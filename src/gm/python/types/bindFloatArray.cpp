//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/floatArray.h>

// Python bindings for FloatArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( FloatArray );

void BindFloatArray( pybind11::module& o_module )
{
    pybind11::bind_vector< FloatArray >( o_module, "FloatArray" );
}