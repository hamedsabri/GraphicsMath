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
/// Clamp the value \p {{ interface.ArgName("value") }} with into the range {{ interface.ArgName("range") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("value") }} Value to clamp.
/// \param {{ interface.ArgName("range") }} Range to clamp the value into.
///
/// \return Clamped value.
{{- functionUtils.signature(function, interface) -}}
{
{% if interface.Arg("value").type.isScalar -%}
    if ( {{ interface.ArgName("range") }}.Min() > {{ interface.ArgName("value") }} )
    {
        return {{ interface.ArgName("range") }}.Min();
    }
    else if ( {{ interface.ArgName("range") }}.Max() < {{ interface.ArgName("value") }} )
    {
        return {{ interface.ArgName("range") }}.Max();
    }
    else
    {
        return {{ interface.ArgName("value") }};
    }
{% else -%}
    return {{ interface.ArgClass("value") }}(
{%- for index in range(interface.Arg("value").type.elementSize) %}
        {{ function.name }}( {{ interface.ArgName("value") }}[ {{ index }} ], {{ interface.ArgName("range") }} )
{%- if index + 1 < interface.Arg("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% endif -%}
}
{% endfor %}
{% endblock %}
