#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgType("lhs").varName }}A( 1.0, 0.5, 2.0 );
    gm::{{ interface.ArgClass("lhs") }} {{ interface.ArgType("lhs").varName }}B( 2.0, 5.0, 2.5 );
    gm::{{ interface.ArgClass("lhs") }} res =
        gm::CrossProduct( {{ interface.ArgType("lhs").varName }}A, {{ interface.ArgType("rhs").varName }}B );
    CHECK( res.X() == Approx( -8.75f ) );
    CHECK( res.Y() == Approx( 1.5f ) );
    CHECK( res.Z() == Approx( 4.0f ) );
}
{% endfor %}
