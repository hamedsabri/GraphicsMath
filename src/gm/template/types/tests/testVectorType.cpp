#include <catch2/catch.hpp>

#include <gm/types/{{ context.headerFileName }}>

TEST_CASE( "{{ context.className }}_DefaultConstructor" )
{
    gm::{{ context.className }} {{ context.variablePrefix }};
    CHECK( {{ context.variablePrefix }} ==
    gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(0) }}
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
    {{ context.GetCppNumber(index * 2) }}
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
    {{ context.GetCppNumber(index * 2) }}
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
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}[ {{ index }} ] == {{ context.GetCppNumber(index * 2) }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_ElementWriteAccess" )
{
    gm::{{ context.className }} {{ context.variablePrefix }};
{% for index in range(context.elementSize) -%}
    {{ context.variablePrefix }}[ {{ index }} ] = {{ context.GetCppNumber(index * 5) }};
{%- endfor %}
{% for index in range(context.elementSize) -%}
    CHECK( {{ context.variablePrefix }}[ {{ index }} ] == {{ context.GetCppNumber(index * 5) }} );
{%- endfor %}
}

TEST_CASE( "{{ context.className }}_Addition" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 5) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}C =
        {{ context.variablePrefix }}A + {{ context.variablePrefix }}B;
    CHECK( {{ context.variablePrefix }}C == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 7) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_AdditionAssignment" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 5) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ context.variablePrefix }}B += {{ context.variablePrefix }}A;
    CHECK( {{ context.variablePrefix }}B == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 7) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_Subtraction" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 7) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 5) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}C =
        {{ context.variablePrefix }}A - {{ context.variablePrefix }}B;
    CHECK( {{ context.variablePrefix }}C == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_SubtractionAssignment" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 5) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 7) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ context.variablePrefix }}B -= {{ context.variablePrefix }}A;
    CHECK( {{ context.variablePrefix }}B == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_ScalarVectorMultiplication" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );

    gm::{{ context.className }} {{ context.variablePrefix }}B =
        5 * {{ context.variablePrefix }}A;
    CHECK( {{ context.variablePrefix }}B == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 10) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_VectorScalarMultiplication" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B =
        {{ context.variablePrefix }}A * {{ context.GetCppNumber(5) }};
    CHECK( {{ context.variablePrefix }}B == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 10) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_ScalarMultiplicationAssignment" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ context.variablePrefix }}A *= 5;
    CHECK( {{ context.variablePrefix }}A == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 10) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_VectorScalarDivision" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 10) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ context.className }} {{ context.variablePrefix }}B =
        {{ context.variablePrefix }}A / {{ context.GetCppNumber(5) }};
    CHECK( {{ context.variablePrefix }}B == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_ScalarDivisionAssignment" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}A(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 10) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ context.variablePrefix }}A /= {{ context.GetCppNumber(5) }};
    CHECK( {{ context.variablePrefix }}A == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ context.className }}_Negation" )
{
    gm::{{ context.className }} {{ context.variablePrefix }}(
{% for index in range(context.elementSize) -%}
    {{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( -{{ context.variablePrefix }} == gm::{{ context.className }}(
{% for index in range(context.elementSize) -%}
    -{{ context.GetCppNumber(index * 2) }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

