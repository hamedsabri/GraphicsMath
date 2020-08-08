#include <catch2/catch.hpp>

#include <gm/types/{{ valueType.headerFileName }}>

{% import "types/typeUtils.h" as typeUtils %}

TEST_CASE( "{{ valueType.className }}_DefaultConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    CHECK( {{ valueType.varName }} == {{- typeUtils.GenUniformSequence( valueType, 0 ) -}} );
}

TEST_CASE( "{{ valueType.className }}_CopyConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B( {{ valueType.varName }}A );
    CHECK( {{ valueType.varName }}A == {{ valueType.varName }}B );
}

TEST_CASE( "{{ valueType.className }}_CopyAssignmentConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}A == {{ valueType.varName }}B );
}

TEST_CASE( "{{ valueType.className }}_ElementReadAccess" )
{
    gm::{{ valueType.className }} {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
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

{% if valueType.shape|length == 2 -%}
TEST_CASE( "{{ valueType.className }}_MatrixElementReadAccess" )
{
    gm::{{ valueType.className }} {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 1) -}};
{% for row in range(valueType.shape[1]) -%}
{% for col in range(valueType.shape[0]) -%}
    CHECK( {{ valueType.varName }}( {{ row }}, {{ col }} ) == {{ valueType.CppValue(row * valueType.shape[1] + col) }} );
{%- endfor %}
{%- endfor %}
}

TEST_CASE( "{{ valueType.className }}_MatrixElementWriteAccess" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
{% for row in range(valueType.shape[1]) -%}
{% for col in range(valueType.shape[0]) -%}
    {{ valueType.varName }}( {{ row }}, {{ col }} ) = {{ valueType.CppValue(row * valueType.shape[1] + col) }};
{%- endfor %}
{%- endfor %}
    CHECK( {{ valueType.varName }} == {{- typeUtils.GenArithmeticSequence( valueType, 1 ) -}});
}

TEST_CASE( "{{ valueType.className }}_Identity" )
{
    gm::{{ valueType.className }} {{ valueType.varName }} = gm::{{ valueType.className }}::Identity();

    CHECK( {{ valueType.varName }} == gm::{{ valueType.className }}(
{% for row in range(valueType.shape[0]) -%}
{% for col in range(valueType.shape[1]) -%}
{% if row == col -%}
    {{ valueType.CppValue( 1 ) }}
{%- else -%}
    {{ valueType.CppValue( 0 ) }}
{%- endif %}
{% if row + 1 < valueType.shape[0] or col + 1 < valueType.shape[ 1 ] -%}
    ,
{%- endif %}
{%- endfor -%}
{%- endfor -%}
        )
    );
}

{%- endif %}

{% for namedElement in valueType.namedElements %}
TEST_CASE( "{{ valueType.className }}_NamedElementReadAccessor{{ namedElement.accessorName }}" )
{
    gm::{{ valueType.className }} {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 1) -}};
    CHECK( {{ valueType.varName }}.{{ namedElement.accessorName }}() == {{ valueType.CppValue( loop.index0 ) }} );
}

TEST_CASE( "{{ valueType.className }}_NamedElementWriteAccessor{{ namedElement.accessorName }}" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    {{ valueType.varName }}.{{ namedElement.accessorName }}() = {{ valueType.CppValue( loop.index0 ) }};
    CHECK( {{ valueType.varName }}[ {{ loop.index0 }} ] == {{ valueType.CppValue( loop.index0 ) }} );
}
{%- endfor %}

TEST_CASE( "{{ valueType.className }}_Addition" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{- typeUtils.GenArithmeticSequence(valueType, 5) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}C = {{ valueType.varName }}A + {{ valueType.varName }}B;
    CHECK( {{ valueType.varName }}C == {{- typeUtils.GenArithmeticSequence( valueType, 7 ) -}});
}

TEST_CASE( "{{ valueType.className }}_AdditionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{- typeUtils.GenArithmeticSequence(valueType, 5) -}};
    {{ valueType.varName }}B += {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == {{- typeUtils.GenArithmeticSequence( valueType, 7 ) -}});
}

TEST_CASE( "{{ valueType.className }}_Subtraction" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 7) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{- typeUtils.GenArithmeticSequence(valueType, 5) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}C = {{ valueType.varName }}A - {{ valueType.varName }}B;
    CHECK( {{ valueType.varName }}C == {{- typeUtils.GenArithmeticSequence( valueType, 2 ) -}});
}

TEST_CASE( "{{ valueType.className }}_SubtractionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 5) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{- typeUtils.GenArithmeticSequence(valueType, 7) -}};
    {{ valueType.varName }}B -= {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == {{- typeUtils.GenArithmeticSequence( valueType, 2 ) -}});
}

TEST_CASE( "{{ valueType.className }}_ScalarVectorMultiplication" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{ valueType.CppValue(5) }} * {{ valueType.varName }}A;
    CHECK( {{ valueType.varName }}B == {{- typeUtils.GenArithmeticSequence( valueType, 10 ) -}});
}

TEST_CASE( "{{ valueType.className }}_VectorScalarMultiplication" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{ valueType.varName }}A * {{ valueType.CppValue(5) }};
    CHECK( {{ valueType.varName }}B == {{- typeUtils.GenArithmeticSequence( valueType, 10 ) -}});
}

TEST_CASE( "{{ valueType.className }}_ScalarMultiplicationAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    {{ valueType.varName }}A *= 5;
    CHECK( {{ valueType.varName }}A == {{- typeUtils.GenArithmeticSequence( valueType, 10 ) -}});
}

TEST_CASE( "{{ valueType.className }}_VectorScalarDivision" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 10) -}};
    gm::{{ valueType.className }} {{ valueType.varName }}B = {{ valueType.varName }}A / {{ valueType.CppValue(5) }};
    CHECK( {{ valueType.varName }}B == {{- typeUtils.GenArithmeticSequence( valueType, 2 ) -}});
}

TEST_CASE( "{{ valueType.className }}_ScalarDivisionAssignment" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}A = {{- typeUtils.GenArithmeticSequence(valueType, 10) -}};
    {{ valueType.varName }}A /= 5;
    CHECK( {{ valueType.varName }}A == {{- typeUtils.GenArithmeticSequence( valueType, 2 ) -}});
}

TEST_CASE( "{{ valueType.className }}_Negation" )
{
    gm::{{ valueType.className }} {{ valueType.varName }} = {{- typeUtils.GenArithmeticSequence(valueType, 2) -}};
    CHECK( -{{ valueType.varName }} == {{- typeUtils.GenArithmeticSequence(valueType, -2) -}} );
}

