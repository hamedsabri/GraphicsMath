#pragma once

/// \file {{ vectorType.headerFileName }}
/// \ingroup gm_types_vector

#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/gm.h>
#include <gm/base/assert.h>
{% if vectorType.elementType.className != "int" -%}
#include <gm/base/almost.h>
{%- endif %}

GM_NS_OPEN

/// \class {{ vectorType.className }}
/// \ingroup gm_types_vector
///
/// Class definition of a {{ vectorType.varName }} with {{ vectorType.elementSize }} {{ vectorType.elementType.className }} elements.
class {{ vectorType.className }} final
{
public:
    /// \typedef ElementType
    ///
    /// Convenience type definition of \ref {{ vectorType.className }}'s elements.
    using ElementType = {{ vectorType.elementType.className }};

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing all of the element values to 0.
    GM_HOST_DEVICE constexpr inline {{ vectorType.className }}()  = default;

    /// Element-wise constructor.
    GM_HOST_DEVICE explicit constexpr inline {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        const {{ vectorType.elementType.className }}& i_element{{ index }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
        : m_elements{
{% for index in range(vectorType.elementSize) -%}
        i_element{{ index }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
        }
    {
        GM_ASSERT( !HasNans() );
    }

    // --------------------------------------------------------------------- //
    /// \name Element access
    // --------------------------------------------------------------------- //

    /// Indexed element write access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than {{ vectorType.elementSize }}.
    ///
    /// \return mutable element value.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }}& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ vectorType.elementSize }} );
        return m_elements[ i_index ];
    }

    /// Indexed element read access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than {{ vectorType.elementSize }}.
    ///
    /// \return immutable element value.
    GM_HOST_DEVICE inline const {{ vectorType.elementType.className }}& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ vectorType.elementSize }} );
        return m_elements[ i_index ];
    }

{% if vectorType.shape|length == 2 -%}
    /// Matrix element read-access.
    GM_HOST_DEVICE inline const {{ vectorType.elementType.className }}& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ i_row * {{ vectorType.shape[ 0 ] }} + i_column ];
    }
{%- endif %}


{% if vectorType.shape|length == 2 -%}
    /// Matrix element write-access.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }}& operator()( size_t i_row, size_t i_column )
    {
        return m_elements[ i_row * {{ vectorType.shape[ 0 ] }} + i_column ];
    }
{%- endif %}

{% if vectorType.shape|length == 1 and vectorType.elementSize <= 4 -%}
    /// X component accessor for the first element.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }} X() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
{%- endif %}

{% if vectorType.shape|length == 1 and vectorType.elementSize >= 2 and vectorType.elementSize <= 4 -%}
    /// Y component accessor for the second element.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }} Y() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }
{%- endif %}

{% if vectorType.shape|length == 1 and vectorType.elementSize >= 3 and vectorType.elementSize <= 4 -%}
    /// Z component accessor for the third element.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }} Z() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
{%- endif %}

