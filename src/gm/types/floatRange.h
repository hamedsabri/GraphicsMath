//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file floatRange.h
/// \ingroup gm_types_range

#include <gm/gm.h>

#include <limits>
#include <sstream>

GM_NS_OPEN

/// \class FloatRange
/// \ingroup gm_types_range
///
/// Class definition for a bounded range of float(s).
class FloatRange final
{
public:
    /// \typedef ValueType
    ///
    /// Convenience type definition of \ref FloatRange's elemental value type.
    using ValueType = float;

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing an \em empty range.
    ///
    /// An empty range has a min value with max numerical limit, conversely
    /// a max value with min numerical limit.
    GM_HOST_DEVICE constexpr inline FloatRange() = default;

    /// Explicit constructor for initializing a minimum maximum range.
    ///
    /// \param i_min Minimum.
    /// \param i_max Maximum.
    GM_HOST_DEVICE constexpr explicit inline FloatRange( const float& i_min, const float& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    // --------------------------------------------------------------------- //
    /// \name Access
    // --------------------------------------------------------------------- //

    /// Read access to the minimum bound of this range.
    ///
    /// \return The minimum bound.
    GM_HOST_DEVICE inline const float& Min() const
    {
        return m_min;
    }

    /// Write access to the minimum bound of this range.
    ///
    /// \return The minimum bound.
    GM_HOST_DEVICE inline float& Min()
    {
        return m_min;
    }

    /// Read access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline const float& Max() const
    {
        return m_max;
    }

    /// Write access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline float& Max()
    {
        return m_max;
    }

    // --------------------------------------------------------------------- //
    /// \name Containment
    // --------------------------------------------------------------------- //

    /// Check that \p i_value is inside the current range, inclusive of the both the
    /// min and max.
    ///
    /// \param i_value The value to test for inclusiveness within this range.
    ///
    /// \retval true If \p i_value is inside the current range.
    /// \retval false If \p i_value is outisde the current range.
    GM_HOST_DEVICE inline bool Contains( const float& i_value ) const
    {
        return i_value >= Min() && i_value <= Max();
    }

    /// Check that \p i_range is \em completely within the current range, as in, the \em min
    /// and \em max of \p i_range are \em both inclusive of the both the min and max
    /// of the current range..
    ///
    /// \param i_range The range to test for complete inclusiveness within this range.
    ///
    /// \retval true If \p i_range is \em completely inside the current range.
    /// \retval false If \p i_range is \em completely outisde the current range.
    GM_HOST_DEVICE inline bool Contains( const FloatRange& i_range ) const
    {
        return Contains( i_range.Min() ) && Contains( i_range.Max() );
    }

    // --------------------------------------------------------------------- //
    /// \name Debug
    // --------------------------------------------------------------------- //

    /// Get the string representation.  For debugging purposes.
    ///
    /// \param i_classPrefix optional string to prefix class tokens.
    ///
    /// \return descriptive string representing this type instance.
    inline std::string GetString( const std::string& i_classPrefix = std::string() ) const
    {
        std::stringstream ss;
        ss << i_classPrefix << "FloatRange( ";
        ss << m_min;
        ss << ", ";
        ss << m_max;
        ss << " )";
        return ss.str();
    }

private:
    // Min bound member.
    float m_min = std::numeric_limits< float >::max();

    // Max bound member.
    float m_max = std::numeric_limits< float >::min();
};

/// Operator overload for << to enable writing the string representation of \p i_value into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_value the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const FloatRange& i_value )
{
    o_outputStream << i_value.GetString();
    return o_outputStream;
}

GM_NS_CLOSE