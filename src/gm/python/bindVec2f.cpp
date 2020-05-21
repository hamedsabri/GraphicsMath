//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2f.h>

// Python bindings for Vec2f.

void BindVec2f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec2f > cls( o_module, "Vec2f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&, const float& >() );
}