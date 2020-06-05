//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/degrees.h>

// Python bindings for Degrees.

GM_NS_USING

void BindDegrees( pybind11::module& o_module )
{
    o_module.def( "Degrees", []( const float& i_angle ) { return Degrees( i_angle ); } );
}