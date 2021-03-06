#include <pybind11/pybind11.h>

#include <gm/types/{{ valueType.headerFileName }}>

// Python bindings for {{ valueType.className }}.

GM_NS_USING

void Bind{{ valueType.className }}( pybind11::module& o_module )
{
    pybind11::class_< {{ valueType.className }} > cls( o_module, "{{ valueType.className }}" );

    // Default initializer.
    cls.def( pybind11::init<>() );

    // Object representation.
    cls.def( "__repr__", []( const {{ valueType.className }}& i_range ) {
        return pybind11::str( i_range.GetString( "gm." ) );
    } );

    // Minimum maximum initializer.
    cls.def( pybind11::init<
        const {{ valueType.elementType.className }}&,
        const {{ valueType.elementType.className }}&
    >() );

    // Property getter/setter for the minimum bounds.
    cls.def_property( "min",
        pybind11::cpp_function(
            []( {{ valueType.className }}& i_range ) -> {{ valueType.elementType.className }}&
            {
               return i_range.Min();
            },
            pybind11::return_value_policy::reference_internal
        ),
        pybind11::cpp_function(
            []( {{ valueType.className }}& o_range, const {{ valueType.elementType.className }}& i_min )
            {
               o_range.Min() = i_min;
            }
        ),
        "Property getter / setter for the minimum."
    );

    // Property getter/setter for the maximum bounds.
    cls.def_property( "max",
        pybind11::cpp_function(
            []( {{ valueType.className }}& i_range ) -> {{ valueType.elementType.className }}&
            {
               return i_range.Max();
            },
            pybind11::return_value_policy::reference_internal
        ),
        pybind11::cpp_function(
            []( {{ valueType.className }}& o_range, const {{ valueType.elementType.className }}& i_max )
            {
               o_range.Max() = i_max;
            }
        ),
        "Property getter / setter for the maximum."
    );
}
