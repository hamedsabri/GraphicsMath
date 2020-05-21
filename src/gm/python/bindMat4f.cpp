#include <pybind11/pybind11.h>

#include <gm/types/mat4f.h>

void BindMat4f( pybind11::module& o_module )
{
    pybind11::class_< gm::Mat4f > cls( o_module, "Mat4f" );
    cls.def( pybind11::init<>() );
    cls.def( pybind11::init< const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float& >() );
}