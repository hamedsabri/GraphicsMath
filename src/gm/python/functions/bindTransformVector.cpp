//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/transformVector.h>

// Python bindings for TransformVector.

GM_NS_USING

void BindTransformVector( pybind11::module& o_module )
{
    o_module.def( "TransformVector", []( const Mat4f& i_matrix, const Vec3f& i_vector ) {
        return TransformVector( i_matrix, i_vector );
    } );
}