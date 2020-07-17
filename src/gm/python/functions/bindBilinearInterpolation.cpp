//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/bilinearInterpolation.h>

// Python bindings for BilinearInterpolation.

GM_NS_USING

void BindBilinearInterpolation( pybind11::module& o_module )
{
    o_module.def( "BilinearInterpolation",
                  []( const float& i_corner00,
                      const float& i_corner10,
                      const float& i_corner01,
                      const float& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Mat3f& i_corner00,
                      const Mat3f& i_corner10,
                      const Mat3f& i_corner01,
                      const Mat3f& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Mat4f& i_corner00,
                      const Mat4f& i_corner10,
                      const Mat4f& i_corner01,
                      const Mat4f& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec2f& i_corner00,
                      const Vec2f& i_corner10,
                      const Vec2f& i_corner01,
                      const Vec2f& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec3f& i_corner00,
                      const Vec3f& i_corner10,
                      const Vec3f& i_corner01,
                      const Vec3f& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec4f& i_corner00,
                      const Vec4f& i_corner10,
                      const Vec4f& i_corner01,
                      const Vec4f& i_corner11,
                      const Vec2f& i_weight ) {
                      return BilinearInterpolation( i_corner00, i_corner10, i_corner01, i_corner11, i_weight );
                  } );
}