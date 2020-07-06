#include <catch2/catch.hpp>

#include <gm/types/{{ valueType.headerFileName }}>

TEST_CASE( "{{ valueType.className }}_DefaultConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
{% for element in valueType.elements -%}
    CHECK( {{ valueType.varName }}.{{ element.accessorName }}() ==
{%- if not element.type.isScalar -%}
        gm::
{%- endif -%}
           {{ element.type.className }}() );
{%- endfor %}
}
