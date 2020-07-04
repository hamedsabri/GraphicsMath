//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec3fRange.h>

// Python bindings for Vec3fRange.

GM_NS_USING

void BindVec3fRange( pybind11::module& o_module )
{
    pybind11::class_< Vec3fRange > cls( o_module, "Vec3fRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec3f&, const Vec3f& >() );
}