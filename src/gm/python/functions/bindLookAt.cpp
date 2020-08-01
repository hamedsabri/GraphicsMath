//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/lookAt.h>

// Python bindings for LookAt.

GM_NS_USING

void BindLookAt( pybind11::module& o_module )
{
    o_module.def( "LookAt", []( const Vec3f& i_position, const Vec3f& i_look, const Vec3f& i_up ) {
        return LookAt( i_position, i_look, i_up );
    } );
}