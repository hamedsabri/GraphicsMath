#include <pybind11/pybind11.h>

#include <gm/functions/{{ function.headerFileName }}>

// Python bindings for {{ function.name }}.

GM_NS_USING

void Bind{{ function.name }}( pybind11::module& o_module )
{
    {% for signature in function.signatures -%}
    o_module.def( "{{ function.name }}",
        []( {{ signature.cppTypedParameters }} )
        {
            return {{ function.name }}( {{ signature.parameterNames }} );
        }
    );
    {% endfor %}
}
