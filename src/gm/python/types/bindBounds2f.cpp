//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds2f.h>

// Python bindings for Bounds2f.

GM_NS_USING

void BindBounds2f( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds2f > cls( o_module, "Bounds2f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec2f&, const Vec2f& >() );
}