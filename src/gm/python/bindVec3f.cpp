//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec3f.h>

// Python bindings for Vec3f.

void BindVec3f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec3f > cls( o_module, "Vec3f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&, const float&, const float& >() );
}