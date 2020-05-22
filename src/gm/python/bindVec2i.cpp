//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2i.h>

// Python bindings for Vec2i.

GM_NS_USING

void BindVec2i( pybind11::module& o_module )
{
    pybind11::class_< Vec2i > cls( o_module, "Vec2i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Per-element initializer.
    cls.def( pybind11::init< const int&, const int& >() );

    // Object representation.
    cls.def( "__repr__",
             []( const Vec2i& i_lhs ) { return pybind11::str( "gm.Vec2i({},{})" ).format( i_lhs[ 0 ], i_lhs[ 1 ] ); } );

    // Element indexed read access.
    cls.def( "__getitem__", []( const Vec2i& i_vector, size_t i_index ) {
        if ( i_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        return i_vector[ i_index ];
    } );

    // Element indexed write access.
    cls.def( "__setitem__", []( Vec2i& o_vector, size_t i_index, int i_value ) {
        if ( o_vector.GetElementSize() <= i_index )
        {
            throw pybind11::index_error();
        }

        o_vector[ i_index ] = i_value;
    } );

    // Vector addition.
    cls.def( "__add__", []( const Vec2i& i_lhs, const Vec2i& i_rhs ) { return i_lhs + i_rhs; } );
}