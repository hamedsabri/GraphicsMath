#include <pybind11/pybind11.h>

#include <gm/types/{{ valueType.headerFileName }}>

// Python bindings for {{ valueType.className }}.

GM_NS_USING

void Bind{{ valueType.className }}( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< {{ valueType.className }} > cls( o_module, "{{ valueType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init<
{%- for index in range(valueType.elementSize) -%}
        const {{ valueType.elements[ index ].type.className }}&
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    >() );

    // Object representation.
    cls.def( "__repr__", []( const {{ valueType.className }}& i_composite ) {
        return pybind11::str( i_composite.GetString( "gm." ) );
    } );

{% for element in valueType.elements %}
    // Property getter/setter for the "{{ element.name }}" element.
    cls.def_property( "{{ element.name }}",
        pybind11::cpp_function(
            []( {{ valueType.className }}& o_composite ) -> {{ element.type.className }}&
            {
               return o_composite.{{ element.accessorName }}();
            },
            pybind11::return_value_policy::reference_internal
        ),
        pybind11::cpp_function(
            []( {{ valueType.className }}& o_composite, const {{ element.type.className }}& i_element )
            {
               o_composite.{{ element.accessorName }}() = i_element;
            }
        ),
        "Property getter / setter for the {{ element.name }} element."
    );
{% endfor %}
}
