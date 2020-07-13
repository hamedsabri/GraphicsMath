{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Compute the \b length, or magnitude, of a vector.
///
/// The length of a vector is defined as the <em>square root</em> of the <em>sum of the squares</em>
/// of <em>each vector element</em>.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/lengthSquared.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vector = interface.ArgName("vector") %}
/// Compute the length of the vector \p {{ vector }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ vector }} The input vector.
///
/// \return The length of the vector.
{{- functionUtils.signature(function, interface) -}}
{
    return sqrt( LengthSquared( {{ vector }} ) );
}
{% endfor %}
{% endblock %}
