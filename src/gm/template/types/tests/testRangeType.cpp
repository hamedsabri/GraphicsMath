#include <catch2/catch.hpp>

#include <gm/types/{{ rangeType.headerFileName }}>

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
