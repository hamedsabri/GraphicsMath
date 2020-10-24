//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/viewportTransform.h>

// Python bindings for ViewportTransform.

GM_NS_USING

void BindViewportTransform( pybind11::module& o_module )
{
    o_module.def( "ViewportTransform", []( const Vec2f& i_dimensions, const Vec2f& i_offset ) {
        return ViewportTransform( i_dimensions, i_offset );
    } );
}