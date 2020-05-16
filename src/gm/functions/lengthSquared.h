#pragma once

/// \file functions/lengthSquared.h
///
/// Compute the length squared of a vector, defined as the <em>sum of the squares</em> of <em>each vector element</em>.
///
/// Can also be represented as the dot product (see \ref functions/dotProduct.h) of the vector with itself.

#include <gm/gm.h>

#include <gm/types/vec2f.h>
#include <gm/types/vec3f.h>
#include <gm/types/vec4f.h>

#include <gm/functions/lengthSquared.h>

GM_NS_OPEN

/// Compute the length squared of the vector \p i_vector.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline float LengthSquared( const Vec2f& i_vector )
{
    return DotProduct( i_vector, i_vector );
}

/// Compute the length squared of the vector \p i_vector.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline float LengthSquared( const Vec3f& i_vector )
{
    return DotProduct( i_vector, i_vector );
}

/// Compute the length squared of the vector \p i_vector.
///
/// \return the length squared of the vector.
GM_HOST_DEVICE inline float LengthSquared( const Vec4f& i_vector )
{
    return DotProduct( i_vector, i_vector );
}

PBR_NAMESPACE_END