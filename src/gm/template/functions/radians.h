{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Unit conversion from an angle encoded as degrees into radians.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/constants.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set angle     = interface.ArgName("angle") %}
{% set angleType = interface.ArgType("angle") %}
/// Converts angle \p {{ angle }} from degrees to radians.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ angle }} The input angle in unit of \em degrees.
///
/// \return The angle in units of radians.
{{- functionUtils.signature(function, interface) -}}
{
    constexpr {{ angleType.className }} degreesToRadiansRatio = Pi / {{ angleType.CppValue(180) }};
    return {{ angle }} * degreesToRadiansRatio;
}
{% endfor %}
{% endblock %}
