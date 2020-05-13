#pragma once

/// \file vec4f.h

#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/api.h>
#include <gm/tool/almost.h>
#include <gm/tool/assert.h>

GM_NAMESPACE_BEGIN

/// \class Vec4f
class GM_API Vec4f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Vec4f() = default;

    /// Destructor.
    ~Vec4f() = default;

    /// Element-wise constructor.
    explicit Vec4f( const float& i_element0, const float& i_element1, const float& i_element2, const float& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        GM_ASSERT( !HasNans() );
    }

#ifdef GM_DEBUG
    /// Copy constructor.
    Vec4f( const Vec4f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 4 );
        GM_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec4f& operator=( const Vec4f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 4 );
        GM_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline float& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const float& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    /// Vector addition.
    inline Vec4f operator+( const Vec4f& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return Vec4f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    /// Vector addition assignment.
    inline Vec4f& operator+=( const Vec4f& i_vector )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    /// Vector subtraction.
    inline Vec4f operator-( const Vec4f& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return Vec4f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    /// Vector subtraction assignment.
    inline Vec4f& operator-=( const Vec4f& i_vector )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    /// Scalar multiplication assignment.
    inline Vec4f& operator*=( const float& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    /// Scalar division.
    inline Vec4f operator/( const float& i_scalar ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec4f( m_elements[ 0 ] * reciprocal,
                      m_elements[ 1 ] * reciprocal,
                      m_elements[ 2 ] * reciprocal,
                      m_elements[ 3 ] * reciprocal );
    }

    /// Scalar division assignment.
    inline Vec4f& operator/=( const float& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        m_elements[ 3 ] *= reciprocal;
        return *this;
    }

    /// Unary negation.
    inline Vec4f operator-() const
    {
        GM_ASSERT( !HasNans() );
        return Vec4f( -m_elements[ 0 ], -m_elements[ 1 ], -m_elements[ 2 ], -m_elements[ 3 ] );
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
    inline float Z() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
    inline float W() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }

    /// Comparison operator
    inline bool operator==( const Vec4f& i_vector ) const
    {
        return AlmostEqual( m_elements[ 0 ], i_vector.m_elements[ 0 ] ) &&
               AlmostEqual( m_elements[ 1 ], i_vector.m_elements[ 1 ] ) &&
               AlmostEqual( m_elements[ 2 ], i_vector.m_elements[ 2 ] ) &&
               AlmostEqual( m_elements[ 3 ], i_vector.m_elements[ 3 ] );
    }

    /// Not equal operator
    inline bool operator!=( const Vec4f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 4;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Vec4f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << ", ";
        ss << m_elements[ 3 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 4 ] = {0, 0, 0, 0};
};

inline Vec4f operator*( const Vec4f& i_vector, const float& i_scalar )
{
    GM_ASSERT( !i_vector.HasNans() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

inline Vec4f operator*( const float& i_scalar, const Vec4f& i_vector )
{
    GM_ASSERT( !i_vector.HasNans() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

GM_NAMESPACE_END