{% extends "types/baseType.h" %}

{% block includes %}
#include <sstream>
{% for include in valueType.extraIncludes -%}
#include {{ include }}
{% endfor %}

{% for element in valueType.elements -%}
{% if element.type.isVector or element.type.isComposite -%}
#include <gm/types/{{ element.type.headerFileName }}>
{%- endif %}
{% endfor %}
{% endblock %}

{% block body %}

/// \class {{ valueType.className }}
/// \ingroup gm_types_composite
///
/// Class definition of a composite type with named elements:
{% for element in valueType.elements -%}
/// - {{ element.name }} (\ref {{ element.type.className }})
{% endfor -%}
class {{ valueType.className }} final
{
public:
    /// Default constructor.
    GM_HOST_DEVICE constexpr inline {{ valueType.className }}()  = default;

    /// Element-wise constructor.
    GM_HOST_DEVICE explicit constexpr inline {{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
        const {{ valueType.elements[ index ].type.className }}& i_{{ valueType.elements[ index ].name }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
{% for index in range(valueType.elementSize) -%}
{%- if index + 1 < valueType.elementSize -%}
        :
{%- else -%}
        ,
{%- endif -%}
        m_{{ valueType.elements[ index ].name }}( i_{{ valueType.elements[ index ].name }} )
{%- endfor %}
    {
    }

{% for element in valueType.elements %}
    /// Const accessor for "{{ element.name }}".
    GM_HOST_DEVICE inline const {{ element.type.className }}& {{ element.accessorName }}() const
    {
        return m_{{ element.name }};
    }

    /// Mutable accessor for "{{ element.name }}".
    GM_HOST_DEVICE inline {{ element.type.className }}& {{ element.accessorName }}()
    {
        return m_{{ element.name }};
    }
{% endfor %}

    /// Get the string representation.  For debugging purposes.
    ///
    /// \param i_classPrefix optional string to prefix class tokens.
    ///
    /// \return descriptive string representing this type instance.
    inline std::string GetString( const std::string& i_classPrefix=std::string() ) const
    {
        std::stringstream ss;
        ss << i_classPrefix << "{{ valueType.className }}( ";
{%- for index in range(valueType.elementSize) -%}
{%- if valueType.elements[ index ].type.isVector or valueType.elements[ index ].type.isComposite %}
        ss << m_{{ valueType.elements[ index ].name }}.GetString( i_classPrefix );
{%- elif valueType.elements[ index ].type.isScalar %}
        ss << m_{{ valueType.elements[ index ].name }};
{%- endif %}
{%- if index + 1 < valueType.elementSize -%}
        ss << ", ";
{%- endif %}
{%- endfor %}
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
{% for element in valueType.elements -%}
    {{ element.type.className }} m_{{ element.name }}
{%- if element.defaultValue -%}
    = {{ element.defaultValue }}
{%- endif -%}
    ;
{%- endfor %}
};

/// Operator overload for << to enable writing the string representation of \p i_composite into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_composite the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const {{ valueType.className }}& i_composite )
{
    o_outputStream << i_composite.GetString();
    return o_outputStream;
}

{% endblock %}
