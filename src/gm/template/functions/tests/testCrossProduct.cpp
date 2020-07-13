#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
{% set vectorType            = interface.ArgType("lhs") %}
{% set namespacedVectorClass = vectorType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("lhs") }}" )
{
    {{ namespacedVectorClass }} {{ vectorType.varName }}A( 1.0, 0.5, 2.0 );
    {{ namespacedVectorClass }} {{ vectorType.varName }}B( 2.0, 5.0, 2.5 );
    {{ namespacedVectorClass }} res = gm::CrossProduct( {{ vectorType.varName }}A, {{ vectorType.varName }}B );
    CHECK( res.X() == Approx( -8.75f ) );
    CHECK( res.Y() == Approx( 1.5f ) );
    CHECK( res.Z() == Approx( 4.0f ) );
}
{% endfor %}
