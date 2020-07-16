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
                  []( const float& i_value000,
                      const float& i_value001,
                      const float& i_value010,
                      const float& i_value011,
                      const float& i_value100,
                      const float& i_value101,
                      const float& i_value110,
                      const float& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Mat3f& i_value000,
                      const Mat3f& i_value001,
                      const Mat3f& i_value010,
                      const Mat3f& i_value011,
                      const Mat3f& i_value100,
                      const Mat3f& i_value101,
                      const Mat3f& i_value110,
                      const Mat3f& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Mat4f& i_value000,
                      const Mat4f& i_value001,
                      const Mat4f& i_value010,
                      const Mat4f& i_value011,
                      const Mat4f& i_value100,
                      const Mat4f& i_value101,
                      const Mat4f& i_value110,
                      const Mat4f& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec2f& i_value000,
                      const Vec2f& i_value001,
                      const Vec2f& i_value010,
                      const Vec2f& i_value011,
                      const Vec2f& i_value100,
                      const Vec2f& i_value101,
                      const Vec2f& i_value110,
                      const Vec2f& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec3f& i_value000,
                      const Vec3f& i_value001,
                      const Vec3f& i_value010,
                      const Vec3f& i_value011,
                      const Vec3f& i_value100,
                      const Vec3f& i_value101,
                      const Vec3f& i_value110,
                      const Vec3f& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
    o_module.def( "TrilinearInterpolation",
                  []( const Vec4f& i_value000,
                      const Vec4f& i_value001,
                      const Vec4f& i_value010,
                      const Vec4f& i_value011,
                      const Vec4f& i_value100,
                      const Vec4f& i_value101,
                      const Vec4f& i_value110,
                      const Vec4f& i_value111,
                      const float& i_weightX,
                      const float& i_weightY,
                      const float& i_weightZ ) {
                      return TrilinearInterpolation( i_value000,
                                                     i_value001,
                                                     i_value010,
                                                     i_value011,
                                                     i_value100,
                                                     i_value101,
                                                     i_value110,
                                                     i_value111,
                                                     i_weightX,
                                                     i_weightY,
                                                     i_weightZ );
                  } );
}