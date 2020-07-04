//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/boolArray.h>

// Python bindings for BoolArray.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( BoolArray );

void BindBoolArray( pybind11::module& o_module )
{
    pybind11::bind_vector< BoolArray >( o_module, "BoolArray" );
}