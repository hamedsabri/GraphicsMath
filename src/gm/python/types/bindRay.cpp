//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/types/ray.h>

// Python bindings for Ray.

GM_NS_USING

void BindRay( pybind11::module& o_module )
{
    // Define class.
    pybind11::class_< Ray > cls( o_module, "Ray" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Element-wise initializer.
    cls.def( pybind11::init< const Vec3f&, const Vec3f& >() );

    // Object representation.
    cls.def( "__repr__", []( const Ray& i_composite ) { return pybind11::str( i_composite.GetString( "gm." ) ); } );

    // Property getter/setter for the "origin" element.
    cls.def_property(
        "origin",
        pybind11::cpp_function( []( Ray& o_composite ) -> Vec3f& { return o_composite.Origin(); },
                                pybind11::return_value_policy::reference_internal ),
        pybind11::cpp_function( []( Ray& o_composite, const Vec3f& i_element ) { o_composite.Origin() = i_element; } ),
        "Property getter / setter for the origin element." );

    // Property getter/setter for the "direction" element.
    cls.def_property( "direction",
                      pybind11::cpp_function( []( Ray& o_composite ) -> Vec3f& { return o_composite.Direction(); },
                                              pybind11::return_value_policy::reference_internal ),
                      pybind11::cpp_function(
                          []( Ray& o_composite, const Vec3f& i_element ) { o_composite.Direction() = i_element; } ),
                      "Property getter / setter for the direction element." );
}