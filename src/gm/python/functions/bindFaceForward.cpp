//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/faceForward.h>

// Python bindings for FaceForward.

GM_NS_USING

void BindFaceForward( pybind11::module& o_module )
{
    o_module.def( "FaceForward",
                  []( const Vec2f& i_normal, const Vec2f& i_guide ) { return FaceForward( i_normal, i_guide ); } );
    o_module.def( "FaceForward",
                  []( const Vec3f& i_normal, const Vec3f& i_guide ) { return FaceForward( i_normal, i_guide ); } );
    o_module.def( "FaceForward",
                  []( const Vec4f& i_normal, const Vec4f& i_guide ) { return FaceForward( i_normal, i_guide ); } );
}