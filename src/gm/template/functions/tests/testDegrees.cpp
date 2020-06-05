#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("angle") }}" )
{
    {{ interface.ArgClass("angle") }} {{ interface.ArgType("angle").varName }} =
        {{ interface.Arg("angle").type.CppValue(2.15) }};
    {{ interface.ArgClass("angle") }} {{ interface.ArgType("angle").varName }}Degrees =
        gm::{{ function.name }}( {{ interface.ArgType("angle").varName }} );
    CHECK( {{ interface.ArgType("angle").varName }}Degrees
           == Approx( {{ interface.Arg("angle").type.CppValue( math.degrees(2.15) ) }} ));
}
{% endfor %}
