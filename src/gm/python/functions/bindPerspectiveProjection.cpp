//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/perspectiveProjection.h>

// Python bindings for PerspectiveProjection.

GM_NS_USING

void BindPerspectiveProjection( pybind11::module& o_module )
{
    o_module.def(
        "PerspectiveProjection",
        []( const float& i_left,
            const float& i_right,
            const float& i_bottom,
            const float& i_top,
            const float& i_near,
            const float& i_far ) { return PerspectiveProjection( i_left, i_right, i_bottom, i_top, i_near, i_far ); } );
    o_module.def(
        "PerspectiveProjection",
        []( const float& i_fieldOfView, const float& i_aspectRatio, const float& i_near, const float& i_far ) {
            return PerspectiveProjection( i_fieldOfView, i_aspectRatio, i_near, i_far );
        } );
}