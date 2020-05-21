//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/mat3f.h>

// Python bindings for Mat3f.

void BindMat3f( pybind11::module& o_module )
{
    pybind11::class_< gm::Mat3f > cls( o_module, "Mat3f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float& >() );
}