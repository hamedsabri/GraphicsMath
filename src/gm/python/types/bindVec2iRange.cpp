//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec2iRange.h>

// Python bindings for Vec2iRange.

GM_NS_USING

void BindVec2iRange( pybind11::module& o_module )
{
    pybind11::class_< Vec2iRange > cls( o_module, "Vec2iRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Object representation.
    cls.def( "__repr__", []( const Vec2iRange& i_range ) { return pybind11::str( i_range.GetString( "gm." ) ); } );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec2i&, const Vec2i& >() );

    // Property getter/setter for the minimum bounds.
    cls.def_property(
        "min",
        pybind11::cpp_function( []( Vec2iRange& i_range ) -> Vec2i& { return i_range.Min(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( Vec2iRange& o_range, const Vec2i& i_min ) { o_range.Min() = i_min; } ),
        "Property getter / setter for the minimum." );

    // Property getter/setter for the maximum bounds.
    cls.def_property(
        "max",
        pybind11::cpp_function( []( Vec2iRange& i_range ) -> Vec2i& { return i_range.Max(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( Vec2iRange& o_range, const Vec2i& i_max ) { o_range.Max() = i_max; } ),
        "Property getter / setter for the maximum." );
}