{% if vectorType.shape|length == 1 and vectorType.elementSize == 4 %}
    /// W component accessor for the fourth element.
    GM_HOST_DEVICE inline {{ vectorType.elementType.className }} W() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }
{%- endif %}

    // --------------------------------------------------------------------- //
    /// \name Arithmetic operators
    // --------------------------------------------------------------------- //

    /// Element-wise vector addition.
    ///
    /// Corresponding elements of the current vector and \p i_vector are added to form a new vector.
    ///
    /// \return the new vector.
    GM_HOST_DEVICE inline {{ vectorType.className }} operator+( const {{ vectorType.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] + i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Element-wise vector addition assignment.
    GM_HOST_DEVICE inline {{ vectorType.className }}& operator+=( const {{ vectorType.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] += i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Vector subtraction.
    GM_HOST_DEVICE inline {{ vectorType.className }} operator-( const {{ vectorType.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] - i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Vector subtraction assignment.
    GM_HOST_DEVICE inline {{ vectorType.className }}& operator-=( const {{ vectorType.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] -= i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Scalar multiplication assignment.
    GM_HOST_DEVICE inline {{ vectorType.className }}& operator*=( const {{ vectorType.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] *= i_scalar;
{%- endfor %}
        return *this;
    }

    /// Scalar division.
    GM_HOST_DEVICE inline {{ vectorType.className }} operator/( const {{ vectorType.elementType.className }}& i_scalar ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ vectorType.CppValue(0) }} );
{% if vectorType.elementType == "float" or vectorType.elementType == "double" -%}
        {{ vectorType.elementType.className }} reciprocal = {{ vectorType.CppValue(1) }} / i_scalar;
        return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] * reciprocal
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- else -%}
        return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] / i_scalar
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- endif %}
        );
    }

    /// Scalar division assignment.
    GM_HOST_DEVICE inline {{ vectorType.className }}& operator/=( const {{ vectorType.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ vectorType.CppValue(0) }} );
{% if vectorType.elementType == "float" or vectorType.elementType == "double" -%}
        {{ vectorType.elementType.className }} reciprocal = {{ vectorType.CppValue(1) }} / i_scalar;
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] *= reciprocal;
{%- endfor %}
{%- else -%}
{% for index in range(vectorType.elementSize) -%}
        m_elements[ {{ index }} ] /= i_scalar;
{%- endfor %}
{%- endif %}
        return *this;
    }

    /// Unary negation.
    GM_HOST_DEVICE inline {{ vectorType.className }} operator-() const
    {
        GM_ASSERT( !HasNans() );
        return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
        -m_elements[ {{ index }} ]
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    // --------------------------------------------------------------------- //
    /// \name Comparison operators
    // --------------------------------------------------------------------- //

    /// Comparison operator
    GM_HOST_DEVICE inline bool operator==( const {{vectorType.className}}& i_vector ) const
    {
        return
{% for index in range(vectorType.elementSize) -%}
{% if vectorType.elementType.className == "int" -%}
        m_elements[ {{ index }} ] == i_vector.m_elements[ {{ index }} ]
{%- else -%}
        AlmostEqual( m_elements[ {{ index }} ], i_vector.m_elements[ {{ index }} ] )
{%- endif %}
{%- if index + 1 < vectorType.elementSize -%}
        &&
{% endif %}
{%- endfor -%}
        ;
    }

    /// Not equal operator
    GM_HOST_DEVICE inline bool operator!=( const {{vectorType.className}}& i_vector ) const
    {
        return !( (*this) == i_vector );
    }

    // --------------------------------------------------------------------- //
    /// \name Shape
    // --------------------------------------------------------------------- //

    /// Get the number of elements in this vector.
    GM_HOST_DEVICE inline static size_t GetElementSize()
    {
        return {{ vectorType.elementSize }};
    }

    // --------------------------------------------------------------------- //
    /// \name Debug
    // --------------------------------------------------------------------- //

    /// Are any of the element values NaNs?
    GM_HOST_DEVICE inline bool HasNans() const
    {
        return
{% for index in range(vectorType.elementSize) -%}
        std::isnan( m_elements[ {{ index }} ] )
{%- if index + 1 < vectorType.elementSize -%}
        ||
{%- endif %}
{%- endfor %}
        ;
    }

    /// Get the string representation.  For debugging purposes.
    ///
    /// \param i_classPrefix optional string to prefix class tokens.
    ///
    /// \return descriptive string representing this type instance.
    inline std::string GetString( const std::string& i_classPrefix=std::string() ) const
    {
        std::stringstream ss;
        ss << i_classPrefix << "{{ vectorType.className }}( ";
{%- if vectorType.shape|length == 2 -%}
{%- for index in range(vectorType.elementSize) -%}
{%- if index % vectorType.shape[0] == 0 -%}
        ss << "\n    ";
{%- endif -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < vectorType.elementSize -%}
        ss << ", ";
{%- endif -%}
{%- endfor -%}
        ss << "\n)";
{%- else -%}
{%- for index in range(vectorType.elementSize) -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < vectorType.elementSize -%}
        ss << ", ";
{%- endif -%}
{%- endfor -%}
        ss << " )";
{%- endif -%}
        return ss.str();
    }

private:
    {{ vectorType.elementType.className }} m_elements[ {{ vectorType.elementSize }} ] = {
{%- for index in range(vectorType.elementSize) -%}
        {{ vectorType.CppValue(0) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
    };
};

/// Vector-scalar multiplication.
GM_HOST_DEVICE inline {{ vectorType.className }} operator*( const {{ vectorType.className }}& i_vector, const {{ vectorType.elementType.className }}& i_scalar )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < vectorType.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

/// Scalar-vector multiplication.
GM_HOST_DEVICE inline {{ vectorType.className }} operator*( const {{ vectorType.elementType.className }}& i_scalar, const {{ vectorType.className }}& i_vector )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < vectorType.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

/// Operator overload for << to enable writing the string representation of \p i_vector into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_vector the source vector value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const {{ vectorType.className }}& i_vector )
{
    o_outputStream << i_vector.GetString();
    return o_outputStream;
}

GM_NS_CLOSE
