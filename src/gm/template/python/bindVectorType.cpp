#include <pybind11/pybind11.h>

#include <gm/types/{{ vectorType.headerFileName }}>

// Python bindings for {{ vectorType.className }}.

GM_NS_USING

void Bind{{ vectorType.className }}( pybind11::module& o_module )
{
    pybind11::class_< {{ vectorType.className }} > cls( o_module, "{{ vectorType.className }}" );

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

    // Object representation.
    cls.def( "__repr__", []( const {{ vectorType.className }}& i_lhs ) {
        return pybind11::str("gm.{{vectorType.className}}(
{%- for index in range(vectorType.elementSize) -%}
        {}
{%- if index + 1 < vectorType.elementSize -%}
        ,{{ " " }}
{%- endif -%}
{%- endfor -%}
            )" ).format(
{%- for index in range(vectorType.elementSize) -%}
            i_lhs[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
            ,
{%- endif -%}
{%- endfor -%}
            );
        }
    );

    // Element indexed read access.
    cls.def( "__getitem__", []( const {{ vectorType.className }}& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( {{ vectorType.className }}& o_vector,
                                size_t i_index,
                                {{ vectorType.elementType.className }} i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const {{ vectorType.className }}& i_lhs,
                            const {{ vectorType.className }}& i_rhs ) {
        return i_lhs + i_rhs;
    } );

}
