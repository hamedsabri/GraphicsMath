#include <pybind11/pybind11.h>

#include <gm/types/vec3i.h>

void BindVec3i( pybind11::module& o_module )
{
    pybind11::class_< gm::Vec3i >( o_module, "Vec3i" ).def( pybind11::init<>() );
}