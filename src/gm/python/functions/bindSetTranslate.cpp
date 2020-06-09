//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setTranslate.h>

// Python bindings for SetTranslate.

GM_NS_USING

void BindSetTranslate( pybind11::module& o_module )
{
    o_module.def( "SetTranslate",
                  []( const Vec2f& i_vector, Mat3f& o_matrix ) { SetTranslate( i_vector, o_matrix ); } );
    o_module.def( "SetTranslate",
                  []( const Vec3f& i_vector, Mat4f& o_matrix ) { SetTranslate( i_vector, o_matrix ); } );
}