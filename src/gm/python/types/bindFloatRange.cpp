//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/floatRange.h>

// Python bindings for FloatRange.

GM_NS_USING

void BindFloatRange( pybind11::module& o_module )
{
    pybind11::class_< FloatRange > cls( o_module, "FloatRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const float&, const float& >() );
}