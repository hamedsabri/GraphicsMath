{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Normal vector face forward.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}

#include <gm/functions/dotProduct.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set normal = interface.ArgName("normal") %}
{% set guide = interface.ArgName("guide") %}
{% set vectorType = interface.ArgType("normal") %}
/// Orient a normal vector {{ normal }} such that its direction is oriented towards the same
/// hemisphere as the guide vector {{ normal }} .
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ normal }} The normal vector.
/// \param {{ guide }} The guiding vector.
///
/// \return The oriented normal vector directed at the same hemisphere as the guide vector.
{{- functionUtils.signature(function, interface) -}}
{
    if ( DotProduct( {{ normal }}, {{ guide }} ) > 0.0f )
    {
        return {{ normal }};
    }
    else
    {
        return -{{ normal }};
    }
}
{% endfor %}
{% endblock %}
