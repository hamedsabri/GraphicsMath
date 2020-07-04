//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2fRange.h>

// Python bindings for Vec2fRange.

GM_NS_USING

void BindVec2fRange( pybind11::module& o_module )
{
    pybind11::class_< Vec2fRange > cls( o_module, "Vec2fRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec2f&, const Vec2f& >() );
}