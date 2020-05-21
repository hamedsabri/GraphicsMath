//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4f.h>

// Python bindings for Vec4f.

void BindVec4f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec4f > cls( o_module, "Vec4f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&, const float&, const float&, const float& >() );
}