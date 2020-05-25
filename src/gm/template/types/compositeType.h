#pragma once

/// \file {{ compositeType.headerFileName }}

#include <sstream>
{% for include in compositeType.extraIncludes -%}
#include {{ include }}
{% endfor %}

#include <gm/gm.h>
{% for element in compositeType.elements -%}
{% if element.type.isVector or element.type.isComposite -%}
#include <gm/types/{{ element.type.headerFileName }}>
{%- endif %}
{% endfor %}

GM_NS_OPEN

/// \class {{ compositeType.className }}
class {{ compositeType.className }} final
{
public:
    /// Default constructor.
    {{ compositeType.className }}()  = default;

    /// Destructor.
    ~{{ compositeType.className }}() = default;

    /// Element-wise constructor.
    explicit {{ compositeType.className }}(
{% for index in range(compositeType.elementSize) -%}
        const {{ compositeType.elements[ index ].type.className }}& i_{{ compositeType.elements[ index ].name }}
{%- if index + 1 < compositeType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
{% for index in range(compositeType.elementSize) -%}
{%- if index + 1 < compositeType.elementSize -%}
        :
{%- else -%}
        ,
{%- endif -%}
        m_{{ compositeType.elements[ index ].name }}( i_{{ compositeType.elements[ index ].name }} )
{%- endfor %}
    {
    }

{% for element in compositeType.elements %}
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
        ss << i_classPrefix << "{{ compositeType.className }}( ";
{%- for index in range(compositeType.elementSize) -%}
{%- if compositeType.elements[ index ].type.isVector or compositeType.elements[ index ].type.isComposite %}
        ss << m_{{ compositeType.elements[ index ].name }}.GetString( i_classPrefix );
{%- elif compositeType.elements[ index ].type.isScalar %}
        ss << m_{{ compositeType.elements[ index ].name }};
{%- endif %}
{%- if index + 1 < compositeType.elementSize -%}
        ss << ", ";
{%- endif %}
{%- endfor %}
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
{% for element in compositeType.elements -%}
    {{ element.type.className }} m_{{ element.name }}
{%- if element.defaultValue -%}
    = {{ element.defaultValue }}
{%- endif -%}
    ;
{%- endfor %}
};

GM_NS_CLOSE
