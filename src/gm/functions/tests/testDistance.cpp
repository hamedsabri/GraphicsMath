#include <catch2/catch.hpp>

#include <gm/functions/distance.h>

TEST_CASE( "Distance_Vec2f" )
{
    gm::Vec2f pointA( 3.0f, 3.0f );
    gm::Vec2f pointB( 6.0f, 7.0f );
    CHECK( gm::Distance( pointA, pointB ) == Approx( 5.0f ) );
}

TEST_CASE( "Distance_Vec3f" )
{
    gm::Vec3f pointA( 3.0f, 3.0f, -5.0f );
    gm::Vec3f pointB( 6.0f, 7.0f, -5.0f );
    CHECK( gm::Distance( pointA, pointB ) == Approx( 5.0f ) );
}
