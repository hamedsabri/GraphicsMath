//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec3i.h>

// Python bindings for Vec3i.

GM_NS_USING

void BindVec3i( pybind11::module& o_module )
{
    pybind11::class_< Vec3i > cls( o_module, "Vec3i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const int&, const int&, const int& >() );

    // Object representation.
    cls.def( "__repr__", []( const Vec3i& i_vector ) { return pybind11::str( i_vector.GetString( "gm." ) ); } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Vec3i& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Vec3i& o_vector, size_t i_index, int i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Named X element accessor.
    cls.def_property( "x",
                      pybind11::cpp_function( []( Vec3i& i_vector ) -> int& { return i_vector.X(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function( []( Vec3i& o_vector, const int& i_x ) { o_vector.X() = i_x; } ),
                      "Named property getter / setter for the element at index 0." ); // Named Y element accessor.
    cls.def_property( "y",
                      pybind11::cpp_function( []( Vec3i& i_vector ) -> int& { return i_vector.Y(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function( []( Vec3i& o_vector, const int& i_y ) { o_vector.Y() = i_y; } ),
                      "Named property getter / setter for the element at index 1." ); // Named Z element accessor.
    cls.def_property( "z",
                      pybind11::cpp_function( []( Vec3i& i_vector ) -> int& { return i_vector.Z(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function( []( Vec3i& o_vector, const int& i_z ) { o_vector.Z() = i_z; } ),
                      "Named property getter / setter for the element at index 2." );

    // Vector addition.
    cls.def( "__add__", []( const Vec3i& i_lhs, const Vec3i& i_rhs ) { return i_lhs + i_rhs; } );

    // Vector subtraction.
    cls.def( "__sub__", []( const Vec3i& i_lhs, const Vec3i& i_rhs ) { return i_lhs - i_rhs; } );

    // Vector-scalar Multiplication.
    cls.def( "__mul__", []( const Vec3i& i_lhs, int i_rhs ) { return i_lhs * i_rhs; } );

    // Scalar-vector Multiplication.
    cls.def( "__rmul__", []( const Vec3i& i_rhs, int i_lhs ) { return i_lhs * i_rhs; } );

    // Vector-scalar Division.
    cls.def( "__div__", []( const Vec3i& i_lhs, int i_rhs ) {
        if ( i_rhs == 0 )
        {
            // TODO throw pybind11::zero_division_error();
            throw pybind11::value_error();
        }
        return i_lhs / i_rhs;
    } );

    // Unary negation.
    cls.def( "__neg__", []( const Vec3i& i_vector ) { return -i_vector; } );

    // Equality.
    cls.def( "__eq__", []( const Vec3i& i_lhs, const Vec3i& i_rhs ) { return i_lhs == i_rhs; } );

    // Element size.
    cls.def( "GetElementSize", &Vec3i::GetElementSize );

    // Check for nans.
    cls.def( "HasNans", &Vec3i::HasNans );
}