{% extends "types/typeBase.h" %}

{% block includes %}
#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/base/assert.h>
{% if valueType.elementType.className != "int" -%}
#include <gm/base/almost.h>
{%- endif %}
{% endblock %}

{% block body %}
/// \class {{ valueType.className }}
/// \ingroup gm_types_{{ valueType.CATEGORY }}
///
/// Class definition of a {{ valueType.varName }} with {{ valueType.elementSize }} {{ valueType.elementType.className }} elements.
class {{ valueType.className }} final
{
public:
    /// \typedef ElementType
    ///
    /// Convenience type definition of \ref {{ valueType.className }}'s elements.
    using ElementType = {{ valueType.elementType.className }};

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing all of the element values to 0.
    GM_HOST_DEVICE constexpr inline {{ valueType.className }}() = default;

    /// Element-wise constructor.
    GM_HOST_DEVICE explicit constexpr inline {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        const {{ valueType.elementType.className }}& i_element{{ index }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
        : m_elements{
{% for index in range(valueType.elementSize) -%}
        i_element{{ index }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
        }
    {
        GM_ASSERT( !HasNans() );
    }

    // --------------------------------------------------------------------- //
    /// \name Indexed element access
    // --------------------------------------------------------------------- //

    /// Indexed element write access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than {{ valueType.elementSize }}.
    ///
    /// \return mutable element value.
    GM_HOST_DEVICE inline {{ valueType.elementType.className }}& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ valueType.elementSize }} );
        return m_elements[ i_index ];
    }

    /// Indexed element read access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than {{ valueType.elementSize }}.
    ///
    /// \return immutable element value.
    GM_HOST_DEVICE inline const {{ valueType.elementType.className }}& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ valueType.elementSize }} );
        return m_elements[ i_index ];
    }

{% if valueType.shape|length == 2 -%}
    // --------------------------------------------------------------------- //
    /// \name Matrix row column indexed element access
    // --------------------------------------------------------------------- //

    /// Matrix element read-access.
    ///
    /// \param i_row Row index.
    /// \param i_column Column index.
    ///
    /// \pre \p i_row must be less than {{ valueType.shape[0] }}.
    /// \pre \p i_column must be less than {{ valueType.shape[1] }}.
    ///
    /// \return Element value.
    GM_HOST_DEVICE inline const {{ valueType.elementType.className }}& operator()( size_t i_row, size_t i_column ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_row < {{ valueType.shape[0] }} );
        GM_ASSERT( i_column < {{ valueType.shape[1] }} );
        return m_elements[ i_row * {{ valueType.shape[ 0 ] }} + i_column ];
    }

    /// Matrix element write-access.
    ///
    /// \param i_row Row index.
    /// \param i_column Column index.
    ///
    /// \pre \p i_row must be less than {{ valueType.shape[ 1 ] }}.
    /// \pre \p i_column must be less than {{ valueType.shape[ 0 ] }}.
    ///
    /// \return Element value.
    GM_HOST_DEVICE inline {{ valueType.elementType.className }}& operator()( size_t i_row, size_t i_column )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_row < {{ valueType.shape[0] }} );
        GM_ASSERT( i_column < {{ valueType.shape[1] }} );
        return m_elements[ i_row * {{ valueType.shape[ 0 ] }} + i_column ];
    }
{%- endif %}

{% if valueType.shape|length == 1 and valueType.elementSize <= 4 -%}
    // --------------------------------------------------------------------- //
    /// \name Named element access.
    // --------------------------------------------------------------------- //
{%- endif %}

