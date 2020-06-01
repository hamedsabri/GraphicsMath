#include <catch2/catch.hpp>

#include <gm/types/{{ vectorType.headerFileName }}>

TEST_CASE( "{{ vectorType.className }}_DefaultConstructor" )
{
    gm::{{ vectorType.className }} {{ vectorType.varName }};
    CHECK( {{ vectorType.varName }} ==
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B( {{ vectorType.varName }}A );
    CHECK( {{ vectorType.varName }}A == {{ vectorType.varName }}B );
}

TEST_CASE( "{{ vectorType.className }}_CopyAssignmentConstructor" )
{
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B = {{ vectorType.varName }}A;
    CHECK( {{ vectorType.varName }}A == {{ vectorType.varName }}B );
}

TEST_CASE( "{{ vectorType.className }}_ElementReadAccess" )
{
    gm::{{ vectorType.className }} {{ vectorType.varName }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% for index in range(vectorType.elementSize) -%}
    CHECK( {{ vectorType.varName }}[ {{ index }} ] == {{ vectorType.CppNumber(index * 2) }} );
{%- endfor %}
}

TEST_CASE( "{{ vectorType.className }}_ElementWriteAccess" )
{
    gm::{{ vectorType.className }} {{ vectorType.varName }};
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.varName }}[ {{ index }} ] = {{ vectorType.CppNumber(index * 5) }};
{%- endfor %}
{% for index in range(vectorType.elementSize) -%}
    CHECK( {{ vectorType.varName }}[ {{ index }} ] == {{ vectorType.CppNumber(index * 5) }} );
{%- endfor %}
}

TEST_CASE( "{{ vectorType.className }}_Addition" )
{
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}C =
        {{ vectorType.varName }}A + {{ vectorType.varName }}B;
    CHECK( {{ vectorType.varName }}C == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.varName }}B += {{ vectorType.varName }}A;
    CHECK( {{ vectorType.varName }}B == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}C =
        {{ vectorType.varName }}A - {{ vectorType.varName }}B;
    CHECK( {{ vectorType.varName }}C == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 5) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 7) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.varName }}B -= {{ vectorType.varName }}A;
    CHECK( {{ vectorType.varName }}B == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );

    gm::{{ vectorType.className }} {{ vectorType.varName }}B =
        5 * {{ vectorType.varName }}A;
    CHECK( {{ vectorType.varName }}B == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B =
        {{ vectorType.varName }}A * {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.varName }}B == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.varName }}A *= 5;
    CHECK( {{ vectorType.varName }}A == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ vectorType.className }} {{ vectorType.varName }}B =
        {{ vectorType.varName }}A / {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.varName }}B == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}A(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 10) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ vectorType.varName }}A /= {{ vectorType.CppNumber(5) }};
    CHECK( {{ vectorType.varName }}A == gm::{{ vectorType.className }}(
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
    gm::{{ vectorType.className }} {{ vectorType.varName }}(
{% for index in range(vectorType.elementSize) -%}
    {{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( -{{ vectorType.varName }} == gm::{{ vectorType.className }}(
{% for index in range(vectorType.elementSize) -%}
    -{{ vectorType.CppNumber(index * 2) }}
{%- if index + 1 < vectorType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

