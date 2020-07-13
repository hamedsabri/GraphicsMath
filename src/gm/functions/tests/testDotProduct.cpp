//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/dotProduct.h>

TEST_CASE( "DotProduct_Vec2f" )
{
    gm::Vec2f vectorA = gm::Vec2f( 0.0f, 1.0f );
    gm::Vec2f vectorB = gm::Vec2f( 0.0f, 5.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 5.0f );
}

TEST_CASE( "DotProduct_Vec3f" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 1.0f, 2.0f );
    gm::Vec3f vectorB = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 25.0f );
}

TEST_CASE( "DotProduct_Vec4f" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    gm::Vec4f vectorB = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    CHECK( gm::DotProduct( vectorA, vectorB ) == 70.0f );
}
