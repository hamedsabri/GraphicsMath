#include <pybind11/pybind11.h>

#include <gm/types/vec4f.h>

void BindVec4f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec4f > cls( o_module, "Vec4f" );
    cls.def( pybind11::init<>() );
    cls.def( pybind11::init< const float&, const float&, const float&, const float& >() );
}