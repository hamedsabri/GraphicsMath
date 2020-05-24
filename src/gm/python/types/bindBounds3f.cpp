//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds3f.h>

// Python bindings for Bounds3f.

GM_NS_USING

void BindBounds3f( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds3f > cls( o_module, "Bounds3f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec3f&, const Vec3f& >() );
}