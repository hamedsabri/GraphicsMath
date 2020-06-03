//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/ceil.h>

TEST_CASE( "Ceil_float" )
{
    float floatVal       = 2.333f;
    float floatValCeiled = gm::Ceil( floatVal );
    CHECK( floatValCeiled == Approx( 3.0f ) );
}

TEST_CASE( "Ceil_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 2.333f );
    gm::Vec2f vectorCeiled = gm::Ceil( vector );
    CHECK( vectorCeiled[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorCeiled[ 1 ] == Approx( 3.0f ) );
}

TEST_CASE( "Ceil_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 2.333f, 4.666f );
    gm::Vec3f vectorCeiled = gm::Ceil( vector );
    CHECK( vectorCeiled[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorCeiled[ 1 ] == Approx( 3.0f ) );
    CHECK( vectorCeiled[ 2 ] == Approx( 5.0f ) );
}

TEST_CASE( "Ceil_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 2.333f, 4.666f, 6.999f );
    gm::Vec4f vectorCeiled = gm::Ceil( vector );
    CHECK( vectorCeiled[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorCeiled[ 1 ] == Approx( 3.0f ) );
    CHECK( vectorCeiled[ 2 ] == Approx( 5.0f ) );
    CHECK( vectorCeiled[ 3 ] == Approx( 7.0f ) );
}

TEST_CASE( "Ceil_Mat3f" )
{
    gm::Mat3f matrix( 0.0f, 2.333f, 4.666f, 6.999f, 9.332f, 11.665f, 13.998f, 16.331f, 18.664f );
    gm::Mat3f matrixCeiled = gm::Ceil( matrix );
    CHECK( matrixCeiled[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixCeiled[ 1 ] == Approx( 3.0f ) );
    CHECK( matrixCeiled[ 2 ] == Approx( 5.0f ) );
    CHECK( matrixCeiled[ 3 ] == Approx( 7.0f ) );
    CHECK( matrixCeiled[ 4 ] == Approx( 10.0f ) );
    CHECK( matrixCeiled[ 5 ] == Approx( 12.0f ) );
    CHECK( matrixCeiled[ 6 ] == Approx( 14.0f ) );
    CHECK( matrixCeiled[ 7 ] == Approx( 17.0f ) );
    CHECK( matrixCeiled[ 8 ] == Approx( 19.0f ) );
}

TEST_CASE( "Ceil_Mat4f" )
{
    gm::Mat4f matrix( 0.0f,
                      2.333f,
                      4.666f,
                      6.999f,
                      9.332f,
                      11.665f,
                      13.998f,
                      16.331f,
                      18.664f,
                      20.997f,
                      23.33f,
                      25.663f,
                      27.996f,
                      30.329f,
                      32.662f,
                      34.995f );
    gm::Mat4f matrixCeiled = gm::Ceil( matrix );
    CHECK( matrixCeiled[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixCeiled[ 1 ] == Approx( 3.0f ) );
    CHECK( matrixCeiled[ 2 ] == Approx( 5.0f ) );
    CHECK( matrixCeiled[ 3 ] == Approx( 7.0f ) );
    CHECK( matrixCeiled[ 4 ] == Approx( 10.0f ) );
    CHECK( matrixCeiled[ 5 ] == Approx( 12.0f ) );
    CHECK( matrixCeiled[ 6 ] == Approx( 14.0f ) );
    CHECK( matrixCeiled[ 7 ] == Approx( 17.0f ) );
    CHECK( matrixCeiled[ 8 ] == Approx( 19.0f ) );
    CHECK( matrixCeiled[ 9 ] == Approx( 21.0f ) );
    CHECK( matrixCeiled[ 10 ] == Approx( 24.0f ) );
    CHECK( matrixCeiled[ 11 ] == Approx( 26.0f ) );
    CHECK( matrixCeiled[ 12 ] == Approx( 28.0f ) );
    CHECK( matrixCeiled[ 13 ] == Approx( 31.0f ) );
    CHECK( matrixCeiled[ 14 ] == Approx( 33.0f ) );
    CHECK( matrixCeiled[ 15 ] == Approx( 35.0f ) );
}
