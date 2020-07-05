{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Find the minimum of two input values.
/// If the value type is a vector, the maximum will be computed per-element.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <algorithm>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Find the maximum from the inputs \p {{ interface.ArgName("valueA") }} and \p {{ interface.ArgName("valueB") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("valueA") }} The first value to compare.
/// \param {{ interface.ArgName("valueB") }} The second value to compare.
///
/// \return The maximum of the two inputs.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("valueA").type.isScalar -%}
    return std::max( {{ interface.ArgName("valueA") }}, {{ interface.ArgName("valueB") }} );
{%- elif interface.Arg("valueA").type.isVector -%}
    return {{ interface.ArgClass("valueA") }}(
{%- for index in range(interface.Arg("valueA").type.elementSize) %}
        std::max( {{ interface.ArgName("valueA") }}[ {{ index }} ], {{ interface.ArgName("valueB") }}[ {{ index }} ] )
{%- if index + 1 < interface.Arg("valueA").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}
}
{% endfor %}
{% endblock %}
