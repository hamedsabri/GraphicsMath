//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4fRange.h>

// Python bindings for Vec4fRange.

GM_NS_USING

void BindVec4fRange( pybind11::module& o_module )
{
    pybind11::class_< Vec4fRange > cls( o_module, "Vec4fRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec4f&, const Vec4f& >() );
}