//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4f.h>

// Python bindings for Vec4f.

GM_NS_USING

void BindVec4f( pybind11::module& o_module )
{
    pybind11::class_< Vec4f > cls( o_module, "Vec4f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const float&, const float&, const float&, const float& >() );

    // Object representation.
    cls.def( "__repr__", []( const Vec4f& i_lhs ) {
        return pybind11::str( "gm.Vec4f({}, {}, {}, {})" ).format( i_lhs[ 0 ], i_lhs[ 1 ], i_lhs[ 2 ], i_lhs[ 3 ] );
    } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Vec4f& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Vec4f& o_vector, size_t i_index, float i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const Vec4f& i_lhs, const Vec4f& i_rhs ) { return i_lhs + i_rhs; } );
}