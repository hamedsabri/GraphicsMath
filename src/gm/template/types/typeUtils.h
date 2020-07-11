{# Utility macro to generate an element value for a range type #}
{% macro GenRangeElement( valueType, value ) %}
{%- if valueType.elementType.isScalar -%}
    {{ valueType.CppValue( value ) }}
{%- elif valueType.elementType.isVector -%}
    gm::{{ valueType.elementType.className }}(
{%- for index in range(valueType.elementType.elementSize) -%}
    {{ valueType.elementType.CppValue( value ) }}
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}

{# Utility macro to generate a range value #}
{% macro GenRange( valueType, minValue, maxValue ) %}
    gm::{{ valueType.className }}(
        {{- GenRangeElement( valueType, minValue ) -}},
        {{- GenRangeElement( valueType, maxValue ) -}}
    )
{% endmacro %}

