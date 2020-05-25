//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds3i.h>

// Python bindings for Bounds3i.

GM_NS_USING

void BindBounds3i( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds3i > cls( o_module, "Bounds3i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec3i&, const Vec3i& >() );

    // Object representation.
    cls.def( "__repr__",
             []( const Bounds3i& i_composite ) { return pybind11::str( i_composite.GetString( "gm." ) ); } );

    // Property getter/setter for the "min" element.
    cls.def_property( "min",
                      pybind11::cpp_function( []( Bounds3i& o_composite ) -> Vec3i& { return o_composite.Min(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds3i& o_composite, const Vec3i& i_element ) { o_composite.Min() = i_element; } ),
                      "Property getter / setter for the min element." );

    // Property getter/setter for the "max" element.
    cls.def_property( "max",
                      pybind11::cpp_function( []( Bounds3i& o_composite ) -> Vec3i& { return o_composite.Max(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds3i& o_composite, const Vec3i& i_element ) { o_composite.Max() = i_element; } ),
                      "Property getter / setter for the max element." );
}