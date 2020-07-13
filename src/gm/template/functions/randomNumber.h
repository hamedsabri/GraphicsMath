{% extends "functions/functionBase.h" %}
{% import "functions/functionUtils.h" as functionUtils %}

{%- block fileDoc -%}
/// Thread-safe random number generation.
///
/// Uniformly generate a random number within a numeric range.
{%- endblock %}

{% block includes %}
#include <gm/base/assert.h>

{{ functionUtils.typeIncludes(function) }}

#include <random>
{% endblock %}

{% block body %}
{% for interface in function.interfaces %}
{% set rangeArg  = interface.ArgName("range") %}
{% set rangeType = interface.ArgType("range") %}
/// Generates a random number within \p {{ rangeArg }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \warning Limit usage across multiple translation units.
/// A random number generator is allocated per-thread, per consumed translation unit.
///
/// \param {{ rangeArg }} Range to limit the generated number.
///
/// \return Randomly generated number.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ rangeArg }}.Min() != {{ rangeArg }}.Max() );
    static thread_local std::mt19937 generator;
{% if rangeType.elementType.className == "int" -%}
    std::uniform_int_distribution
{%- else -%}
    std::uniform_real_distribution
{%- endif -%}
    < {{ rangeType.elementType.className }} > distribution(
        {{ rangeArg }}.Min(),
        {{ rangeArg }}.Max()
{%- if rangeType.elementType.className == "int" -%}
        - {{ rangeType.CppValue( 1 ) }}
{%- endif -%}
    );
    return distribution( generator );
}
{% endfor %}
{% endblock %}
