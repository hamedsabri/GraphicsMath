{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Value clamp.
///
/// Clamp a scalar, or vector into a range such that:
/// - Any value less than the minimum will assume the minimum.
/// - Any value greater than the maximum will assume the maximum.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set value = interface.ArgName("value") %}
{% set valueType = interface.ArgType("value") %}
{% set rangeArg = interface.ArgName("range") %}
/// Clamp the value \p {{ value }} with into the range {{ rangeArg }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ value }} Value to clamp.
/// \param {{ rangeArg }} Range to clamp the value into.
///
/// \return Clamped value.
{{- functionUtils.signature(function, interface) -}}
{
{% if valueType.isScalar -%}
    if ( {{ rangeArg }}.Min() > {{ value }} )
    {
        return {{ rangeArg }}.Min();
    }
    else if ( {{ rangeArg }}.Max() < {{ value }} )
    {
        return {{ rangeArg }}.Max();
    }
    else
    {
        return {{ value }};
    }
{% else -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(valueType.elementSize) %}
        {{ function.name }}( {{ value }}[ {{ index }} ], {{ rangeArg }} )
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% endif -%}
}
{% endfor %}
{% endblock %}
