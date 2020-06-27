#include <catch2/catch.hpp>

#include <gm/functions/rayPosition.h>

TEST_CASE( "RayPosition_Vec2f" )
{
    gm::Vec2f origin( 0.0f, 2.0f );
    gm::Vec2f direction( 0.0f, 1.0f );
    gm::Vec2f rayPos = gm::RayPosition( origin, direction, 5.0 );
    CHECK( rayPos[ 0 ] == Approx( 0.0f ) );
    CHECK( rayPos[ 1 ] == Approx( 7.0f ) );
}

TEST_CASE( "RayPosition_Vec3f" )
{
    gm::Vec3f origin( 0.0f, 2.0f, 4.0f );
    gm::Vec3f direction( 0.0f, 1.0f, 0.0f );
    gm::Vec3f rayPos = gm::RayPosition( origin, direction, 5.0f );
    CHECK( rayPos[ 0 ] == Approx( 0.0f ) );
    CHECK( rayPos[ 1 ] == Approx( 7.0f ) );
    CHECK( rayPos[ 2 ] == Approx( 4.0f ) );
}
