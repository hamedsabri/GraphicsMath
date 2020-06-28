//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/quadraticRoots.h>

// Python bindings for QuadraticRoots.

GM_NS_USING

void BindQuadraticRoots( pybind11::module& o_module )
{
    o_module.def( "QuadraticRoots",
                  []( const float& i_a, const float& i_b, const float& i_c, float& o_firstRoot, float& o_secondRoot ) {
                      return QuadraticRoots( i_a, i_b, i_c, o_firstRoot, o_secondRoot );
                  } );
}