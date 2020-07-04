#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include <gm/types/{{ arrayType.headerFileName }}>

// Python bindings for {{ arrayType.className }}.

GM_NS_USING

PYBIND11_MAKE_OPAQUE( {{ arrayType.className }} );

void Bind{{ arrayType.className }}( pybind11::module& o_module )
{
    pybind11::bind_vector< {{ arrayType.className }} >(o_module, "{{ arrayType.className }}");
}
