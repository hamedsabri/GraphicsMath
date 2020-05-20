#include <pybind11/pybind11.h>

#include <gm/types/vec2f.h>

void BindVec2f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec2f >( o_module, "Vec2f" ).def( pybind11::init<>() );
}