{#
    Python utility macro to generate a scalar or vector value
    type instance with uniform element values.
#}
{% macro GenUniformSequence(valueType, value, valueFn=None) %}
{%- if valueType.isScalar -%}
{%- if valueFn -%}
    {{ valueType.PyValue(valueFn(value)) }}
{%- else -%}
    {{ valueType.PyValue( value ) }}
{%- endif -%}
{%- elif valueType.isVector -%}
    gm.{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
{%- if valueFn -%}
    {{ valueType.PyValue(valueFn(value)) }}
{%- else -%}
    {{ valueType.PyValue(value) }}
{%- endif -%}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}

{#
    Python utility macro to generate a scalar or vector value
    type instance with element values representing an arithmetic
    sequence.
#}
{% macro GenArithmeticSequence(valueType, value, valueFn=None) %}
{%- if valueType.isScalar -%}
{{- GenUniformSequence(valueType, value, valueFn=valueFn) -}}
{%- elif valueType.isVector -%}
    gm.{{ valueType.className }}(
{%- for index in range(valueType.elementSize) -%}
{%- if valueFn -%}
    {{ valueType.PyValue(valueFn(value * index)) }}
{%- else -%}
    {{ valueType.PyValue( value * index ) }}
{%- endif -%}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
{% endmacro %}
