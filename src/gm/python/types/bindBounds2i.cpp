//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/bounds2i.h>

// Python bindings for Bounds2i.

GM_NS_USING

void BindBounds2i( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Bounds2i > cls( o_module, "Bounds2i" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec2i&, const Vec2i& >() );

    // Property getter/setter for the "min" element.
    cls.def_property( "min",
                      pybind11::cpp_function( []( Bounds2i& o_composite ) -> Vec2i& { return o_composite.Min(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds2i& o_composite, const Vec2i& i_element ) { o_composite.Min() = i_element; } ),
                      "Property getter / setter for the min element." );

    // Property getter/setter for the "max" element.
    cls.def_property( "max",
                      pybind11::cpp_function( []( Bounds2i& o_composite ) -> Vec2i& { return o_composite.Max(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Bounds2i& o_composite, const Vec2i& i_element ) { o_composite.Max() = i_element; } ),
                      "Property getter / setter for the max element." );
}