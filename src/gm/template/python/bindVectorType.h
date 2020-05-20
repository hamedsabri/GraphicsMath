#include <pybind11/pybind11.h>

#include <gm/types/{{ vectorType.headerFileName }}>

void Bind{{ vectorType.className }}( pybind11::module& o_module )
{
    pybind11::class_< gm::{{ vectorType.className }} >( o_module, "{{ vectorType.className }}" )
        .def( pybind11::init<>() );
}
