{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Ceil the input value, by rounding upwards to the nearest integral value.
/// If the value type is a vector, the ceil will be performed element-wise.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <cmath>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Ceil the input \ref {{ interface.ArgClass("value") }} \p {{ interface.ArgName("value") }},
/// rounding upwards to the nearest integral value.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The upward rounded input value.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("value").type.isScalar -%}
    return std::ceil( {{ interface.ArgName("value") }} );
{%- elif interface.Arg("value").type.isVector -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        std::ceil( {{ interface.ArgName("value") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
