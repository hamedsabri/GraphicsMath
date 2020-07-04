#include <catch2/catch.hpp>

#include <gm/types/{{ rangeType.headerFileName }}>
#include <gm/types/{{ rangeType.headerFileName.replace("Range", "Array") }}>

TEST_CASE( "{{ rangeType.className }}_DefaultConstructor" )
{
    gm::{{ rangeType.className }} {{ rangeType.varName }};
    CHECK( {{ rangeType.varName }}.Min() ==
{%- if rangeType.elementType.isScalar -%}
           std::numeric_limits< {{ rangeType.elementType.className }} >::max()
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
        std::numeric_limits< {{ rangeType.elementType.elementType.className }} >::max()
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
    CHECK( {{ rangeType.varName }}.Max() ==
{%- if rangeType.elementType.isScalar -%}
           std::numeric_limits< {{ rangeType.elementType.className }} >::min()
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
        std::numeric_limits< {{ rangeType.elementType.elementType.className }} >::min()
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
}

TEST_CASE( "{{ rangeType.className }}_MinMaxConstructor" )
{
    gm::{{ rangeType.className }} {{ rangeType.varName }}(
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( -1 ) }},
            {{ rangeType.CppValue( 1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( -1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    ), gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( 1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
    CHECK( {{ rangeType.varName }}.Min() ==
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( -1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( -1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
    CHECK( {{ rangeType.varName }}.Max() ==
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( 1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( 1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
}

TEST_CASE( "{{ rangeType.className }}_MinAccessor" )
{
    gm::{{ rangeType.className }} {{ rangeType.varName }};
    {{ rangeType.varName }}.Min() =
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( -1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( -1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    ;
    CHECK( {{ rangeType.varName }}.Min() ==
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( -1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( -1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
}

TEST_CASE( "{{ rangeType.className }}_MaxAccessor" )
{
    gm::{{ rangeType.className }} {{ rangeType.varName }};
    {{ rangeType.varName }}.Max() =
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( 1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( 1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    ;
    CHECK( {{ rangeType.varName }}.Max() ==
{%- if rangeType.elementType.isScalar -%}
            {{ rangeType.CppValue( 1 ) }}
{%- elif rangeType.elementType.isVector %}
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( 1 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
{%- endif -%}
    );
}

{% if rangeType.elementType.isScalar and rangeType.elementType.className == "int" %}
TEST_CASE( "{{ rangeType.className }}_RangeIteration" )
{
    gm::{{ rangeType.className }} range( {{ rangeType.CppValue( -3 ) }}, {{ rangeType.CppValue( 3 ) }} );
    gm::{{ rangeType.className.replace("Range", "Array") }} array;
    for ( const {{ rangeType.elementType.className }}& value : range )
    {
        array.push_back( value );
    }

    gm::{{ rangeType.className.replace("Range", "Array") }} expectedArray = {
{% for index in range(-3, 3) -%}
        {{ rangeType.CppValue( index ) }}
{%- if index + 1 < 3 -%}
        ,
{%- endif -%}
{%- endfor -%}
    };
    CHECK( array == expectedArray );
}
{% elif rangeType.elementType.isVector and rangeType.elementType.elementType.className == "int" %}
TEST_CASE( "{{ rangeType.className }}_RangeIteration" )
{
    gm::{{ rangeType.className }} range(
           gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( -2 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    ), gm::{{ rangeType.elementType.className }}(
{% for index in range(rangeType.elementType.elementSize) -%}
            {{ rangeType.CppValue( 4 ) }}
{%- if index + 1 < rangeType.elementType.elementSize -%}
        ,
{%- endif -%}
{%- endfor -%}
    )
    );
    gm::{{ rangeType.className.replace("Range", "Array") }} array;
    for ( const gm::{{ rangeType.elementType.className }}& value : range )
    {
        array.push_back( value );
    }

    gm::{{ rangeType.className.replace("Range", "Array") }} expectedArray = {
{% if rangeType.elementType.elementSize == 2 -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ rangeType.elementType.className }}(
            {{ rangeType.CppValue( x ) }},
            {{ rangeType.CppValue( y ) }}
        )
{%- if x != 4 - 1 or y != 4 - 1 -%}
        ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- elif rangeType.elementType.elementSize == 3 -%}
{% for z in range(-2, 4) -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ rangeType.elementType.className }}(
            {{ rangeType.CppValue( x ) }},
            {{ rangeType.CppValue( y ) }},
            {{ rangeType.CppValue( z ) }}
        )
{%- if x != 4 - 1 or y != 4 - 1 or z != 4 -%}
        ,
{%- endif -%}
{%- endfor -%}
{%- endfor -%}
{%- endfor -%}
{%- elif rangeType.elementType.elementSize == 4 -%}
{% for w in range(-2, 4) -%}
{% for z in range(-2, 4) -%}
{% for y in range(-2, 4) -%}
{% for x in range(-2, 4) -%}
        gm::{{ rangeType.elementType.className }}(
            {{ rangeType.CppValue( x ) }},
            {{ rangeType.CppValue( y ) }},
            {{ rangeType.CppValue( z ) }},
            {{ rangeType.CppValue( w ) }}
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
