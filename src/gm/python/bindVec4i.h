#include <pybind11/pybind11.h>

#include <gm/types/vec4i.h>

void BindVec4i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec4i >( o_module, "Vec4i" ).def( pybind11::init<>() );
}