{% extends "types/typeBase.h" %}

{% block includes %}
{% if valueType.elementType.isVector %}
#include <gm/types/{{ valueType.elementType.headerFileName }}>
{%- endif %}

{% if valueType.elementType.className != "int" -%}
#include <gm/base/almost.h>
{%- endif %}

#include <limits>
#include <sstream>
{% endblock %}

{% block body %}

/// \class {{ valueType.className }}
/// \ingroup gm_types_{{ valueType.CATEGORY }}
///
/// Class definition for a bounded range of {{ valueType.elementType.className }}(s).
class {{ valueType.className }} final
{
public:
    /// \typedef ValueType
    ///
    /// Convenience type definition of \ref {{ valueType.className }}'s elemental value type.
    using ValueType = {{ valueType.elementType.className }};

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing an \em empty range.
    ///
    /// An empty range has a min value with max numerical limit, conversely
    /// a max value with min numerical limit.
    GM_HOST_DEVICE constexpr inline {{ valueType.className }}() = default;

    /// Explicit constructor for initializing a minimum maximum range.
    ///
    /// \param i_min Minimum.
    /// \param i_max Maximum.
    GM_HOST_DEVICE constexpr explicit inline {{ valueType.className }}(
        const {{ valueType.elementType.className }}& i_min,
        const {{ valueType.elementType.className }}& i_max
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
    GM_HOST_DEVICE inline const {{ valueType.elementType.className }}& Min() const
    {
        return m_min;
    }

    /// Write access to the minimum bound of this range.
    ///
    /// \return The minimum bound.
    GM_HOST_DEVICE inline {{ valueType.elementType.className }}& Min()
    {
        return m_min;
    }

    /// Read access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline const {{ valueType.elementType.className }}& Max() const
    {
        return m_max;
    }

    /// Write access to the maximum bound of this range.
    ///
    /// \return The maximum bound.
    GM_HOST_DEVICE inline {{ valueType.elementType.className }}& Max()
    {
        return m_max;
    }

    // --------------------------------------------------------------------- //
    /// \name Comparison
    // --------------------------------------------------------------------- //

    /// Equality comparison against \p i_range.
    ///
    /// \param i_range The range to compare against.
    ///
    /// \retval true If this range is equal to \p i_range.
    /// \retval false If this range is not equal to \p i_range.
    GM_HOST_DEVICE inline bool operator==( const {{valueType.className}}& i_range ) const
    {
{% if valueType.elementType.isScalar and valueType.elementType.className == "float" -%}
        return AlmostEqual( Min(), i_range.Min() ) && AlmostEqual( Min(), i_range.Min() );
{% else -%}
        return Min() == i_range.Min() && Max() == i_range.Max();
{%- endif -%}
    }

    /// Non-equality comparison against \p i_range.
    ///
    /// \param i_range The range to compare against.
    ///
    /// \retval true If this range is not equal to \p i_range.
    /// \retval false If this range is equal to \p i_range.
    GM_HOST_DEVICE inline bool operator!=( const {{ valueType.className }}& i_range ) const
    {
        return !( (*this) == i_range );
    }

    /// Check if this range is empty.
    ///
    /// A range is empty if any of the components in the minimum is greater
    /// than the maximum.
    ///
    /// \retval true If this range is empty.
    /// \retval false If this range is non-empty.
    GM_HOST_DEVICE inline bool IsEmpty() const
    {
{% if valueType.elementType.isScalar -%}
        return Min() > Max();
{% elif valueType.elementType.isVector -%}
        return
{%- for index in range(valueType.elementType.elementSize) %}
        Min()[ {{ index }} ] > Max()[ {{ index }} ]
{%- if index + 1 < valueType.elementType.elementSize -%}
        ||
{%- endif -%}
{%- endfor %}
        ;
{%- endif -%}
    }

{% if valueType.elementType.isScalar and valueType.elementType.className == "int" %}
    // --------------------------------------------------------------------- //
    /// \name Range iteration.
    // --------------------------------------------------------------------- //

    /// \class iterator
    ///
    /// Iterator class for the range {{ valueType.className }}.
    class iterator final
    {
    public:
        /// Iterator construction, with the current position.
        ///
        /// \param i_current The position to initialize this iterator to.
        inline iterator( const {{ valueType.elementType.className }}& i_current )
            : m_currentValue( i_current )
        {
        }

        /// Check if the current position of the iterator matches another.
        inline bool operator!=( const iterator& i_other ) const
        {
            return m_currentValue != i_other.m_currentValue;
        }

        /// De-reference this iterator, returning the value.
        inline const {{ valueType.elementType.className }}& operator*() const
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
        {{ valueType.elementType.className }} m_currentValue;
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
{% elif valueType.elementType.isVector and valueType.elementType.elementType.className == "int" %}
    // --------------------------------------------------------------------- //
    /// \name Range iteration.
    // --------------------------------------------------------------------- //

    /// \class iterator
    ///
    /// Iterator class for the range {{ valueType.className }}.
    class iterator final
    {
    public:
        /// Iterator construction, with the current position.
        ///
        /// \param i_current The position to initialize this iterator to.
        /// \param i_min the minimum of the range.
        /// \param i_max the maximum of the range.
        inline iterator(
            const {{ valueType.elementType.className }}& i_current,
            const {{ valueType.elementType.className }}& i_min,
            const {{ valueType.elementType.className }}& i_max
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
        inline const {{ valueType.elementType.className }}& operator*() const
        {
            return m_currentValue;
        }

        /// Increment this iterator forwards.
        inline const iterator& operator++()
        {
{% for componentIndex in range(valueType.elementType.elementSize) -%}
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
        {{ valueType.elementType.className }} m_currentValue;
        {{ valueType.elementType.className }} m_min;
        {{ valueType.elementType.className }} m_max;
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
        ss << i_classPrefix << "{{ valueType.className }}( ";
{%- if valueType.elementType.isScalar %}
        ss << m_min;
{%- else -%}
        ss << m_min.GetString( i_classPrefix );
{%- endif -%}
        ss << ", ";
{%- if valueType.elementType.isScalar -%}
        ss << m_max;
{%- else -%}
        ss << m_max.GetString( i_classPrefix );
{%- endif %}
        ss << " )";
        return ss.str();
    }

private:
    // Min bound member.
{%- if valueType.elementType.isScalar %}
    {{ valueType.elementType.className }} m_min = std::numeric_limits< {{ valueType.elementType.className }} >::max();
{%- elif valueType.elementType.isVector %}
    {{ valueType.elementType.className }} m_min = {{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
        std::numeric_limits< {{ valueType.elementType.elementType.className }} >::max()
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% endif %}

    // Max bound member.
{%- if valueType.elementType.isScalar %}
    {{ valueType.elementType.className }} m_max = std::numeric_limits< {{ valueType.elementType.className }} >::min();
{%- elif valueType.elementType.isVector %}
    {{ valueType.elementType.className }} m_max = {{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
        std::numeric_limits< {{ valueType.elementType.elementType.className }} >::min()
{%- if index + 1 < valueType.elementType.elementSize -%}
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
inline std::ostream& operator<<( std::ostream& o_outputStream, const {{ valueType.className }}& i_value )
{
    o_outputStream << i_value.GetString();
    return o_outputStream;
}

{% endblock %}