{% for namedElement in valueType.namedElements %}
    /// Convenience named const accessor for the element at index {{ loop.index0 }}.
    ///
    /// \return Const reference to the element at index {{ loop.index0 }}.
    GM_HOST_DEVICE inline const {{ valueType.elementType.className }}& {{ namedElement.accessorName }}() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ {{ loop.index0 }} ];
    }

    /// Convenience named mutable accessor for the element at index
    ///
    /// \return Mutable reference to the element at index {{ loop.index0 }}.
    GM_HOST_DEVICE inline {{ valueType.elementType.className }}& {{ namedElement.accessorName }}()
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ {{ loop.index0 }} ];
    }
{%- endfor %}

    // --------------------------------------------------------------------- //
    /// \name Arithmetic operators
    // --------------------------------------------------------------------- //

    /// Element-wise vector addition.
    ///
    /// Corresponding elements of the current vector and \p i_vector are added to form a new vector.
    ///
    /// \return the new vector.
    GM_HOST_DEVICE inline {{ valueType.className }} operator+( const {{ valueType.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] + i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Element-wise vector addition assignment.
    GM_HOST_DEVICE inline {{ valueType.className }}& operator+=( const {{ valueType.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] += i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Vector subtraction.
    GM_HOST_DEVICE inline {{ valueType.className }} operator-( const {{ valueType.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] - i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Vector subtraction assignment.
    GM_HOST_DEVICE inline {{ valueType.className }}& operator-=( const {{ valueType.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] -= i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Scalar multiplication assignment.
    GM_HOST_DEVICE inline {{ valueType.className }}& operator*=( const {{ valueType.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] *= i_scalar;
{%- endfor %}
        return *this;
    }

    /// Scalar division.
    GM_HOST_DEVICE inline {{ valueType.className }} operator/( const {{ valueType.elementType.className }}& i_scalar ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ valueType.CppValue(0) }} );
{% if valueType.elementType == "float" or valueType.elementType == "double" -%}
        {{ valueType.elementType.className }} reciprocal = {{ valueType.CppValue(1) }} / i_scalar;
        return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] * reciprocal
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- else -%}
        return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] / i_scalar
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- endif %}
        );
    }

    /// Scalar division assignment.
    GM_HOST_DEVICE inline {{ valueType.className }}& operator/=( const {{ valueType.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ valueType.CppValue(0) }} );
{% if valueType.elementType == "float" or valueType.elementType == "double" -%}
        {{ valueType.elementType.className }} reciprocal = {{ valueType.CppValue(1) }} / i_scalar;
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] *= reciprocal;
{%- endfor %}
{%- else -%}
{% for index in range(valueType.elementSize) -%}
        m_elements[ {{ index }} ] /= i_scalar;
{%- endfor %}
{%- endif %}
        return *this;
    }

    /// Unary negation.
    GM_HOST_DEVICE inline {{ valueType.className }} operator-() const
    {
        GM_ASSERT( !HasNans() );
        return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        -m_elements[ {{ index }} ]
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    // --------------------------------------------------------------------- //
    /// \name Comparison operators
    // --------------------------------------------------------------------- //

    /// Comparison operator
    GM_HOST_DEVICE inline bool operator==( const {{valueType.className}}& i_vector ) const
    {
        return
{% for index in range(valueType.elementSize) -%}
{% if valueType.elementType.className == "int" -%}
        m_elements[ {{ index }} ] == i_vector.m_elements[ {{ index }} ]
{%- else -%}
        AlmostEqual( m_elements[ {{ index }} ], i_vector.m_elements[ {{ index }} ] )
{%- endif %}
{%- if index + 1 < valueType.elementSize -%}
        &&
{% endif %}
{%- endfor -%}
        ;
    }

    /// Not equal operator
    GM_HOST_DEVICE inline bool operator!=( const {{valueType.className}}& i_vector ) const
    {
        return !( (*this) == i_vector );
    }

    // --------------------------------------------------------------------- //
    /// \name Shape
    // --------------------------------------------------------------------- //

    /// Get the number of elements in this vector.
    GM_HOST_DEVICE inline static size_t GetElementSize()
    {
        return {{ valueType.elementSize }};
    }

    // --------------------------------------------------------------------- //
    /// \name Debug
    // --------------------------------------------------------------------- //

    /// Are any of the element values NaNs?
    GM_HOST_DEVICE inline bool HasNans() const
    {
        return
{% for index in range(valueType.elementSize) -%}
        std::isnan( m_elements[ {{ index }} ] )
{%- if index + 1 < valueType.elementSize -%}
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
        ss << i_classPrefix << "{{ valueType.className }}( ";
{%- if valueType.shape|length == 2 -%}
{%- for index in range(valueType.elementSize) -%}
{%- if index % valueType.shape[0] == 0 -%}
        ss << "\n    ";
{%- endif -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < valueType.elementSize -%}
        ss << ", ";
{%- endif -%}
{%- endfor -%}
        ss << "\n)";
{%- else -%}
{%- for index in range(valueType.elementSize) -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < valueType.elementSize -%}
        ss << ", ";
{%- endif -%}
{%- endfor -%}
        ss << " )";
{%- endif -%}
        return ss.str();
    }

private:
    {{ valueType.elementType.className }} m_elements[ {{ valueType.elementSize }} ] = {
{%- for index in range(valueType.elementSize) -%}
        {{ valueType.CppValue(0) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
    };
};

/// Vector-scalar multiplication.
GM_HOST_DEVICE inline {{ valueType.className }} operator*( const {{ valueType.className }}& i_vector, const {{ valueType.elementType.className }}& i_scalar )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < valueType.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

/// Scalar-vector multiplication.
GM_HOST_DEVICE inline {{ valueType.className }} operator*( const {{ valueType.elementType.className }}& i_scalar, const {{ valueType.className }}& i_vector )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < valueType.elementSize -%}
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
inline std::ostream& operator<<( std::ostream& o_outputStream, const {{ valueType.className }}& i_vector )
{
    o_outputStream << i_vector.GetString();
    return o_outputStream;
}

{% endblock %}
