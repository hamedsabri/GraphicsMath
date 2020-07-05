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
/// Converts angle \p {{ interface.ArgName("angle") }} from degrees to radians.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("angle") }} The input angle in unit of \em degrees.
///
/// \return The angle in units of radians.
{{- functionUtils.signature(function, interface) -}}
{
    constexpr {{ interface.ArgType("angle").className }} degreesToRadiansRatio = GM_PI / {{ interface.ArgType("angle").CppValue(180) }};
    return {{ interface.ArgName("angle") }} * degreesToRadiansRatio;
}
{% endfor %}
{% endblock %}
