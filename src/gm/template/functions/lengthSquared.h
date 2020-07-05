{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Compute the length squared of a vector, defined as the <em>sum of the squares</em> of <em>each vector element</em>.
///
/// Can also be represented as the dot product (see \ref functions/dotProduct.h) of the vector with itself.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/functions/dotProduct.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Compute the length squared of the vector \p {{ interface.ArgName("vector") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("vector") }} The input vector.
///
/// \return the length squared of the vector.
{{- functionUtils.signature(function, interface) -}}
{
    return DotProduct( {{ interface.ArgName("vector") }},
                       {{ interface.ArgName("vector") }} );
}
{% endfor %}
{% endblock %}
