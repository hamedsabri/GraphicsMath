//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/randomNumber.h>

TEST_CASE( "RandomNumber_float" )
{
    gm::FloatRange range( -10.0f, 10.0f );
    float          floatVal = gm::RandomNumber( range );
    CHECK( floatVal >= range.Min() );
    CHECK( floatVal < range.Max() );
}

TEST_CASE( "RandomNumber_int" )
{
    gm::IntRange range( -10, 10 );
    int          intVal = gm::RandomNumber( range );
    CHECK( intVal >= range.Min() );
    CHECK( intVal < range.Max() );
}
