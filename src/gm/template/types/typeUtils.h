{#
    C++ utility macro to generate a scalar or vector value
    type instance with uniform element values.
#}
{% macro GenUniformSequence(valueType, value, valueFn=None) %}
{%- if valueType.isScalar -%}
{%- if valueFn -%}
    {{ valueType.CppValue(valueFn(value)) }}
{%- else -%}
    {{ valueType.CppValue( value ) }}
{%- endif -%}
{%- elif valueType.isVector -%}
    gm::{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
{%- if valueFn -%}
    {{ valueType.CppValue(valueFn(value)) }}
{%- else -%}
    {{ valueType.CppValue(value) }}
{%- endif -%}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}

{#
    C++ utility macro to generate a scalar or vector value
    type instance with element values representing an arithmetic
    sequence.
#}
{% macro GenArithmeticSequence(valueType, value, valueFn=None) %}
{%- if valueType.isScalar -%}
{{- GenUniformSequence(valueType, value, valueFn=valueFn) -}}
{%- elif valueType.isVector -%}
    gm::{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
{%- if valueFn -%}
    {{ valueType.CppValue(valueFn(value * index)) }}
{%- else -%}
    {{ valueType.CppValue( value * index ) }}
{%- endif -%}
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
    Utility macro to generate a range value
#}
{% macro GenRange(rangeType, minValue, maxValue) %}
    gm::{{ rangeType.className }}(
        {{- GenUniformSequence(rangeType.elementType, minValue) -}},
        {{- GenUniformSequence(rangeType.elementType, maxValue) -}}
    )
{% endmacro %}

{#
    Utility macro to generate a range value with arithmetically increasing elements.
#}
{% macro GenArithmeticRange(rangeType, minValue, maxValue) %}
    gm::{{ rangeType.className }}(
        {{- GenArithmeticSequence(rangeType.elementType, minValue) -}},
        {{- GenArithmeticSequence(rangeType.elementType, maxValue) -}}
    )
{% endmacro %}
