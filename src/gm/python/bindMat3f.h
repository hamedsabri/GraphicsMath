#include <pybind11/pybind11.h>

#include <gm/types/mat3f.h>

void BindMat3f( pybind11::module& o_module )
{
    pybind11::class_< gm::Mat3f >( o_module, "Mat3f" ).def( pybind11::init<>() );
}