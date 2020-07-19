//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/linearInterpolation.h>

// Python bindings for LinearInterpolation.

GM_NS_USING

void BindLinearInterpolation( pybind11::module& o_module )
{
    o_module.def( "LinearInterpolation", []( const float& i_source, const float& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation", []( const Mat3f& i_source, const Mat3f& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation", []( const Mat4f& i_source, const Mat4f& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation", []( const Vec2f& i_source, const Vec2f& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation", []( const Vec3f& i_source, const Vec3f& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation", []( const Vec4f& i_source, const Vec4f& i_target, const float& i_weight ) {
        return LinearInterpolation( i_source, i_target, i_weight );
    } );
    o_module.def( "LinearInterpolation",
                  []( const Vec2fRange& i_source, const Vec2fRange& i_target, const float& i_weight ) {
                      return LinearInterpolation( i_source, i_target, i_weight );
                  } );
    o_module.def( "LinearInterpolation",
                  []( const Vec3fRange& i_source, const Vec3fRange& i_target, const float& i_weight ) {
                      return LinearInterpolation( i_source, i_target, i_weight );
                  } );
    o_module.def( "LinearInterpolation",
                  []( const Vec4fRange& i_source, const Vec4fRange& i_target, const float& i_weight ) {
                      return LinearInterpolation( i_source, i_target, i_weight );
                  } );
    o_module.def( "LinearInterpolation",
                  []( const FloatRange& i_source, const FloatRange& i_target, const float& i_weight ) {
                      return LinearInterpolation( i_source, i_target, i_weight );
                  } );
}