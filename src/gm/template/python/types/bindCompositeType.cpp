#include <pybind11/pybind11.h>

#include <gm/types/{{ compositeType.headerFileName }}>

// Python bindings for {{ compositeType.className }}.

GM_NS_USING

void Bind{{ compositeType.className }}( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< {{ compositeType.className }} > cls( o_module, "{{ compositeType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );
}
