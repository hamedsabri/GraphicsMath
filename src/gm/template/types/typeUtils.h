{#
    Utility macro to generate a scalar or vector with uniform element values
#}
{% macro GenUniformValue(valueType, value) %}
{%- if valueType.isScalar -%}
    {{ valueType.CppValue( value ) }}
{%- elif valueType.isVector -%}
    gm::{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue( value ) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}

{#
   Utility macro to generate a scalar or vector with a specified leading element value,
   with other elements zeroed.
#}
{% macro GenLeadingValue(valueType, value) %}
{%- if valueType.isScalar -%}
    {{ valueType.CppValue( value ) }}
{%- elif valueType.isVector -%}
    gm::{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
{%- if index == 0 -%}
    {{ valueType.CppValue( value ) }}
{%- else -%}
    {{ valueType.CppValue( 0 ) }}
{%- endif -%}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}

{#
    Utility macro to generate an element value for a range type
#}
{% macro GenRangeElement(rangeType, value) %}
{{- GenUniformValue(rangeType.elementType, value) -}}
{% endmacro %}

{#
    Utility macro to generate a range value
#}
{% macro GenRange(rangeType, minValue, maxValue) %}
    gm::{{ rangeType.className }}(
        {{- GenRangeElement(rangeType, minValue) -}},
        {{- GenRangeElement(rangeType, maxValue) -}}
    )
{% endmacro %}

