#include <catch2/catch.hpp>

#include <gm/types/{{ valueType.headerFileName }}>

#include <vector>

{% import "types/typeUtils.h" as typeUtils %}

TEST_CASE( "{{ valueType.className }}_DefaultConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    CHECK( {{ valueType.varName }}.Min() ==
{%- if valueType.elementType.isScalar -%}
           std::numeric_limits< {{ valueType.elementType.className }} >::max()
{%- elif valueType.elementType.isVector %}
           gm::{{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
        std::numeric_limits< {{ valueType.elementType.elementType.className }} >::max()
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
    CHECK( {{ valueType.varName }}.Max() ==
{%- if valueType.elementType.isScalar -%}
           std::numeric_limits< {{ valueType.elementType.className }} >::min()
{%- elif valueType.elementType.isVector %}
           gm::{{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
        std::numeric_limits< {{ valueType.elementType.elementType.className }} >::min()
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
}

TEST_CASE( "{{ valueType.className }}_MinMaxConstructor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }}(
        {{ typeUtils.GenUniformSequence( valueType.elementType, -1 ) }},
        {{ typeUtils.GenUniformSequence( valueType.elementType, 1 ) }}
    );
    CHECK( {{ valueType.varName }}.Min() == {{ typeUtils.GenUniformSequence( valueType.elementType, -1 ) }} );
    CHECK( {{ valueType.varName }}.Max() == {{ typeUtils.GenUniformSequence( valueType.elementType, 1 ) }} );
}

TEST_CASE( "{{ valueType.className }}_MinAccessor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    {{ valueType.varName }}.Min() = {{ typeUtils.GenUniformSequence( valueType.elementType, -1 ) }};
    CHECK( {{ valueType.varName }}.Min() == {{ typeUtils.GenUniformSequence( valueType.elementType, -1 ) }} );
}

TEST_CASE( "{{ valueType.className }}_MaxAccessor" )
{
    gm::{{ valueType.className }} {{ valueType.varName }};
    {{ valueType.varName }}.Max() = {{ typeUtils.GenUniformSequence( valueType.elementType, 1 ) }};
    CHECK( {{ valueType.varName }}.Max() == {{ typeUtils.GenUniformSequence( valueType.elementType, 1 ) }} );
}

TEST_CASE( "{{ valueType.className }}_EqualityComparison" )
{
    CHECK( {{ typeUtils.GenRange( valueType, 2, -2 ) }} == {{ typeUtils.GenRange( valueType, 2, -2 ) }} );
    CHECK( !( {{ typeUtils.GenRange( valueType, 2, -2 ) }} == {{ typeUtils.GenRange( valueType, -2, -2 ) }} ) );
}

TEST_CASE( "{{ valueType.className }}_InequalityComparison" )
{
    CHECK( {{ typeUtils.GenRange( valueType, 2, -2 ) }} != {{ typeUtils.GenRange( valueType, -2, -2 ) }} );
    CHECK( !( {{ typeUtils.GenRange( valueType, 2, -2 ) }} != {{ typeUtils.GenRange( valueType, 2, -2 ) }} ) );
}

TEST_CASE( "{{ valueType.className }}_IsEmpty" )
{
    CHECK( {{ typeUtils.GenRange( valueType, 2, -2 ) }}.IsEmpty() );
    CHECK( !{{ typeUtils.GenRange( valueType, -2, -2 ) }}.IsEmpty() );
    CHECK( !{{ typeUtils.GenRange( valueType, -2, 2 ) }}.IsEmpty() );
}

{% if valueType.elementType.isScalar and valueType.elementType.className == "int" %}
TEST_CASE( "{{ valueType.className }}_RangeIteration" )
{
    gm::{{ valueType.className }} range( {{ valueType.CppValue( -3 ) }}, {{ valueType.CppValue( 3 ) }} );
    std::vector< {{ valueType.elementType.namespacedClassName }} > array;
    for ( const {{ valueType.elementType.className }}& value : range )
    {
        array.push_back( value );
    }


    std::vector< {{ valueType.elementType.namespacedClassName }} > expectedArray = {
{% for index in range(-3, 3) -%}
        {{ valueType.CppValue( index ) }}
{%- if index + 1 < 3 -%}
        ,
{%- endif -%}
{%- endfor -%}
    };
    CHECK( array == expectedArray );
}
{% elif valueType.elementType.isVector and valueType.elementType.elementType.className == "int" %}
TEST_CASE( "{{ valueType.className }}_RangeIteration" )
{
    gm::{{ valueType.className }} range(
           gm::{{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
            {{ valueType.CppValue( -2 ) }}
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    ), gm::{{ valueType.elementType.className }}(
{% for index in range(valueType.elementType.elementSize) -%}
            {{ valueType.CppValue( 4 ) }}
{%- if index + 1 < valueType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
    );
    std::vector< {{ valueType.elementType.namespacedClassName }} > array;
    for ( const gm::{{ valueType.elementType.className }}& value : range )
    {
        array.push_back( value );
    }

    std::vector< {{ valueType.elementType.namespacedClassName }} > expectedArray = {
{% if valueType.elementType.elementSize == 2 -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ valueType.elementType.className }}(
            {{ valueType.CppValue( x ) }},
            {{ valueType.CppValue( y ) }}
        )
{%- if x != 4 - 1 or y != 4 - 1 -%}
        ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- elif valueType.elementType.elementSize == 3 -%}
{% for z in range(-2, 4) -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ valueType.elementType.className }}(
            {{ valueType.CppValue( x ) }},
            {{ valueType.CppValue( y ) }},
            {{ valueType.CppValue( z ) }}
        )
{%- if x != 4 - 1 or y != 4 - 1 or z != 4 -%}
        ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}
{%- elif valueType.elementType.elementSize == 4 -%}
{% for w in range(-2, 4) -%}
{% for z in range(-2, 4) -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ valueType.elementType.className }}(
            {{ valueType.CppValue( x ) }},
            {{ valueType.CppValue( y ) }},
            {{ valueType.CppValue( z ) }},
            {{ valueType.CppValue( w ) }}
        )
{%- if x != 4 - 1 or y != 4 - 1 or z != 4 or w != 4 -%}
        ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}
{%- endif -%}
    };
    CHECK( array == expectedArray );
}
{% endif %}
