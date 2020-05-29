#include <catch2/catch.hpp>

#include <gm/functions/lengthSquared.h>

TEST_CASE( "LengthSquared_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 2.0f );
    CHECK( gm::LengthSquared( vector ) == 4.0f );
}

TEST_CASE( "LengthSquared_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 2.0f, 4.0f );
    CHECK( gm::LengthSquared( vector ) == 20.0f );
}

TEST_CASE( "LengthSquared_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 2.0f, 4.0f, 6.0f );
    CHECK( gm::LengthSquared( vector ) == 56.0f );
}
