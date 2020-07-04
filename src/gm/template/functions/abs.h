{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Find the absolute value of two input values, defined as the magnitude of a real number without its sign.
///
/// If the value type is a vector, the absolute value will be performed on each element.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <algorithm>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Find the absolute value of the input \p {{ interface.ArgName("value") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The absolute value of the input.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("value").type.isScalar -%}
    return std::abs( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::abs( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
