#include <catch2/catch.hpp>

#include <gm/functions/length.h>

// This test is auto-generated! Please do not modify directly

TEST_CASE( "Length_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 2.0f );
    CHECK( gm::Length( vector ) == Approx( 2.0f ) );
}

TEST_CASE( "Length_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 2.0f, 4.0f );
    CHECK( gm::Length( vector ) == Approx( 4.472135955f ) );
}

TEST_CASE( "Length_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 2.0f, 4.0f, 6.0f );
    CHECK( gm::Length( vector ) == Approx( 7.48331477355f ) );
}
