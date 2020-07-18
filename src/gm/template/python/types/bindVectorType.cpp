#include <pybind11/pybind11.h>

#include <gm/types/{{ valueType.headerFileName }}>

// Python bindings for {{ valueType.className }}.

GM_NS_USING

void Bind{{ valueType.className }}( pybind11::module& o_module )
{
    pybind11::class_< {{ valueType.className }} > cls( o_module, "{{ valueType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init<
{%- for index in range(valueType.elementSize) -%}
        const {{ valueType.elementType.className }}&
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    >() );

    // Object representation.
    cls.def( "__repr__", []( const {{ valueType.className }}& i_vector ) {
        return pybind11::str( i_vector.GetString( "gm." ) );
    } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const {{ valueType.className }}& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( {{ valueType.className }}& o_vector,
                                size_t i_index,
                                {{ valueType.elementType.className }} i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

{% if valueType.shape|length == 2 -%}
    // Matrix row-column indexed element read access.
    cls.def( "__getitem__", []( const {{ valueType.className }}& i_matrix, pybind11::tuple i_index ) {
        if ( i_index.size() != 2 )
        {
            throw pybind11::index_error();
        }

        size_t row = i_index[0].cast< size_t >();
        size_t col = i_index[1].cast< size_t >();
        if ( row >= {{ valueType.shape[0] }} || col >= {{ valueType.shape[1] }} )
        {
            throw pybind11::index_error();
        }

        return i_matrix( row, col );
    } );

    // Matrix row-column indexed element write access.
    cls.def( "__setitem__", []( {{ valueType.className }}& o_matrix,
                                pybind11::tuple i_index,
                                {{ valueType.elementType.className }} i_value ) {
        if ( i_index.size() != 2 )
        {
            throw pybind11::index_error();
        }

        size_t row = i_index[0].cast< size_t >();
        size_t col = i_index[1].cast< size_t >();
        if ( row >= {{ valueType.shape[0] }} || col >= {{ valueType.shape[1] }} )
        {
            throw pybind11::index_error();
        }

        o_matrix( row, col ) = i_value;
    } );
{%- endif %}

{%- for namedElement in valueType.namedElements -%}
    // Named {{ namedElement.accessorName }} element accessor.
    cls.def_property( "{{ namedElement.name }}",
        pybind11::cpp_function(
            []( {{ valueType.className }}& i_vector ) -> {{ valueType.elementType.className }}&
            {
               return i_vector.{{ namedElement.accessorName }}();
            },
            pybind11::return_value_policy::reference_internal
        ),
        pybind11::cpp_function(
            []( {{ valueType.className }}& o_vector, const {{ valueType.elementType.className }}& i_{{ namedElement.name }} )
            {
               o_vector.{{ namedElement.accessorName }}() = i_{{ namedElement.name }};
            }
        ),
        "Named property getter / setter for the element at index {{ loop.index0 }}."
    );
{%- endfor %}

    // Vector addition.
    cls.def( "__add__", []( const {{ valueType.className }}& i_lhs,
                            const {{ valueType.className }}& i_rhs ) {
        return i_lhs + i_rhs;
    } );

    // Vector subtraction.
    cls.def( "__sub__", []( const {{ valueType.className }}& i_lhs,
                            const {{ valueType.className }}& i_rhs ) {
        return i_lhs - i_rhs;
    } );

    // Vector-scalar Multiplication.
    cls.def( "__mul__", []( const {{ valueType.className }}& i_lhs,
                            {{ valueType.elementType.className }} i_rhs ) {
        return i_lhs * i_rhs;
    } );

    // Scalar-vector Multiplication.
    cls.def( "__rmul__", []( const {{ valueType.className }}& i_rhs,
                             {{ valueType.elementType.className }} i_lhs ) {
        return i_lhs * i_rhs;
    } );


    // Vector-scalar Division.
    cls.def( "__div__", []( const {{ valueType.className }}& i_lhs,
                            {{ valueType.elementType.className }} i_rhs ) {
        if ( i_rhs == {{ valueType.CppValue( 0 ) }} )
        {
            // TODO throw pybind11::zero_division_error();
            throw pybind11::value_error();
        }
        return i_lhs / i_rhs;
    } );

    // Unary negation.
    cls.def( "__neg__", []( const {{ valueType.className }}& i_vector ) {
        return -i_vector;
    } );

    // Equality.
    cls.def( "__eq__", []( const {{ valueType.className }}& i_lhs,
                           const {{ valueType.className }}& i_rhs ) {
        return i_lhs == i_rhs;
    } );

    // Element size.
    cls.def( "GetElementSize", &{{ valueType.className }}::GetElementSize );

    // Check for nans.
    cls.def( "HasNans", &{{ valueType.className }}::HasNans );
}
