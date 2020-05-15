#pragma once

/// \file functions/dotProduct.h
///
/// Dot product, or scalar product between two <em>equal-length</em> vectors.
///
/// The corresponding elements of the two vector(s) are multipled, and the products reduced via summation,
/// into a single value.
///
/// This operation can be geometrically represented as the magnitudes between the vectors and the cosine of
/// the angle between them.

#include <gm/gm.h>

#include <gm/types/vec2f.h>
#include <gm/types/vec3f.h>
#include <gm/types/vec4f.h>

GM_NS_BEGIN

/// Compute the dot product of two \ref Vec2f, \p i_lhs and \p i_rhs, and return the result.
///
/// \return computed dot product.
GM_HOST_DEVICE
inline float DotProduct( const Vec2f& i_lhs, const Vec2f& i_rhs )
{
    float product;
    product += i_lhs[ 0 ] * i_rhs[ 0 ];
    product += i_lhs[ 1 ] * i_rhs[ 1 ];
    return product;
}

/// Compute the dot product of two \ref Vec3f, \p i_lhs and \p i_rhs, and return the result.
///
/// \return computed dot product.
GM_HOST_DEVICE
inline float DotProduct( const Vec3f& i_lhs, const Vec3f& i_rhs )
{
    float product;
    product += i_lhs[ 0 ] * i_rhs[ 0 ];
    product += i_lhs[ 1 ] * i_rhs[ 1 ];
    product += i_lhs[ 2 ] * i_rhs[ 2 ];
    return product;
}

/// Compute the dot product of two \ref Vec4f, \p i_lhs and \p i_rhs, and return the result.
///
/// \return computed dot product.
GM_HOST_DEVICE
inline float DotProduct( const Vec4f& i_lhs, const Vec4f& i_rhs )
{
    float product;
    product += i_lhs[ 0 ] * i_rhs[ 0 ];
    product += i_lhs[ 1 ] * i_rhs[ 1 ];
    product += i_lhs[ 2 ] * i_rhs[ 2 ];
    product += i_lhs[ 3 ] * i_rhs[ 3 ];
    return product;
}

GM_NS_END