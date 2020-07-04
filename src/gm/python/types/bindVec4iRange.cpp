//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4iRange.h>

// Python bindings for Vec4iRange.

GM_NS_USING

void BindVec4iRange( pybind11::module& o_module )
{
    pybind11::class_< Vec4iRange > cls( o_module, "Vec4iRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec4i&, const Vec4i& >() );
}