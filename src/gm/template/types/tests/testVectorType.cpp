#include <catch2/catch.hpp>

#include <gm/types/{{ vectorType.headerFileName }}>

TEST_CASE( "{{ vectorType.className }}_DefaultConstructor" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }};
    CHECK( {{ vectorType.variablePrefix }} ==
    gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(0) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_CopyConstructor" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B( {{ vectorType.variablePrefix }}A );
    CHECK( {{ vectorType.variablePrefix }}A == {{ vectorType.variablePrefix }}B );
}

TEST_CASE( "{{ vectorType.className }}_CopyAssignmentConstructor" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B = {{ vectorType.variablePrefix }}A;
    CHECK( {{ vectorType.variablePrefix }}A == {{ vectorType.variablePrefix }}B );
}

TEST_CASE( "{{ vectorType.className }}_ElementReadAccess" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% for index in range(vectorType.elementSize) -%}
    CHECK( {{ vectorType.variablePrefix }}[ {{ index }} ] == {{ vectorType.CppNumber(index * 2) }} );
{%- endfor %}
}

TEST_CASE( "{{ vectorType.className }}_ElementWriteAccess" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }};
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.variablePrefix }}[ {{ index }} ] = {{ vectorType.CppNumber(index * 5) }};
{%- endfor %}
{% for index in range(vectorType.elementSize) -%}
    CHECK( {{ vectorType.variablePrefix }}[ {{ index }} ] == {{ vectorType.CppNumber(index * 5) }} );
{%- endfor %}
}

TEST_CASE( "{{ vectorType.className }}_Addition" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}C =
        {{ vectorType.variablePrefix }}A + {{ vectorType.variablePrefix }}B;
    CHECK( {{ vectorType.variablePrefix }}C == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_AdditionAssignment" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.variablePrefix }}B += {{ vectorType.variablePrefix }}A;
    CHECK( {{ vectorType.variablePrefix }}B == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_Subtraction" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}C =
        {{ vectorType.variablePrefix }}A - {{ vectorType.variablePrefix }}B;
    CHECK( {{ vectorType.variablePrefix }}C == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_SubtractionAssignment" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.variablePrefix }}B -= {{ vectorType.variablePrefix }}A;
    CHECK( {{ vectorType.variablePrefix }}B == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_ScalarVectorMultiplication" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );

    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B =
        5 * {{ vectorType.variablePrefix }}A;
    CHECK( {{ vectorType.variablePrefix }}B == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_VectorScalarMultiplication" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B =
        {{ vectorType.variablePrefix }}A * {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.variablePrefix }}B == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_ScalarMultiplicationAssignment" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.variablePrefix }}A *= 5;
    CHECK( {{ vectorType.variablePrefix }}A == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_VectorScalarDivision" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}B =
        {{ vectorType.variablePrefix }}A / {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.variablePrefix }}B == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_ScalarDivisionAssignment" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.variablePrefix }}A /= {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.variablePrefix }}A == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ vectorType.className }}_Negation" )
{
    gm::{{ vectorType.className }} {{ vectorType.variablePrefix }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( -{{ vectorType.variablePrefix }} == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    -{{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

