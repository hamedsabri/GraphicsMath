{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Vector normalization.
///
/// The computation divides each of its elements by the vector length/magnitude.  The normalized vector is defined as a unit vector.
{%- endblock %}

{% block includes %}
{{ functionUtils.typeIncludes(function) }}
#include <gm/base/diagnostic.h>
#include <gm/functions/length.h>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set vector = interface.ArgName("vector") %}
{% set vectorType = interface.ArgType("vector") %}
/// Compute the normalised vector from the input vector \p {{ vector }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \param {{ vector }} Input vector.
///
/// \return Normalised vector.
{{- functionUtils.signature(function, interface) -}}
{
    {{ vectorType.elementType.className }} length = Length( {{ vector }} );
    GM_ASSERT( length != {{ vectorType.CppValue( 0 ) }} );
    return {{ vector }} / length;
}
{% endfor %}
{% endblock %}
