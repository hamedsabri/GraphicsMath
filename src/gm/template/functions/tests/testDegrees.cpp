#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
{% set angleType  = interface.ArgType("angle") %}
{% set angleClass = interface.ArgClass("angle") %}
TEST_CASE( "{{ function.name }}_{{ angleClass }}" )
{
    {{ angleClass }} {{ angleType.varName }} = {{ angleType.CppValue(2.15) }};
    {{ angleClass }} {{ angleType.varName }}Degrees = gm::{{ function.name }}( {{ angleType.varName }} );
    CHECK( {{ angleType.varName }}Degrees == Approx( {{ angleType.CppValue( math.degrees(2.15) ) }} ));
}
{% endfor %}
