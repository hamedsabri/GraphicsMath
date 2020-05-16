#pragma once

/// \file bounds3i.h

#include <sstream>

#include <gm/gm.h>

#include <gm/types/vec3i.h>

#include <limits>

GM_NS_OPEN

/// \class Bounds3i
class Bounds3i final
{
public:
    /// Default constructor.
    Bounds3i() = default;

    /// Destructor.
    ~Bounds3i() = default;

    /// Element-wise constructor.
    explicit Bounds3i( const Vec3i& i_min, const Vec3i& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    GM_HOST_DEVICE inline const Vec3i& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    GM_HOST_DEVICE inline Vec3i& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    GM_HOST_DEVICE inline const Vec3i& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    GM_HOST_DEVICE inline Vec3i& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Bounds3i( ";
        ss << m_min.GetString();
        ss << ", ";
        ss << m_max.GetString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec3i m_min = Vec3i( std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max() );
    Vec3i m_max = Vec3i( std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min() );
};

GM_NS_CLOSE