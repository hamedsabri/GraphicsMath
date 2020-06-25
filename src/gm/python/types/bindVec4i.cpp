//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4i.h>

// Python bindings for Vec4i.

GM_NS_USING

void BindVec4i( pybind11::module& o_module )
{
    pybind11::class_< Vec4i > cls( o_module, "Vec4i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const int&, const int&, const int&, const int& >() );

    // Object representation.
    cls.def( "__repr__", []( const Vec4i& i_vector ) { return pybind11::str( i_vector.GetString( "gm." ) ); } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Vec4i& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Vec4i& o_vector, size_t i_index, int i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const Vec4i& i_lhs, const Vec4i& i_rhs ) { return i_lhs + i_rhs; } );

    // Vector subtraction.
    cls.def( "__sub__", []( const Vec4i& i_lhs, const Vec4i& i_rhs ) { return i_lhs - i_rhs; } );

    // Vector-scalar Multiplication.
    cls.def( "__mul__", []( const Vec4i& i_lhs, int i_rhs ) { return i_lhs * i_rhs; } );

    // Scalar-vector Multiplication.
    cls.def( "__rmul__", []( const Vec4i& i_rhs, int i_lhs ) { return i_lhs * i_rhs; } );

    // Vector-scalar Division.
    cls.def( "__div__", []( const Vec4i& i_lhs, int i_rhs ) {
        if ( i_rhs == 0 )
        {
            // TODO throw pybind11::zero_division_error();
            throw pybind11::value_error();
        }
        return i_lhs / i_rhs;
    } );

    // Unary negation.
    cls.def( "__neg__", []( const Vec4i& i_vector ) { return -i_vector; } );

    // Equality.
    cls.def( "__eq__", []( const Vec4i& i_lhs, const Vec4i& i_rhs ) { return i_lhs == i_rhs; } );

    // Element size.
    cls.def( "GetElementSize", &Vec4i::GetElementSize );

    // Check for nans.
    cls.def( "HasNans", &Vec4i::HasNans );
}