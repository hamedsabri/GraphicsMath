//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/trilinearInterpolation.h>

// Python bindings for TrilinearInterpolation.

GM_NS_USING

void BindTrilinearInterpolation( pybind11::module& o_module )
{
    o_module.def( "TrilinearInterpolation",
                  []( const float& i_corner000,
                      const float& i_corner100,
                      const float& i_corner010,
                      const float& i_corner110,
                      const float& i_corner001,
                      const float& i_corner101,
                      const float& i_corner011,
                      const float& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Mat3f& i_corner000,
                      const Mat3f& i_corner100,
                      const Mat3f& i_corner010,
                      const Mat3f& i_corner110,
                      const Mat3f& i_corner001,
                      const Mat3f& i_corner101,
                      const Mat3f& i_corner011,
                      const Mat3f& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Mat4f& i_corner000,
                      const Mat4f& i_corner100,
                      const Mat4f& i_corner010,
                      const Mat4f& i_corner110,
                      const Mat4f& i_corner001,
                      const Mat4f& i_corner101,
                      const Mat4f& i_corner011,
                      const Mat4f& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec2f& i_corner000,
                      const Vec2f& i_corner100,
                      const Vec2f& i_corner010,
                      const Vec2f& i_corner110,
                      const Vec2f& i_corner001,
                      const Vec2f& i_corner101,
                      const Vec2f& i_corner011,
                      const Vec2f& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec3f& i_corner000,
                      const Vec3f& i_corner100,
                      const Vec3f& i_corner010,
                      const Vec3f& i_corner110,
                      const Vec3f& i_corner001,
                      const Vec3f& i_corner101,
                      const Vec3f& i_corner011,
                      const Vec3f& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec4f& i_corner000,
                      const Vec4f& i_corner100,
                      const Vec4f& i_corner010,
                      const Vec4f& i_corner110,
                      const Vec4f& i_corner001,
                      const Vec4f& i_corner101,
                      const Vec4f& i_corner011,
                      const Vec4f& i_corner111,
                      const Vec3f& i_weight ) {
                      return TrilinearInterpolation( i_corner000,
                                                     i_corner100,
                                                     i_corner010,
                                                     i_corner110,
                                                     i_corner001,
                                                     i_corner101,
                                                     i_corner011,
                                                     i_corner111,
                                                     i_weight );
                  } );
}