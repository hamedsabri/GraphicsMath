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

    // Element-wise initializer.
    cls.def( pybind11::init<
{%- for index in range(compositeType.elementSize) -%}
        const {{ compositeType.elements[ index ].type.className }}&
{%- if index + 1 < compositeType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    >() );
}
