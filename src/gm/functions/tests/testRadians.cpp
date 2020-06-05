//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/radians.h>

TEST_CASE( "Radians_float" )
{
    float floatVal        = 95.0f;
    float floatValRadians = gm::Radians( floatVal );
    CHECK( floatValRadians == Approx( 1.65806278939f ) );
}
