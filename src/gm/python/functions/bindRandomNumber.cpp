//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/randomNumber.h>

// Python bindings for RandomNumber.

GM_NS_USING

void BindRandomNumber( pybind11::module& o_module )
{
    o_module.def( "RandomNumber", []( const FloatRange& i_range ) { return RandomNumber( i_range ); } );
    o_module.def( "RandomNumber", []( const IntRange& i_range ) { return RandomNumber( i_range ); } );
}