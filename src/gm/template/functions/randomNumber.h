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
/// Generates a random number within \p {{ interface.ArgName("range") }}.
/// \ingroup gm_functions_{{ function.category }}
///
/// \warning Limit usage across multiple translation units.
/// A random number generator is allocated per-thread, per consumed translation unit.
///
/// \param {{ interface.ArgName("range") }} Range to limit the generated number.
///
/// \return Randomly generated number.
{{- functionUtils.signature(function, interface) -}}
{
    GM_ASSERT( {{ interface.ArgName("range") }}.Min() != {{ interface.ArgName("range") }}.Max() );
    static thread_local std::mt19937 generator;
{% if interface.ArgType("range").elementType.className == "int" -%}
    std::uniform_int_distribution
{%- else -%}
    std::uniform_real_distribution
{%- endif -%}
    < {{ interface.ArgType("range").elementType.className }} > distribution(
        {{ interface.ArgName("range") }}.Min(),
        {{ interface.ArgName("range") }}.Max()
{%- if interface.ArgType("range").elementType.className == "int" -%}
        - {{ interface.ArgType("range").CppValue( 1 ) }}
{%- endif -%}
    );
    return distribution( generator );
}
{% endfor %}
{% endblock %}
