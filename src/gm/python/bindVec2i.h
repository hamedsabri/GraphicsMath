#include <pybind11/pybind11.h>

#include <gm/types/vec2i.h>

void BindVec2i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec2i >( o_module, "Vec2i" ).def( pybind11::init<>() );
}