//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/intArray.h>

// Python bindings for IntArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( IntArray );

void BindIntArray( pybind11::module& o_module )
{
    pybind11::bind_vector< IntArray >( o_module, "IntArray" );
}