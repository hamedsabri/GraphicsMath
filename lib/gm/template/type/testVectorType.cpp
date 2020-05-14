#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/{{ context.headerFileName }}>

TEST_CASE( "{{ context.className }}_DefaultConstructor" )
{
    gm::{{ context.className }} {{ context.variablePrefix }};
    CHECK( {{ context.variablePrefix }} ==
    gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    0
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_CopyConstructor" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B( {{ context.variablePrefix }}A );
    CHECK( {{ context.variablePrefix }}A == {{ context.variablePrefix }}B );
}

TEST_CASE( "{{ context.className }}_CopyAssignmentConstructor" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B = {{ context.variablePrefix }}A;
    CHECK( {{ context.variablePrefix }}A == {{ context.variablePrefix }}B );
}

TEST_CASE( "{{ context.className }}_ElementReadAccess" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}[ {{ index }} ] == {{ index * 2 }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_ElementWriteAccess" )
{
    gm::{{ context.className }} {{ context.variablePrefix }};
{% for index in range(context.elementSize) -%}
    {{ context.variablePrefix }}[ {{ index }} ] = {{ index * 5 }};
{%- endfor %}
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}[ {{ index }} ] == {{ index * 5 }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_Addition" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ index * 5 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}C =
        {{ context.variablePrefix }}A + {{ context.variablePrefix }}B;
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}C[ {{ index }} ] == {{ index * 7 }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_Addition" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ index * 2 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ index * 5 }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}C =
        {{ context.variablePrefix }}A + {{ context.variablePrefix }}B;
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}C[ {{ index }} ] == {{ index * 7 }} );
{%- endfor %}
}
