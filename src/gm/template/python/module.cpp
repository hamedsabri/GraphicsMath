#include <pybind11/pybind11.h>

// Type Declarations.
{% for type in types -%}
void Bind{{ type.className }}( pybind11::module& );
{% endfor %}

// Function Declarations.
{% for function in functions -%}
void Bind{{ function.name }}( pybind11::module& );
{% endfor %}

PYBIND11_MODULE( gm, o_module )
{
    o_module.doc() = "GraphicsMath python module.";

    // Types.
{% for type in types -%}
    Bind{{ type.className }}( o_module );
{%- endfor %}

    // Functions.
{% for function in functions -%}
    Bind{{ function.name }}( o_module );
{%- endfor %}
}

