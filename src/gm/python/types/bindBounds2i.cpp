//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds2i.h>

// Python bindings for Bounds2i.

GM_NS_USING

void BindBounds2i( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds2i > cls( o_module, "Bounds2i" );

    // Default initializer.
    cls.def( pybind11::init<>() );
}