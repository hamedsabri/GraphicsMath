{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Check if a container, such as a range contains a specified element or range of elements.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/min.h>
#include <gm/functions/max.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set category = interface.ArgType("container").CATEGORY %}
{% set container = interface.ArgName("container") %}
{% set containee = interface.ArgName("containee") %}
{% set containeeType = interface.ArgType("containee") %}
/// Check if the {{ category }} \p {{ container }} completely contains \p {{ containee }}.
///
/// \param {{ container }} The {{ category }} container.
/// \param {{ containee }} The {{ containee }}.
///
/// \retval true If \p {{ containee }} is completely contained within {{ container }}.
/// \retval false If \p {{ containee }} is not completely contained within {{ container }}.
{{- functionUtils.signature(function, interface) -}}
{
{% if containeeType.isScalar -%}
        return {{ containee }} >= {{ container }}.Min() && {{ containee }} <= {{ container }}.Max();
{% elif containeeType.isVector -%}
        return
{%- for index in range(containeeType.elementSize) %}
        {{ containee }}[ {{ index }} ] >= {{ container }}.Min()[ {{ index }} ] &&
        {{ containee }}[ {{ index }} ] <= {{ container }}.Max()[ {{ index }} ]
{%- if index + 1 < containeeType.elementSize -%}
        &&
{%- endif -%}
{%- endfor %}
        ;
{% elif containeeType.isRange -%}
        return Contains( {{ container }}, {{ containee }}.Min() ) &&
               Contains( {{ container }}, {{ containee }}.Max() );
{%- endif -%}
}
{% endfor %}
{% endblock %}
