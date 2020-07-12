//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/contains.h>

// Python bindings for Contains.

GM_NS_USING

void BindContains( pybind11::module& o_module )
{
    o_module.def( "Contains", []( const FloatRange& i_container, const float& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const FloatRange& i_container, const FloatRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const IntRange& i_container, const int& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const IntRange& i_container, const IntRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec2fRange& i_container, const Vec2f& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec2fRange& i_container, const Vec2fRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec3fRange& i_container, const Vec3f& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec3fRange& i_container, const Vec3fRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec4fRange& i_container, const Vec4f& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec4fRange& i_container, const Vec4fRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec2iRange& i_container, const Vec2i& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec2iRange& i_container, const Vec2iRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec3iRange& i_container, const Vec3i& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec3iRange& i_container, const Vec3iRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec4iRange& i_container, const Vec4i& i_containee ) {
        return Contains( i_container, i_containee );
    } );
    o_module.def( "Contains", []( const Vec4iRange& i_container, const Vec4iRange& i_containee ) {
        return Contains( i_container, i_containee );
    } );
}