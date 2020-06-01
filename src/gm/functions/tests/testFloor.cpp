//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/floor.h>

TEST_CASE( "Floor_float" )
{
    float floatVal        = 2.333f;
    float floatValFloored = gm::Floor( floatVal );
    CHECK( floatValFloored == Approx( 2.0f ) );
}

TEST_CASE( "Floor_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 2.333f );
    gm::Vec2f vectorFloored = gm::Floor( vector );
    CHECK( vectorFloored[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorFloored[ 1 ] == Approx( 2.0f ) );
}

TEST_CASE( "Floor_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 2.333f, 4.666f );
    gm::Vec3f vectorFloored = gm::Floor( vector );
    CHECK( vectorFloored[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorFloored[ 1 ] == Approx( 2.0f ) );
    CHECK( vectorFloored[ 2 ] == Approx( 4.0f ) );
}

TEST_CASE( "Floor_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 2.333f, 4.666f, 6.999f );
    gm::Vec4f vectorFloored = gm::Floor( vector );
    CHECK( vectorFloored[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorFloored[ 1 ] == Approx( 2.0f ) );
    CHECK( vectorFloored[ 2 ] == Approx( 4.0f ) );
    CHECK( vectorFloored[ 3 ] == Approx( 6.0f ) );
}

TEST_CASE( "Floor_Mat3f" )
{
    gm::Mat3f matrix( 0.0f, 2.333f, 4.666f, 6.999f, 9.332f, 11.665f, 13.998f, 16.331f, 18.664f );
    gm::Mat3f matrixFloored = gm::Floor( matrix );
    CHECK( matrixFloored[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixFloored[ 1 ] == Approx( 2.0f ) );
    CHECK( matrixFloored[ 2 ] == Approx( 4.0f ) );
    CHECK( matrixFloored[ 3 ] == Approx( 6.0f ) );
    CHECK( matrixFloored[ 4 ] == Approx( 9.0f ) );
    CHECK( matrixFloored[ 5 ] == Approx( 11.0f ) );
    CHECK( matrixFloored[ 6 ] == Approx( 13.0f ) );
    CHECK( matrixFloored[ 7 ] == Approx( 16.0f ) );
    CHECK( matrixFloored[ 8 ] == Approx( 18.0f ) );
}

TEST_CASE( "Floor_Mat4f" )
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
    gm::Mat4f matrixFloored = gm::Floor( matrix );
    CHECK( matrixFloored[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixFloored[ 1 ] == Approx( 2.0f ) );
    CHECK( matrixFloored[ 2 ] == Approx( 4.0f ) );
    CHECK( matrixFloored[ 3 ] == Approx( 6.0f ) );
    CHECK( matrixFloored[ 4 ] == Approx( 9.0f ) );
    CHECK( matrixFloored[ 5 ] == Approx( 11.0f ) );
    CHECK( matrixFloored[ 6 ] == Approx( 13.0f ) );
    CHECK( matrixFloored[ 7 ] == Approx( 16.0f ) );
    CHECK( matrixFloored[ 8 ] == Approx( 18.0f ) );
    CHECK( matrixFloored[ 9 ] == Approx( 20.0f ) );
    CHECK( matrixFloored[ 10 ] == Approx( 23.0f ) );
    CHECK( matrixFloored[ 11 ] == Approx( 25.0f ) );
    CHECK( matrixFloored[ 12 ] == Approx( 27.0f ) );
    CHECK( matrixFloored[ 13 ] == Approx( 30.0f ) );
    CHECK( matrixFloored[ 14 ] == Approx( 32.0f ) );
    CHECK( matrixFloored[ 15 ] == Approx( 34.0f ) );
}
