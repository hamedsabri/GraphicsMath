#pragma once

/// \file {{ context.headerFileName }}

#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/gm.h>
#include <gm/tool/assert.h>
{% if context.elementType.className != "int" -%}
#include <gm/tool/almost.h>
{%- endif %}

GM_NS_OPEN

/// \class {{ context.className }}
class {{ context.className }} final
{
public:
    /// Type of \ref {{ context.className }}'s elements.
    using ElementType = {{ context.elementType.className }};

    /// Default constructor.
    {{ context.className }}()  = default;

    /// Destructor.
    ~{{ context.className }}() = default;

    /// Element-wise constructor.
    explicit {{ context.className }}(
{% for index in range(context.elementSize) -%}
        const {{ context.elementType.className }}& i_element{{ index }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
        : m_elements{
{% for index in range(context.elementSize) -%}
        i_element{{ index }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
        }
    {
        GM_ASSERT( !HasNans() );
    }

#ifdef GM_DEBUG
    /// Copy constructor.
    {{ context.className }}( const {{ context.className }}& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ context.elementType.className }}  )* {{ context.elementSize }} );
        GM_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    {{ context.className }}& operator=( const {{ context.className }}& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ context.elementType.className }}  )* {{ context.elementSize }} );
        GM_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    GM_HOST_DEVICE inline {{ context.elementType.className }}& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ context.elementSize }} );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    GM_HOST_DEVICE inline const {{ context.elementType.className }}& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_index < {{ context.elementSize }} );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    /// Vector addition.
    GM_HOST_DEVICE inline {{ context.className }} operator+( const {{ context.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] + i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Vector addition assignment.
    GM_HOST_DEVICE inline {{ context.className }}& operator+=( const {{ context.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] += i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Vector subtraction.
    GM_HOST_DEVICE inline {{ context.className }} operator-( const {{ context.className }}& i_vector ) const
    {
        GM_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] - i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Vector subtraction assignment.
    GM_HOST_DEVICE inline {{ context.className }}& operator-=( const {{ context.className }}& i_vector )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] -= i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Scalar multiplication assignment.
    GM_HOST_DEVICE inline {{ context.className }}& operator*=( const {{ context.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] *= i_scalar;
{%- endfor %}
        return *this;
    }

    /// Scalar division.
    GM_HOST_DEVICE inline {{ context.className }} operator/( const {{ context.elementType.className }}& i_scalar ) const
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ context.GetCppNumber(0) }} );
{% if context.elementType == "float" or context.elementType == "double" -%}
        {{ context.elementType.className }} reciprocal = {{ context.GetCppNumber(1) }} / i_scalar;
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] * reciprocal
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- else -%}
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] / i_scalar
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
{%- endif %}
        );
    }

    /// Scalar division assignment.
    GM_HOST_DEVICE inline {{ context.className }}& operator/=( const {{ context.elementType.className }}& i_scalar )
    {
        GM_ASSERT( !HasNans() );
        GM_ASSERT( i_scalar != {{ context.GetCppNumber(0) }} );
{% if context.elementType == "float" or context.elementType == "double" -%}
        {{ context.elementType.className }} reciprocal = {{ context.GetCppNumber(1) }} / i_scalar;
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] *= reciprocal;
{%- endfor %}
{%- else -%}
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] /= i_scalar;
{%- endfor %}
{%- endif %}
        return *this;
    }

    /// Unary negation.
    GM_HOST_DEVICE inline {{ context.className }} operator-() const
    {
        GM_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        -m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

{% if context.dims|length == 2 -%}
    /// Matrix element read-access.
    GM_HOST_DEVICE inline const {{ context.elementType.className }}& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ i_row * {{ context.dims[ 0 ] }} + i_column ];
    }
{%- endif %}


{% if context.dims|length == 2 -%}
    /// Matrix element write-access.
    GM_HOST_DEVICE inline {{ context.elementType.className }}& operator()( size_t i_row, size_t i_column )
    {
        return m_elements[ i_row * {{ context.dims[ 0 ] }} + i_column ];
    }
{%- endif %}

{% if context.dims|length == 1 and context.elementSize <= 4 -%}
    /// X component accessor for the first element.
    GM_HOST_DEVICE inline {{ context.elementType.className }} X() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
{%- endif %}

{% if context.dims|length == 1 and context.elementSize >= 2 and context.elementSize <= 4 -%}
    /// Y component accessor for the second element.
    GM_HOST_DEVICE inline {{ context.elementType.className }} Y() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }
{%- endif %}

{% if context.dims|length == 1 and context.elementSize >= 3 and context.elementSize <= 4 -%}
    /// Z component accessor for the third element.
    GM_HOST_DEVICE inline {{ context.elementType.className }} Z() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
{%- endif %}

{% if context.dims|length == 1 and context.elementSize == 4 %}
    /// W component accessor for the fourth element.
    GM_HOST_DEVICE inline {{ context.elementType.className }} W() const
    {
        GM_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }
{%- endif %}

    /// Comparison operator
    GM_HOST_DEVICE inline bool operator==( const {{context.className}}& i_vector ) const
    {
        return
{% for index in range(context.elementSize) -%}
{% if context.elementType.className == "int" -%}
        m_elements[ {{ index }} ] == i_vector.m_elements[ {{ index }} ]
{%- else -%}
        AlmostEqual( m_elements[ {{ index }} ], i_vector.m_elements[ {{ index }} ] )
{%- endif %}
{%- if index + 1 < context.elementSize -%}
        &&
{% endif %}
{%- endfor -%}
        ;
    }

    /// Not equal operator
    GM_HOST_DEVICE inline bool operator!=( const {{context.className}}& i_vector ) const
    {
        return !( (*this) == i_vector );
    }

    /// Get the number of elements in this vector.
    GM_HOST_DEVICE inline static size_t GetElementSize()
    {
        return {{ context.elementSize }};
    }

    /// Are any of the element values NaNs?
    GM_HOST_DEVICE inline bool HasNans() const
    {
        return
{% for index in range(context.elementSize) -%}
        std::isnan( m_elements[ {{ index }} ] )
{%- if index + 1 < context.elementSize -%}
        ||
{%- endif %}
{%- endfor %}
        ;
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "{{ context.className }}( ";
{%- for index in range(context.elementSize) -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < context.elementSize -%}
        ss << ", ";
{%- endif %}
{%- endfor %}
        ss << " )";
        return ss.str();
    }

private:
    {{ context.elementType.className }} m_elements[ {{ context.elementSize }} ] = {
{%- for index in range(context.elementSize) -%}
        {{ context.GetCppNumber(0) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
    };
};

/// Vector-scalar multiplication.
GM_HOST_DEVICE inline {{ context.className }} operator*( const {{ context.className }}& i_vector, const {{ context.elementType.className }}& i_scalar )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ context.className }}(
{% for index in range(context.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < context.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

/// Scalar-vector multiplication.
GM_HOST_DEVICE inline {{ context.className }} operator*( const {{ context.elementType.className }}& i_scalar, const {{ context.className }}& i_vector )
{
    GM_ASSERT( !i_vector.HasNans() );
    return {{ context.className }}(
{% for index in range(context.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < context.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

GM_NS_CLOSE
