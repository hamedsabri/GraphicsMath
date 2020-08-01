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
{% set angle     = interface.ArgName("angle") %}
{% set angleType = interface.ArgType("angle") %}
/// Converts angle \p {{ angle }} from radians to degrees.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The angle in units of degrees.
{{- functionUtils.signature(function, interface) -}}
{
    constexpr {{ angleType.className }} radiansToDegreesRatio = {{ angleType.CppValue(180) }} / Pi;
    return {{ angle }} * radiansToDegreesRatio;
}
{% endfor %}
{% endblock %}
