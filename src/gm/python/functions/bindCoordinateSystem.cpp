//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/coordinateSystem.h>

// Python bindings for CoordinateSystem.

GM_NS_USING

void BindCoordinateSystem( pybind11::module& o_module )
{
    o_module.def( "CoordinateSystem", []( const Vec3f& i_vectorA, Vec3f& o_vectorB, Vec3f& o_vectorC ) {
        CoordinateSystem( i_vectorA, o_vectorB, o_vectorC );
    } );
}