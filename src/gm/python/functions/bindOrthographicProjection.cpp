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
                  []( const float& i_left,
                      const float& i_right,
                      const float& i_bottom,
                      const float& i_top,
                      const float& i_near,
                      const float& i_far ) {
                      return OrthographicProjection( i_left, i_right, i_bottom, i_top, i_near, i_far );
                  } );
}