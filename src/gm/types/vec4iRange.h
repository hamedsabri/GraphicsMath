//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file vec4iRange.h
/// \ingroup gm_types_range

#include <gm/gm.h>

#include <gm/types/vec4i.h>

#include <limits>
#include <sstream>

GM_NS_OPEN

/// \class Vec4iRange
/// \ingroup gm_types_range
///
/// Class definition for a bounded range of Vec4i(s).
class Vec4iRange final
{
public:
    /// \typedef ValueType
    ///
    /// Convenience type definition of \ref Vec4iRange's elemental value type.
    using ValueType = Vec4i;

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing an \em empty range.
    ///
    /// An empty range has a min value with max numerical limit, conversely
    /// a max value with min numerical limit.
    GM_HOST_DEVICE constexpr inline Vec4iRange() = default;

    /// Explicit constructor for initializing a minimum maximum range.
    ///
    /// \param i_min Minimum.
    /// \param i_max Maximum.
    GM_HOST_DEVICE constexpr explicit inline Vec4iRange( const Vec4i& i_min, const Vec4i& i_max )
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
    GM_HOST_DEVICE inline const Vec4i& Min() const
    {
        return m_min;
    }

    /// Write access to the minimum bound of this range.
    ///
    /// \return The minimum bound.
    GM_HOST_DEVICE inline Vec4i& Min()
    {
        return m_min;
    }

    /// Read access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline const Vec4i& Max() const
    {
        return m_max;
    }

    /// Write access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline Vec4i& Max()
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
    GM_HOST_DEVICE inline bool Contains( const Vec4i& i_value ) const
    {
        return i_value[ 0 ] >= Min()[ 0 ] && i_value[ 0 ] <= Max()[ 0 ] && i_value[ 1 ] >= Min()[ 1 ] &&
               i_value[ 1 ] <= Max()[ 1 ] && i_value[ 2 ] >= Min()[ 2 ] && i_value[ 2 ] <= Max()[ 2 ] &&
               i_value[ 3 ] >= Min()[ 3 ] && i_value[ 3 ] <= Max()[ 3 ];
    }

    /// Check that \p i_range is \em completely within the current range, as in, the \em min
    /// and \em max of \p i_range are \em both inclusive of the both the min and max
    /// of the current range..
    ///
    /// \param i_range The range to test for complete inclusiveness within this range.
    ///
    /// \retval true If \p i_range is \em completely inside the current range.
    /// \retval false If \p i_range is \em completely outisde the current range.
    GM_HOST_DEVICE inline bool Contains( const Vec4iRange& i_range ) const
    {
        return Contains( i_range.Min() ) && Contains( i_range.Max() );
    }

    // --------------------------------------------------------------------- //
    /// \name Range iteration.
    // --------------------------------------------------------------------- //

    /// \class iterator
    ///
    /// Iterator class for the range Vec4iRange.
    class iterator final
    {
    public:
        /// Iterator construction, with the current position.
        ///
        /// \param i_current The position to initialize this iterator to.
        /// \param i_min the minimum of the range.
        /// \param i_max the maximum of the range.
        inline iterator( const Vec4i& i_current, const Vec4i& i_min, const Vec4i& i_max )
            : m_currentValue( i_current )
            , m_min( i_min )
            , m_max( i_max )
        {
        }

        /// Check if the current position of the iterator matches another.
        inline bool operator!=( const iterator& i_other ) const
        {
            return m_currentValue != i_other.m_currentValue;
        }

        /// De-reference this iterator, returning the value.
        inline const Vec4i& operator*() const
        {
            return m_currentValue;
        }

        /// Increment this iterator forwards.
        inline const iterator& operator++()
        {
            if ( m_currentValue[ 0 ] + 1 < m_max[ 0 ] )
            {
                m_currentValue[ 0 ] += 1;
            }
            else if ( m_currentValue[ 1 ] + 1 < m_max[ 1 ] )
            {
                m_currentValue[ 0 ] = m_min[ 0 ];
                m_currentValue[ 1 ] += 1;
            }
            else if ( m_currentValue[ 2 ] + 1 < m_max[ 2 ] )
            {
                m_currentValue[ 0 ] = m_min[ 0 ];
                m_currentValue[ 1 ] = m_min[ 1 ];
                m_currentValue[ 2 ] += 1;
            }
            else if ( m_currentValue[ 3 ] + 1 < m_max[ 3 ] )
            {
                m_currentValue[ 0 ] = m_min[ 0 ];
                m_currentValue[ 1 ] = m_min[ 1 ];
                m_currentValue[ 2 ] = m_min[ 2 ];
                m_currentValue[ 3 ] += 1;
            }
            else
            {
                m_currentValue = m_max;
            }

            return ( *this );
        }

    private:
        Vec4i m_currentValue;
        Vec4i m_min;
        Vec4i m_max;
    };

    /// Get the iterator with the position at the \em beginning of the range.
    inline iterator begin() const
    {
        return iterator( m_min, m_min, m_max );
    }

    /// Get the iterator with the position at the \em end of the range.
    inline iterator end() const
    {
        return iterator( m_max, m_min, m_max );
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
        ss << i_classPrefix << "Vec4iRange( ";
        ss << m_min.GetString( i_classPrefix );
        ss << ", ";
        ss << m_max.GetString( i_classPrefix );
        ss << " )";
        return ss.str();
    }

private:
    // Min bound member.
    Vec4i m_min = Vec4i( std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max() );

    // Max bound member.
    Vec4i m_max = Vec4i( std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min() );
};

/// Operator overload for << to enable writing the string representation of \p i_value into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_value the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const Vec4iRange& i_value )
{
    o_outputStream << i_value.GetString();
    return o_outputStream;
}

GM_NS_CLOSE