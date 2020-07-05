#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.returnType.className }}" )
{
    gm::{{ interface.ArgClass("range") }} {{ interface.ArgType("range").varName }}(
        {{ interface.ArgType("range").CppValue(-10) }},
        {{ interface.ArgType("range").CppValue(10) }}
    );
    {{ interface.returnType.className }} {{ interface.returnType.varName }} =
        gm::RandomNumber( {{ interface.ArgType("range").varName }} );
    CHECK( {{ interface.returnType.varName }} >=
           {{ interface.ArgType("range").varName }}.Min() );
    CHECK( {{ interface.returnType.varName }} <
           {{ interface.ArgType("range").varName }}.Max() );
}
{% endfor %}
