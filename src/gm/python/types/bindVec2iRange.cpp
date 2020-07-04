//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2iRange.h>

// Python bindings for Vec2iRange.

GM_NS_USING

void BindVec2iRange( pybind11::module& o_module )
{
    pybind11::class_< Vec2iRange > cls( o_module, "Vec2iRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec2i&, const Vec2i& >() );
}