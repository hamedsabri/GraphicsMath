//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2i.h>

// Python bindings for Vec2i.

void BindVec2i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec2i > cls( o_module, "Vec2i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const int&, const int& >() );
}