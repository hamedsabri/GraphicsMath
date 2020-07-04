#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/{{ valueType.headerFileName }}>

// Python bindings for {{ valueType.className }}.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( {{ valueType.className }} );

void Bind{{ valueType.className }}( pybind11::module& o_module )
{
    pybind11::bind_vector< {{ valueType.className }} >(o_module, "{{ valueType.className }}");
}
