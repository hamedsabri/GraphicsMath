{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Vector transformation.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vector     = interface.ArgName("vector") %}
{% set vectorType = interface.ArgType("vector") %}
{% set matrix     = interface.ArgName("matrix") %}
{% set matrixType = interface.ArgType("matrix") %}
/// Transform a \p {{ vector }} with the transformation matrix \p {{ matrix }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ matrix }} The transformation matrix.
/// \param {{ vector }} The vector to transform.
///
/// \return Transformed vector.
{{- functionUtils.signature(function, interface) -}}
{
    return {{ vectorType.className }}(
{%- for row in range(vectorType.elementSize) -%}
{%- for col in range(vectorType.elementSize) -%}
        {{ vector }}[ {{ col }} ] * {{ matrix }}( {{ row }}, {{ col }} )
{%- if col + 1 < vectorType.elementSize -%}
    +
{%- endif -%}
{%- endfor -%}
{%- if row + 1 < vectorType.elementSize -%}
    ,
{%- endif -%}
{%- endfor -%}
    );
}
{% endfor %}
{% endblock %}
