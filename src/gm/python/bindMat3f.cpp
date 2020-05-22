//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/mat3f.h>

// Python bindings for Mat3f.

GM_NS_USING

void BindMat3f( pybind11::module& o_module )
{
    pybind11::class_< Mat3f > cls( o_module, "Mat3f" );

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
                             const float& >() );

    // Object representation.
    cls.def( "__repr__", []( const Mat3f& i_lhs ) {
        return pybind11::str( "gm.Mat3f({}, {}, {}, {}, {}, {}, {}, {}, {})" )
            .format( i_lhs[ 0 ],
                     i_lhs[ 1 ],
                     i_lhs[ 2 ],
                     i_lhs[ 3 ],
                     i_lhs[ 4 ],
                     i_lhs[ 5 ],
                     i_lhs[ 6 ],
                     i_lhs[ 7 ],
                     i_lhs[ 8 ] );
    } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Mat3f& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Mat3f& o_vector, size_t i_index, float i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const Mat3f& i_lhs, const Mat3f& i_rhs ) { return i_lhs + i_rhs; } );
}