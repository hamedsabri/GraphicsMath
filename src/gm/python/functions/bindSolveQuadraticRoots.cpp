//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/solveQuadraticRoots.h>

// Python bindings for SolveQuadraticRoots.

GM_NS_USING

void BindSolveQuadraticRoots( pybind11::module& o_module )
{
    o_module.def( "SolveQuadraticRoots",
                  []( const float& i_a, const float& i_b, const float& i_c, float& o_firstRoot, float& o_secondRoot ) {
                      return SolveQuadraticRoots( i_a, i_b, i_c, o_firstRoot, o_secondRoot );
                  } );
}