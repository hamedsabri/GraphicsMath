//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/linearMap.h>

// Python bindings for LinearMap.

GM_NS_USING

void BindLinearMap( pybind11::module& o_module )
{
    o_module.def( "LinearMap",
                  []( const float& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
    o_module.def( "LinearMap",
                  []( const Mat3f& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
    o_module.def( "LinearMap",
                  []( const Mat4f& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
    o_module.def( "LinearMap",
                  []( const Vec2f& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
    o_module.def( "LinearMap",
                  []( const Vec3f& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
    o_module.def( "LinearMap",
                  []( const Vec4f& i_sourceValue, const Vec2f& i_sourceRange, const Vec2f& i_targetRange ) {
                      return LinearMap( i_sourceValue, i_sourceRange, i_targetRange );
                  } );
}