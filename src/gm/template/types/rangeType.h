#pragma once

/// \file {{ rangeType.headerFileName }}
/// \ingroup gm_types_range

#include <gm/gm.h>

{% if rangeType.elementType.isVector %}
#include <gm/types/{{ rangeType.elementType.headerFileName }}>
{%- endif %}

#include <limits>
#include <sstream>

GM_NS_OPEN

/// \class {{ rangeType.className }}
/// \ingroup gm_types_range
///
/// Class definition for a minimum, maximum range of {{ rangeType.elementType.className }}(s).
class {{ rangeType.className }} final
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing an \em empty range.
    ///
    /// An empty range has a min value with max numerical limit, conversely
    /// a max value with min numerical limit.
    GM_HOST_DEVICE constexpr inline {{ rangeType.className }}() = default;

    /// Explicit constructor for initializing a minimum maximum range.
    ///
    /// \param i_min Minimum bounds.
    /// \param i_max Maximum bounds.
    GM_HOST_DEVICE constexpr explicit inline {{ rangeType.className }}(
        const {{ rangeType.elementType.className }}& i_min,
        const {{ rangeType.elementType.className }}& i_max
    )
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
    GM_HOST_DEVICE inline const {{ rangeType.elementType.className }}& Min() const
    {
        return m_min;
    }

    /// Write access to the minimum bound of this range.
    ///
    /// \return The minimum bound.
    GM_HOST_DEVICE inline {{ rangeType.elementType.className }}& Min()
    {
        return m_min;
    }

    /// Read access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline const {{ rangeType.elementType.className }}& Max() const
    {
        return m_max;
    }

    /// Write access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline {{ rangeType.elementType.className }}& Max()
    {
        return m_max;
    }

{% if rangeType.elementType.isScalar and rangeType.elementType.className == "int" %}
    // --------------------------------------------------------------------- //
    /// \name Range iteration.
    // --------------------------------------------------------------------- //

    /// \class iterator
    ///
    /// Iterator class for the range {{ rangeType.className }}.
    class iterator final
    {
    public:
        /// Iterator construction, with the current position.
        ///
        /// \param i_current The position to initialize this iterator to.
        inline iterator( const {{ rangeType.elementType.className }}& i_current )
            : m_currentValue( i_current )
        {
        }

        /// Check if the current position of the iterator matches another.
        inline bool operator!=( const iterator& i_other ) const
        {
            return m_currentValue != i_other.m_currentValue;
        }

        /// De-reference this iterator, returning the value.
        inline const {{ rangeType.elementType.className }}& operator*() const
        {
            return m_currentValue;
        }

        /// Increment this iterator forwards.
        inline const iterator& operator++()
        {
            m_currentValue += 1;
            return ( *this );
        }

    private:
        {{ rangeType.elementType.className }} m_currentValue;
    };

    /// Get the iterator with the position at the \em beginning of the range.
    inline iterator begin() const
    {
        return iterator( m_min );
    }

    /// Get the iterator with the position at the \em end of the range.
    inline iterator end() const
    {
        return iterator( m_max );
    }
{% elif rangeType.elementType.isVector and rangeType.elementType.elementType.className == "int" %}
    // --------------------------------------------------------------------- //
    /// \name Range iteration.
    // --------------------------------------------------------------------- //

    /// \class iterator
    ///
    /// Iterator class for the range {{ rangeType.className }}.
    class iterator final
    {
    public:
        /// Iterator construction, with the current position.
        ///
        /// \param i_current The position to initialize this iterator to.
        /// \param i_min the minimum bounds of the range.
        /// \param i_max the maximum bounds of the range.
        inline iterator(
            const {{ rangeType.elementType.className }}& i_current,
            const {{ rangeType.elementType.className }}& i_min,
            const {{ rangeType.elementType.className }}& i_max
        )
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
        inline const {{ rangeType.elementType.className }}& operator*() const
        {
            return m_currentValue;
        }

        /// Increment this iterator forwards.
        inline const iterator& operator++()
        {
{% for componentIndex in range(rangeType.elementType.elementSize) -%}
{%- if componentIndex == 0 -%}
            if (
{%- else -%}
            else if (
{%- endif -%}
                 m_currentValue[ {{ componentIndex }} ] + 1 < m_max[ {{ componentIndex }} ]
            )
            {
{% for innerIndex in range(componentIndex + 1) -%}
{%- if innerIndex == componentIndex -%}
                m_currentValue[ {{ innerIndex }} ] += 1;
{%- else -%}
                m_currentValue[ {{ innerIndex }} ] = m_min[ {{ innerIndex }} ];
{%- endif -%}
{%- endfor %}
            }
{%- endfor %}
            else
            {
                m_currentValue = m_max;
            }

            return ( *this );
        }

    private:
        {{ rangeType.elementType.className }} m_currentValue;
        {{ rangeType.elementType.className }} m_min;
        {{ rangeType.elementType.className }} m_max;
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
{% endif %}

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
        ss << i_classPrefix << "{{ rangeType.className }}( ";
{%- if rangeType.elementType.isScalar %}
        ss << m_min;
{%- else -%}
        ss << m_min.GetString( i_classPrefix );
{%- endif -%}
        ss << ", ";
{%- if rangeType.elementType.isScalar -%}
        ss << m_max;
{%- else -%}
        ss << m_max.GetString( i_classPrefix );
{%- endif %}
        ss << " )";
        return ss.str();
    }

private:
    // Min bound member.
{%- if rangeType.elementType.isScalar %}
    {{ rangeType.elementType.className }} m_min = std::numeric_limits< {{ rangeType.elementType.className }} >::max();
{%- elif rangeType.elementType.isVector %}
    {{ rangeType.elementType.className }} m_min = {{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
        std::numeric_limits< {{ rangeType.elementType.elementType.className }} >::max()
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% endif %}

    // Max bound member.
{%- if rangeType.elementType.isScalar %}
    {{ rangeType.elementType.className }} m_max = std::numeric_limits< {{ rangeType.elementType.className }} >::min();
{%- elif rangeType.elementType.isVector %}
    {{ rangeType.elementType.className }} m_max = {{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
        std::numeric_limits< {{ rangeType.elementType.elementType.className }} >::min()
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% endif %}
};

/// Operator overload for << to enable writing the string representation of \p i_value into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_value the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const {{ rangeType.className }}& i_value )
{
    o_outputStream << i_value.GetString();
    return o_outputStream;
}

GM_NS_CLOSE
