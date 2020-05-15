#pragma once

/// \file bounds3f.h

#include <sstream>

#include <gm/gm.h>

#include <gm/types/vec3f.h>

#include <limits>

GM_NS_BEGIN

/// \class Bounds3f
class Bounds3f final
{
public:
    /// Default constructor.
    Bounds3f() = default;

    /// Destructor.
    ~Bounds3f() = default;

    /// Element-wise constructor.
    explicit Bounds3f( const Vec3f& i_min, const Vec3f& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    GM_HOST_DEVICE const Vec3f& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    GM_HOST_DEVICE Vec3f& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    GM_HOST_DEVICE const Vec3f& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    GM_HOST_DEVICE Vec3f& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    std::string GetString()
    {
        std::stringstream ss;
        ss << "Bounds3f( ";
        ss << m_min.GetString();
        ss << ", ";
        ss << m_max.GetString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec3f m_min = Vec3f( std::numeric_limits< float >::max(),
                         std::numeric_limits< float >::max(),
                         std::numeric_limits< float >::max() );
    Vec3f m_max = Vec3f( std::numeric_limits< float >::min(),
                         std::numeric_limits< float >::min(),
                         std::numeric_limits< float >::min() );
};

GM_NS_END