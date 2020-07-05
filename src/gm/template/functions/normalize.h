{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Vector normalization.
///
/// The computation divides each of its elements by the vector length/magnitude.  The normalized vector is defined as a unit vector.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/assert.h>
#include <gm/functions/length.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
/// Compute the normalised vector from the input vector \p {{ interface.ArgName("vector") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ interface.ArgName("vector") }} Input vector.
///
/// \return Normalised vector.
{{- functionUtils.signature(function, interface) -}}
{
    {{ interface.ArgType("vector").elementType.className }} length = Length( {{ interface.ArgName("vector") }} );
    GM_ASSERT( length != {{ interface.ArgType("vector").CppValue( 0 ) }} );
    return {{ interface.ArgName("vector") }} / length;
}
{% endfor %}
{% endblock %}
