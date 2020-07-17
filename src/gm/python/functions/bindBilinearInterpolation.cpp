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
                  []( const float& i_value00,
                      const float& i_value10,
                      const float& i_value01,
                      const float& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Mat3f& i_value00,
                      const Mat3f& i_value10,
                      const Mat3f& i_value01,
                      const Mat3f& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Mat4f& i_value00,
                      const Mat4f& i_value10,
                      const Mat4f& i_value01,
                      const Mat4f& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec2f& i_value00,
                      const Vec2f& i_value10,
                      const Vec2f& i_value01,
                      const Vec2f& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec3f& i_value00,
                      const Vec3f& i_value10,
                      const Vec3f& i_value01,
                      const Vec3f& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
    o_module.def( "BilinearInterpolation",
                  []( const Vec4f& i_value00,
                      const Vec4f& i_value10,
                      const Vec4f& i_value01,
                      const Vec4f& i_value11,
                      const float& i_weightX,
                      const float& i_weightY ) {
                      return BilinearInterpolation( i_value00, i_value10, i_value01, i_value11, i_weightX, i_weightY );
                  } );
}