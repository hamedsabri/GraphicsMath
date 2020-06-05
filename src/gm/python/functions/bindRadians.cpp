//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/radians.h>

// Python bindings for Radians.

GM_NS_USING

void BindRadians( pybind11::module& o_module )
{
    o_module.def( "Radians", []( const float& i_angle ) { return Radians( i_angle ); } );
}