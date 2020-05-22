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

{% if vectorType.dims|length == 2 -%}
    // Matrix row-column indexed element read access.
    cls.def( "__getitem__", []( const {{ vectorType.className }}& i_matrix, pybind11::tuple i_index ) {
        if ( i_index.size() != 2 )
        {
            throw pybind11::index_error();
        }

        size_t row = i_index[0].cast< size_t >();
        size_t col = i_index[1].cast< size_t >();
        if ( row >= {{ vectorType.dims[0] }} || col >= {{ vectorType.dims[1] }} )
        {
            throw pybind11::index_error();
        }

        return i_matrix( row, col );
    } );

    // Matrix row-column indexed element write access.
    cls.def( "__setitem__", []( {{ vectorType.className }}& o_matrix,
                                pybind11::tuple i_index,
                                {{ vectorType.elementType.className }} i_value ) {
        if ( i_index.size() != 2 )
        {
            throw pybind11::index_error();
        }

        size_t row = i_index[0].cast< size_t >();
        size_t col = i_index[1].cast< size_t >();
        if ( row >= {{ vectorType.dims[0] }} || col >= {{ vectorType.dims[1] }} )
        {
            throw pybind11::index_error();
        }

        o_matrix( row, col ) = i_value;
    } );
{%- endif %}

    // Vector addition.
    cls.def( "__add__", []( const {{ vectorType.className }}& i_lhs,
                            const {{ vectorType.className }}& i_rhs ) {
        return i_lhs + i_rhs;
    } );

    // Vector subtraction.
    cls.def( "__sub__", []( const {{ vectorType.className }}& i_lhs,
                            const {{ vectorType.className }}& i_rhs ) {
        return i_lhs - i_rhs;
    } );

    // Vector-scalar Multiplication.
    cls.def( "__mul__", []( const {{ vectorType.className }}& i_lhs,
                            {{ vectorType.elementType.className }} i_rhs ) {
        return i_lhs * i_rhs;
    } );

    // Scalar-vector Multiplication.
    cls.def( "__rmul__", []( const {{ vectorType.className }}& i_rhs,
                             {{ vectorType.elementType.className }} i_lhs ) {
        return i_lhs * i_rhs;
    } );


    // Vector-scalar Division.
    cls.def( "__div__", []( const {{ vectorType.className }}& i_lhs,
                            {{ vectorType.elementType.className }} i_rhs ) {
        if ( i_rhs == {{ vectorType.GetCppNumber( 0 ) }} )
        {
            // TODO throw pybind11::zero_division_error();
            throw pybind11::value_error();
        }
        return i_lhs / i_rhs;
    } );

    // Unary negation.
    cls.def( "__neg__", []( const {{ vectorType.className }}& i_vector ) {
        return -i_vector;
    } );

}
