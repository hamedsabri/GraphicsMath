{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Unit conversion from an angle encoded as radians into degrees.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/constants.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Converts angle \p {{ interface.ArgName("angle") }} from radians to degrees.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The angle in units of degrees.
{{- functionUtils.signature(function, interface) -}}
{
    constexpr {{ interface.ArgType("angle").className }} radiansToDegreesRatio =
        {{ interface.ArgType("angle").CppValue(180) }} / GM_PI;
    return {{ interface.ArgName("angle") }} * radiansToDegreesRatio;
}
{% endfor %}
{% endblock %}
