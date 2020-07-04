{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Compute the \b distance between two points.
///
/// The \b distance is computed by taking the \em length of the the <em>vector difference</em> between the two points.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/length.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Compute the distance of between points \p {{ interface.ArgName("pointA") }} and \p {{ interface.ArgName("pointB") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \return The distance between the two points.
GM_HOST_DEVICE inline {{ interface.returnType }} {{ function.name }}( {{ interface.typedArgs }} )
{
    return Length( {{ interface.ArgName("pointA") }} - {{ interface.ArgName("pointB") }} );
}
{% endfor %}
{% endblock %}
