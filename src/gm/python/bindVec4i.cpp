//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4i.h>

// Python bindings for Vec4i.

void BindVec4i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec4i > cls( o_module, "Vec4i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const int&, const int&, const int&, const int& >() );
}