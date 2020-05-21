#include <pybind11/pybind11.h>

#include <gm/types/{{ vectorType.headerFileName }}>

void Bind{{ vectorType.className }}( pybind11::module& o_module )
{
    pybind11::class_< gm::{{ vectorType.className }} > cls( o_module, "{{ vectorType.className }}" );
    cls.def( pybind11::init<>() );
    cls.def( pybind11::init<
{%- for index in range(vectorType.elementSize) -%}
        const {{ vectorType.elementType.className }}&
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    >() );
}
