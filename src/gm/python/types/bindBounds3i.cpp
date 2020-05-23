//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds3i.h>

// Python bindings for Bounds3i.

GM_NS_USING

void BindBounds3i( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds3i > cls( o_module, "Bounds3i" );

    // Default initializer.
    cls.def( pybind11::init<>() );
}