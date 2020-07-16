//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/vec4iRange.h>

// Python bindings for Vec4iRange.

GM_NS_USING

void BindVec4iRange( pybind11::module& o_module )
{
    pybind11::class_< Vec4iRange > cls( o_module, "Vec4iRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Object representation.
    cls.def( "__repr__", []( const Vec4iRange& i_range ) { return pybind11::str( i_range.GetString( "gm." ) ); } );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const Vec4i&, const Vec4i& >() );

    // Property getter/setter for the minimum bounds.
    cls.def_property(
        "min",
        pybind11::cpp_function( []( Vec4iRange& i_range ) -> Vec4i& { return i_range.Min(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( Vec4iRange& o_range, const Vec4i& i_min ) { o_range.Min() = i_min; } ),
        "Property getter / setter for the minimum." );

    // Property getter/setter for the maximum bounds.
    cls.def_property(
        "max",
        pybind11::cpp_function( []( Vec4iRange& i_range ) -> Vec4i& { return i_range.Max(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( Vec4iRange& o_range, const Vec4i& i_max ) { o_range.Max() = i_max; } ),
        "Property getter / setter for the minimum." );
}