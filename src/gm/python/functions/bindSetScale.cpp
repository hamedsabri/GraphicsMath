//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/setScale.h>

// Python bindings for SetScale.

GM_NS_USING

void BindSetScale( pybind11::module& o_module )
{
    o_module.def( "SetScale", []( const Vec2f& i_vector, Mat3f& o_matrix ) { SetScale( i_vector, o_matrix ); } );
    o_module.def( "SetScale", []( const Vec3f& i_vector, Mat4f& o_matrix ) { SetScale( i_vector, o_matrix ); } );
}