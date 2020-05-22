//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/mat4f.h>

// Python bindings for Mat4f.

GM_NS_USING

void BindMat4f( pybind11::module& o_module )
{
    pybind11::class_< Mat4f > cls( o_module, "Mat4f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float&,
                             const float& >() );

    // Object representation.
    cls.def( "__repr__", []( const Mat4f& i_lhs ) {
        return pybind11::str( "gm.Mat4f({}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {})" )
            .format( i_lhs[ 0 ],
                     i_lhs[ 1 ],
                     i_lhs[ 2 ],
                     i_lhs[ 3 ],
                     i_lhs[ 4 ],
                     i_lhs[ 5 ],
                     i_lhs[ 6 ],
                     i_lhs[ 7 ],
                     i_lhs[ 8 ],
                     i_lhs[ 9 ],
                     i_lhs[ 10 ],
                     i_lhs[ 11 ],
                     i_lhs[ 12 ],
                     i_lhs[ 13 ],
                     i_lhs[ 14 ],
                     i_lhs[ 15 ] );
    } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Mat4f& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Mat4f& o_vector, size_t i_index, float i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const Mat4f& i_lhs, const Mat4f& i_rhs ) { return i_lhs + i_rhs; } );

    // Vector subtraction.
    cls.def( "__sub__", []( const Mat4f& i_lhs, const Mat4f& i_rhs ) { return i_lhs - i_rhs; } );

    // Vector-scalar Multiplication.
    cls.def( "__mul__", []( const Mat4f& i_lhs, float i_rhs ) { return i_lhs * i_rhs; } );

    // Scalar-vector Multiplication.
    cls.def( "__rmul__", []( const Mat4f& i_rhs, float i_lhs ) { return i_lhs * i_rhs; } );

    // Vector-scalar Division.
    cls.def( "__div__", []( const Mat4f& i_lhs, float i_rhs ) {
        if ( i_rhs == 0.0f )
        {
            // TODO throw pybind11::zero_division_error();
            throw pybind11::value_error();
        }
        return i_lhs / i_rhs;
    } );
}