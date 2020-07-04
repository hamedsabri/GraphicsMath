//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec3iRange.h>

// Python bindings for Vec3iRange.

GM_NS_USING

void BindVec3iRange( pybind11::module& o_module )
{
    pybind11::class_< Vec3iRange > cls( o_module, "Vec3iRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec3i&, const Vec3i& >() );
}