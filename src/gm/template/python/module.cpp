#include <pybind11/pybind11.h>

// Type Declarations.
{% for type in types -%}
void Bind{{ type.className }}( pybind11::module& );
{% endfor %}

PYBIND11_MODULE( gm, o_module )
{
    o_module.doc() = "GraphicsMath python module.";

    // Types
{% for type in types -%}
    Bind{{ type.className }}( o_module );
{%- endfor %}
}

