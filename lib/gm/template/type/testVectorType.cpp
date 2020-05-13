#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/{{ context.headerFileName }}>

TEST_CASE( "{{ context.className }}_ElementReadAccess" )
{
    gm::{{ context.className }} vector(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );

{% for index in range(context.elementSize) -%}
    CHECK( vector[ {{ index }} ] == {{ index * 2 }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_ElementWriteAccess" )
{
    gm::{{ context.className }} vector;
{% for index in range(context.elementSize) -%}
    vector[ {{ index }} ] = {{ index * 5 }};
{%- endfor %}

{% for index in range(context.elementSize) -%}
    CHECK( vector[ {{ index }} ] == {{ index * 5 }} );
{%- endfor %}
}
