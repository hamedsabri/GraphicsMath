//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/transformPoint.h>

// Python bindings for TransformPoint.

GM_NS_USING

void BindTransformPoint( pybind11::module& o_module )
{
    o_module.def( "TransformPoint",
                  []( const Mat4f& i_matrix, const Vec3f& i_point ) { return TransformPoint( i_matrix, i_point ); } );
}