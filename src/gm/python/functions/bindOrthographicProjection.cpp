//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/orthographicProjection.h>

// Python bindings for OrthographicProjection.

GM_NS_USING

void BindOrthographicProjection( pybind11::module& o_module )
{
    o_module.def( "OrthographicProjection",
                  []( const Vec3fRange& i_viewingVolume ) { return OrthographicProjection( i_viewingVolume ); } );
}