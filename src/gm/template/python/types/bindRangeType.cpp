#include <pybind11/pybind11.h>

#include <gm/types/{{ valueType.headerFileName }}>

// Python bindings for {{ valueType.className }}.

GM_NS_USING

void Bind{{ valueType.className }}( pybind11::module& o_module )
{
    pybind11::class_< {{ valueType.className }} > cls( o_module, "{{ valueType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init<
        const {{ valueType.elementType.className }}&,
        const {{ valueType.elementType.className }}&
    >() );

}
