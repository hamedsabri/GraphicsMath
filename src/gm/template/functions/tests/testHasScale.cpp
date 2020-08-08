#include <catch2/catch.hpp>

#include <gm/functions/setScale.h>
#include <gm/functions/hasScale.h>

{% import "types/typeUtils.h" as typeUtils %}

{% for interface in function.interfaces %}
{% set matrixType = interface.ArgType("matrix") %}
{% set vectorType = VectorType((matrixType.shape[0] - 1,), ScalarType(FLOAT)) %}
TEST_CASE( "{{ function.name }}_{{ matrixType.className }}" )
{
    gm::{{ matrixType.className }} matrix = gm::{{ matrixType.className }}::Identity();

    gm::SetScale( {{ typeUtils.GenUniformSequence( vectorType, 1 ) }}, matrix );
    CHECK( !gm::{{ function.name }}( matrix ) );

    gm::SetScale( {{ typeUtils.GenUniformSequence( vectorType, 2 ) }}, matrix );
    CHECK( gm::{{ function.name }}( matrix ) );

    gm::SetScale( {{ typeUtils.GenArithmeticSequence( vectorType, 3 ) }}, matrix );
    CHECK( gm::{{ function.name }}( matrix ) );
}
{% endfor %}
