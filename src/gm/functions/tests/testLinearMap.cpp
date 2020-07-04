//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/linearMap.h>

TEST_CASE( "LinearMap_float" )
{
    float floatVal       = 0.5f;
    float floatValMapped = gm::LinearMap( floatVal, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( floatValMapped == Approx( 0.75f ) );
}

TEST_CASE( "LinearMap_Mat3f" )
{
    gm::Mat3f matrix( 0.0f, 0.05f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f, 0.35f, 0.4f );
    gm::Mat3f matrixMapped = gm::LinearMap( matrix, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( matrixMapped[ 0 ] == Approx( 0.5f ) );
    CHECK( matrixMapped[ 1 ] == Approx( 0.525f ) );
    CHECK( matrixMapped[ 2 ] == Approx( 0.55f ) );
    CHECK( matrixMapped[ 3 ] == Approx( 0.575f ) );
    CHECK( matrixMapped[ 4 ] == Approx( 0.6f ) );
    CHECK( matrixMapped[ 5 ] == Approx( 0.625f ) );
    CHECK( matrixMapped[ 6 ] == Approx( 0.65f ) );
    CHECK( matrixMapped[ 7 ] == Approx( 0.675f ) );
    CHECK( matrixMapped[ 8 ] == Approx( 0.7f ) );
}

TEST_CASE( "LinearMap_Mat4f" )
{
    gm::Mat4f matrix( 0.0f,
                      0.05f,
                      0.1f,
                      0.15f,
                      0.2f,
                      0.25f,
                      0.3f,
                      0.35f,
                      0.4f,
                      0.45f,
                      0.5f,
                      0.55f,
                      0.6f,
                      0.65f,
                      0.7f,
                      0.75f );
    gm::Mat4f matrixMapped = gm::LinearMap( matrix, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( matrixMapped[ 0 ] == Approx( 0.5f ) );
    CHECK( matrixMapped[ 1 ] == Approx( 0.525f ) );
    CHECK( matrixMapped[ 2 ] == Approx( 0.55f ) );
    CHECK( matrixMapped[ 3 ] == Approx( 0.575f ) );
    CHECK( matrixMapped[ 4 ] == Approx( 0.6f ) );
    CHECK( matrixMapped[ 5 ] == Approx( 0.625f ) );
    CHECK( matrixMapped[ 6 ] == Approx( 0.65f ) );
    CHECK( matrixMapped[ 7 ] == Approx( 0.675f ) );
    CHECK( matrixMapped[ 8 ] == Approx( 0.7f ) );
    CHECK( matrixMapped[ 9 ] == Approx( 0.725f ) );
    CHECK( matrixMapped[ 10 ] == Approx( 0.75f ) );
    CHECK( matrixMapped[ 11 ] == Approx( 0.775f ) );
    CHECK( matrixMapped[ 12 ] == Approx( 0.8f ) );
    CHECK( matrixMapped[ 13 ] == Approx( 0.825f ) );
    CHECK( matrixMapped[ 14 ] == Approx( 0.85f ) );
    CHECK( matrixMapped[ 15 ] == Approx( 0.875f ) );
}

TEST_CASE( "LinearMap_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 0.05f );
    gm::Vec2f vectorMapped = gm::LinearMap( vector, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( vectorMapped[ 0 ] == Approx( 0.5f ) );
    CHECK( vectorMapped[ 1 ] == Approx( 0.525f ) );
}

TEST_CASE( "LinearMap_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 0.05f, 0.1f );
    gm::Vec3f vectorMapped = gm::LinearMap( vector, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( vectorMapped[ 0 ] == Approx( 0.5f ) );
    CHECK( vectorMapped[ 1 ] == Approx( 0.525f ) );
    CHECK( vectorMapped[ 2 ] == Approx( 0.55f ) );
}

TEST_CASE( "LinearMap_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 0.05f, 0.1f, 0.15f );
    gm::Vec4f vectorMapped = gm::LinearMap( vector, gm::FloatRange( -1.0f, 1.0f ), gm::FloatRange( 0.0f, 1.0f ) );
    CHECK( vectorMapped[ 0 ] == Approx( 0.5f ) );
    CHECK( vectorMapped[ 1 ] == Approx( 0.525f ) );
    CHECK( vectorMapped[ 2 ] == Approx( 0.55f ) );
    CHECK( vectorMapped[ 3 ] == Approx( 0.575f ) );
}
