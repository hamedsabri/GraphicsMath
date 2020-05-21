#include <pybind11/pybind11.h>

#include <gm/types/vec3f.h>

void BindVec3f( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec3f > cls( o_module, "Vec3f" );
    cls.def( pybind11::init<>() );
    cls.def( pybind11::init< const float&, const float&, const float& >() );
}