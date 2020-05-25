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

{% for element in compositeType.elements %}
    // Property getter/setter for the "{{ element.name }}" element.
    cls.def_property( "{{ element.name }}",
        pybind11::cpp_function(
            []( {{ compositeType.className }}& o_composite ) -> {{ element.type.className }}&
            {
               return o_composite.{{ element.accessorName }}();
            },
            pybind11::return_value_policy::reference_internal
        ),
        pybind11::cpp_function(
            []( {{ compositeType.className }}& o_composite, const {{ element.type.className }}& i_element )
            {
               o_composite.{{ element.accessorName }}() = i_element;
            }
        ),
        "Property getter / setter for the {{ element.name }} element."
    );
{% endfor %}
}
