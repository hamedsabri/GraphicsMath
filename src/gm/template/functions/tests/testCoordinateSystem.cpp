#include <catch2/catch.hpp>

#include <gm/functions/{{ function.headerFileName }}>

{% for interface in function.interfaces %}
{% set vectorType            = interface.ArgType("vectorA") %}
{% set namespacedVectorClass = vectorType.namespacedClassName %}
TEST_CASE( "{{ function.name }}_{{ interface.ArgClass("vectorA") }}" )
{
    {{ namespacedVectorClass }} vectorA( 1.0, 0.0, 0.0 );
    {{ namespacedVectorClass }} vectorB, vectorC;
    gm::CoordinateSystem( vectorA, vectorB, vectorC );
    CHECK( vectorB == {{ namespacedVectorClass }}( 0.0, 0.0, 1.0 ) );
    CHECK( vectorC == {{ namespacedVectorClass }}( 0.0, -1.0, 0.0 ) );
}
{% endfor %}
