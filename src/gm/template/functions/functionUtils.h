{# Common, utility macros used for rendering code in functions.  #}

{# Generate the signature of a function interface.  #}
{% macro signature(function, interface) %}
GM_HOST_DEVICE inline
{% if interface.returnType -%}
{{ interface.returnType.className }}
{%- else -%}
void
{%- endif %}
{{ function.name }}( {{ interface.typedArgs }} )
{% endmacro %}

{# Generating the includes for the value type(s) defined by a function's interface(s). #}
{% macro typeIncludes(function) %}
{% for type in function.types -%}
{%- if not type.isScalar -%}
#include <gm/types/{{ type.headerFileName }}>
{% endif -%}
{%- endfor %}
{% endmacro %}
