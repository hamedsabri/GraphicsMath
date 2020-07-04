//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/intRange.h>

// Python bindings for IntRange.

GM_NS_USING

void BindIntRange( pybind11::module& o_module )
{
    pybind11::class_< IntRange > cls( o_module, "IntRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const int&, const int& >() );
}