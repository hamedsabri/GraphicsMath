#pragma once

/// \file vec2f.h

#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/gm.h>
#include <gm/tool/almost.h>
#include <gm/tool/assert.h>

GM_NS_BEGIN

/// \class Vec2f
class Vec2f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Vec2f() = default;

    /// Destructor.
    ~Vec2f() = default;

    /// Element-wise constructor.
    explicit Vec2f( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        GM_ASSERT( !HasNans() );
    }

#ifdef GM_DEBUG
    /// Copy constructor.
    Vec2f( const Vec2f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 2 );
        GM_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec2f& operator=( const Vec2f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 2 );
        GM_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline float& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const float& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    /// Vector addition.
    inline Vec2f operator+( const Vec2f& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return Vec2f( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    /// Vector addition assignment.
    inline Vec2f& operator+=( const Vec2f& i_vector )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    /// Vector subtraction.
    inline Vec2f operator-( const Vec2f& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return Vec2f( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    /// Vector subtraction assignment.
    inline Vec2f& operator-=( const Vec2f& i_vector )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    /// Scalar multiplication assignment.
    inline Vec2f& operator*=( const float& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    /// Scalar division.
    inline Vec2f operator/( const float& i_scalar ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec2f( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal );
    }

    /// Scalar division assignment.
    inline Vec2f& operator/=( const float& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        return *this;
    }

    /// Unary negation.
    inline Vec2f operator-() const
    {
        GM_ASSERT( !HasNans() );
        return Vec2f( -m_elements[ 0 ], -m_elements[ 1 ] );
    }

    inline float X() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
    inline float Y() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }

    /// Comparison operator
    inline bool operator==( const Vec2f& i_vector ) const
    {
        return AlmostEqual( m_elements[ 0 ], i_vector.m_elements[ 0 ] ) &&
               AlmostEqual( m_elements[ 1 ], i_vector.m_elements[ 1 ] );
    }

    /// Not equal operator
    inline bool operator!=( const Vec2f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 2;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Vec2f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 2 ] = {0, 0};
};

inline Vec2f operator*( const Vec2f& i_vector, const float& i_scalar )
{
    GM_ASSERT( !i_vector.HasNans() );
    return Vec2f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

inline Vec2f operator*( const float& i_scalar, const Vec2f& i_vector )
{
    GM_ASSERT( !i_vector.HasNans() );
    return Vec2f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

GM_NS_END