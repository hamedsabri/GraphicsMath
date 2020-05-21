//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file bounds2f.h

#include <sstream>

#include <gm/gm.h>

#include <gm/types/vec2f.h>

#include <limits>

GM_NS_OPEN

/// \class Bounds2f
class Bounds2f final
{
public:
    /// Default constructor.
    Bounds2f() = default;

    /// Destructor.
    ~Bounds2f() = default;

    /// Element-wise constructor.
    explicit Bounds2f( const Vec2f& i_min, const Vec2f& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    GM_HOST_DEVICE inline const Vec2f& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    GM_HOST_DEVICE inline Vec2f& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    GM_HOST_DEVICE inline const Vec2f& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    GM_HOST_DEVICE inline Vec2f& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Bounds2f( ";
        ss << m_min.GetString();
        ss << ", ";
        ss << m_max.GetString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec2f m_min = Vec2f( std::numeric_limits< float >::max(), std::numeric_limits< float >::max() );
    Vec2f m_max = Vec2f( std::numeric_limits< float >::min(), std::numeric_limits< float >::min() );
};

GM_NS_CLOSE