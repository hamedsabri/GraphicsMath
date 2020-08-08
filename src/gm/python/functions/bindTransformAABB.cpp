//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/transformAABB.h>

// Python bindings for TransformAABB.

GM_NS_USING

void BindTransformAABB( pybind11::module& o_module )
{
    o_module.def( "TransformAABB",
                  []( const Mat4f& i_matrix, const Vec3fRange& i_aabb ) { return TransformAABB( i_matrix, i_aabb ); } );
}