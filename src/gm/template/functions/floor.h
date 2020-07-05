{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Floor the input value, by rounding downwards, returning the largest integral number less than the input.
/// If the value type is a vector, the floor will be performed element-wise.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <cmath>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Floor the input \ref {{ interface.ArgClass("value") }} \p {{ interface.ArgName("value") }} and return it.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("value") }} Value to floor.
///
/// \return Floored input value.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("value").type.isScalar -%}
    return std::floor( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::floor( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
