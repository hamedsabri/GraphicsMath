#include <pybind11/pybind11.h>

#include <gm/types/vec2i.h>

void BindVec2i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec2i > cls( o_module, "Vec2i" );
    cls.def( pybind11::init<>() );
    cls.def( pybind11::init< const int&, const int& >() );
}