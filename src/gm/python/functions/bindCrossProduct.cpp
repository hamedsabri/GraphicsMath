//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/crossProduct.h>

// Python bindings for CrossProduct.

GM_NS_USING

void BindCrossProduct( pybind11::module& o_module )
{
    o_module.def( "CrossProduct",
                  []( const Vec3f& i_lhs, const Vec3f& i_rhs ) { return CrossProduct( i_lhs, i_rhs ); } );
}