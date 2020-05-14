#pragma once

/// \file bounds2i.h

#include <sstream>

#include <gm/gm.h>

#include <gm/type/vec2i.h>

#include <limits>

GM_NS_BEGIN

/// \class Bounds2i
class Bounds2i final
{
public:
    /// Default constructor.
    Bounds2i() = default;

    /// Destructor.
    ~Bounds2i() = default;

    /// Element-wise constructor.
    explicit Bounds2i( const Vec2i& i_min, const Vec2i& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    GM_HOST_DEVICE const Vec2i& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    GM_HOST_DEVICE Vec2i& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    GM_HOST_DEVICE const Vec2i& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    GM_HOST_DEVICE Vec2i& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    std::string GetString()
    {
        std::stringstream ss;
        ss << "Bounds2i( ";
        ss << m_min.GetString();
        ss << ", ";
        ss << m_max.GetString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec2i m_min = Vec2i( std::numeric_limits< int >::max(), std::numeric_limits< int >::max() );
    Vec2i m_max = Vec2i( std::numeric_limits< int >::min(), std::numeric_limits< int >::min() );
};

GM_NS_END