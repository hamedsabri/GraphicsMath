//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/degrees.h>

TEST_CASE( "Degrees_float" )
{
    float floatVal        = 2.15f;
    float floatValDegrees = gm::Degrees( floatVal );
    CHECK( floatValDegrees == Approx( 123.185925953f ) );
}
