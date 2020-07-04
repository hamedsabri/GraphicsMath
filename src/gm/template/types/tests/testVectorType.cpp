#include <catch2/catch.hpp>

#include <gm/types/{{ valueType.headerFileName }}>

TEST_CASE( "{{ valueType.className }}_DefaultConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    CHECK( {{ valueType.varName }} ==
    gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(0) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_CopyConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B( {{ valueType.varName }}A );
    CHECK( {{ valueType.varName }}A == {{ valueType.varName }}B );
}

TEST_CASE( "{{ valueType.className }}_CopyAssignmentConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}A == {{ valueType.varName }}B );
}

TEST_CASE( "{{ valueType.className }}_ElementReadAccess" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{% for index in range(valueType.elementSize) -%}
    CHECK( {{ valueType.varName }}[ {{ index }} ] == {{ valueType.CppValue(index * 2) }} );
{%- endfor %}
}

TEST_CASE( "{{ valueType.className }}_ElementWriteAccess" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
{% for index in range(valueType.elementSize) -%}
    {{ valueType.varName }}[ {{ index }} ] = {{ valueType.CppValue(index * 5) }};
{%- endfor %}
{% for index in range(valueType.elementSize) -%}
    CHECK( {{ valueType.varName }}[ {{ index }} ] == {{ valueType.CppValue(index * 5) }} );
{%- endfor %}
}

TEST_CASE( "{{ valueType.className }}_Addition" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 5) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}C =
        {{ valueType.varName }}A + {{ valueType.varName }}B;
    CHECK( {{ valueType.varName }}C == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 7) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_AdditionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 5) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ valueType.varName }}B += {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 7) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_Subtraction" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 7) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 5) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}C =
        {{ valueType.varName }}A - {{ valueType.varName }}B;
    CHECK( {{ valueType.varName }}C == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_SubtractionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 5) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 7) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ valueType.varName }}B -= {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_ScalarVectorMultiplication" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );

    gm::{{ valueType.className }} {{ valueType.varName }}B =
        5 * {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 10) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_VectorScalarMultiplication" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B =
        {{ valueType.varName }}A * {{ valueType.CppValue(5) }};
    CHECK( {{ valueType.varName }}B == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 10) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_ScalarMultiplicationAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ valueType.varName }}A *= 5;
    CHECK( {{ valueType.varName }}A == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 10) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_VectorScalarDivision" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 10) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    gm::{{ valueType.className }} {{ valueType.varName }}B =
        {{ valueType.varName }}A / {{ valueType.CppValue(5) }};
    CHECK( {{ valueType.varName }}B == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_ScalarDivisionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 10) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    {{ valueType.varName }}A /= {{ valueType.CppValue(5) }};
    CHECK( {{ valueType.varName }}A == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

TEST_CASE( "{{ valueType.className }}_Negation" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}(
{% for index in range(valueType.elementSize) -%}
    {{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
    CHECK( -{{ valueType.varName }} == gm::{{ valueType.className }}(
{% for index in range(valueType.elementSize) -%}
    -{{ valueType.CppValue(index * 2) }}
{%- if index + 1 < valueType.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    ) );
}

