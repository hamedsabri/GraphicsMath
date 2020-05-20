#include <pybind11/pybind11.h>

// Types
{% for type in types -%}
#include "bind{{ UpperCamelCase(type.headerFileName) }}"
{% endfor %}

PYBIND11_MODULE( gm, o_module )
{
    o_module.doc() = "GraphicsMath python module.";

    // Types
{% for type in types -%}
    Bind{{ type.className }}( o_module );
{%- endfor %}
}

