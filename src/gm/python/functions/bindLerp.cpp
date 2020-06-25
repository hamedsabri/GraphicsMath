//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/lerp.h>

// Python bindings for Lerp.

GM_NS_USING

void BindLerp( pybind11::module& o_module )
{
    o_module.def( "Lerp", []( const float& i_valueA, const float& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
    o_module.def( "Lerp", []( const Mat3f& i_valueA, const Mat3f& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
    o_module.def( "Lerp", []( const Mat4f& i_valueA, const Mat4f& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
    o_module.def( "Lerp", []( const Vec2f& i_valueA, const Vec2f& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
    o_module.def( "Lerp", []( const Vec3f& i_valueA, const Vec3f& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
    o_module.def( "Lerp", []( const Vec4f& i_valueA, const Vec4f& i_valueB, const float& i_weight ) {
        return Lerp( i_valueA, i_valueB, i_weight );
    } );
}