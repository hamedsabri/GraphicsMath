#include <pybind11/pybind11.h>

#include <gm/types/{{ vectorType.headerFileName }}>

// Python bindings for {{ vectorType.className }}.

void Bind{{ vectorType.className }}( pybind11::module& o_module )
{
    pybind11::class_< gm::{{ vectorType.className }} > cls( o_module, "{{ vectorType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init<
{%- for index in range(vectorType.elementSize) -%}
        const {{ vectorType.elementType.className }}&
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    >() );

}
