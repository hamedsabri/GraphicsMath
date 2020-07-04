#include <pybind11/pybind11.h>

#include <gm/types/{{ rangeType.headerFileName }}>

// Python bindings for {{ rangeType.className }}.

GM_NS_USING

void Bind{{ rangeType.className }}( pybind11::module& o_module )
{
    pybind11::class_< {{ rangeType.className }} > cls( o_module, "{{ rangeType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Minimum maximum initializer.
    cls.def( pybind11::init<
        const {{ rangeType.elementType.className }}&,
        const {{ rangeType.elementType.className }}&
    >() );

}
