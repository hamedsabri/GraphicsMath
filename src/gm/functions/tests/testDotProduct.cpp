#include <catch2/catch.hpp>

#include <gm/functions/dotProduct.h>

// This test is auto-generated! Please do not modify directly

TEST_CASE( "DotProduct_Vec2f" )
{
    gm::Vec2f vectorA( 0.0f, 1.0f );
    gm::Vec2f vectorB( 0.0f, 5.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 5.0f );
}

TEST_CASE( "DotProduct_Vec3f" )
{
    gm::Vec3f vectorA( 0.0f, 1.0f, 2.0f );
    gm::Vec3f vectorB( 0.0f, 5.0f, 10.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 25.0f );
}

TEST_CASE( "DotProduct_Vec4f" )
{
    gm::Vec4f vectorA( 0.0f, 1.0f, 2.0f, 3.0f );
    gm::Vec4f vectorB( 0.0f, 5.0f, 10.0f, 15.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 70.0f );
}
