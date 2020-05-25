//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds3f.h>

// Python bindings for Bounds3f.

GM_NS_USING

void BindBounds3f( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds3f > cls( o_module, "Bounds3f" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec3f&, const Vec3f& >() );

    // Object representation.
    cls.def( "__repr__",
             []( const Bounds3f& i_composite ) { return pybind11::str( i_composite.GetString( "gm." ) ); } );

    // Property getter/setter for the "min" element.
    cls.def_property( "min",
                      pybind11::cpp_function( []( Bounds3f& o_composite ) -> Vec3f& { return o_composite.Min(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds3f& o_composite, const Vec3f& i_element ) { o_composite.Min() = i_element; } ),
                      "Property getter / setter for the min element." );

    // Property getter/setter for the "max" element.
    cls.def_property( "max",
                      pybind11::cpp_function( []( Bounds3f& o_composite ) -> Vec3f& { return o_composite.Max(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds3f& o_composite, const Vec3f& i_element ) { o_composite.Max() = i_element; } ),
                      "Property getter / setter for the max element." );
}