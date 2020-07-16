//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/floatRange.h>

// Python bindings for FloatRange.

GM_NS_USING

void BindFloatRange( pybind11::module& o_module )
{
    pybind11::class_< FloatRange > cls( o_module, "FloatRange" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Object representation.
    cls.def( "__repr__", []( const FloatRange& i_range ) { return pybind11::str( i_range.GetString( "gm." ) ); } );

    // Minimum maximum initializer.
    cls.def( pybind11::init< const float&, const float& >() );

    // Property getter/setter for the minimum bounds.
    cls.def_property(
        "min",
        pybind11::cpp_function( []( FloatRange& i_range ) -> float& { return i_range.Min(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( FloatRange& o_range, const float& i_min ) { o_range.Min() = i_min; } ),
        "Property getter / setter for the minimum." );

    // Property getter/setter for the maximum bounds.
    cls.def_property(
        "max",
        pybind11::cpp_function( []( FloatRange& i_range ) -> float& { return i_range.Max(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( FloatRange& o_range, const float& i_max ) { o_range.Max() = i_max; } ),
        "Property getter / setter for the minimum." );
}