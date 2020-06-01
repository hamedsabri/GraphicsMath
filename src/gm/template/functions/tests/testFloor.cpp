#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ParamCls("value") }}" )
{
{%- if interface.Param("value").type.isScalar -%}
    {{ interface.ParamCls("value") }} {{ interface.ParamVar("value") }} =
        {{ interface.Param("value").type.CppNumber(2.333) }};
{%- elif interface.Param("value").type.isVector -%}
    gm::{{ interface.ParamCls("value") }} {{ interface.ParamVar("value") }}(
{% for index in range(interface.Param("value").type.elementSize) -%}
    {{ interface.Param("value").type.CppNumber(index * 2.333) }}
{%- if index + 1 < interface.Param("value").type.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    );
{%- endif %}

{%- if not interface.Param("value").type.isScalar -%}
    gm::
{%- endif -%}
    {{ interface.ParamCls("value") }} {{ interface.ParamVar("value") }}Floored =
        gm::{{ function.name }}( {{ interface.ParamVar("value") }} );

{%- if interface.Param("value").type.isScalar -%}
    CHECK( {{ interface.ParamVar("value") }}Floored
           == Approx( {{ interface.Param("value").type.CppNumber( math.floor(2.333) ) }} ));
{%- elif interface.Param("value").type.isVector -%}
{% for index in range(interface.Param("value").type.elementSize) -%}
    CHECK( {{ interface.ParamVar("value") }}Floored[ {{ index }} ]
           == Approx( {{ interface.Param("value").type.CppNumber( math.floor(index * 2.333) ) }} ));
{%- endfor %}
{%- endif %}
}
{% endfor %}
