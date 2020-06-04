//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/abs.h>

TEST_CASE( "Abs_float" )
{
    float floatVal    = -2.333f;
    float floatValAbs = gm::Abs( floatVal );
    CHECK( floatValAbs == Approx( 2.333f ) );
}

TEST_CASE( "Abs_Vec2f" )
{
    gm::Vec2f vector( 0.0f, -2.333f );
    gm::Vec2f vectorAbs = gm::Abs( vector );
    CHECK( vectorAbs[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorAbs[ 1 ] == Approx( 2.333f ) );
}

TEST_CASE( "Abs_Vec3f" )
{
    gm::Vec3f vector( 0.0f, -2.333f, 4.666f );
    gm::Vec3f vectorAbs = gm::Abs( vector );
    CHECK( vectorAbs[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorAbs[ 1 ] == Approx( 2.333f ) );
    CHECK( vectorAbs[ 2 ] == Approx( 4.666f ) );
}

TEST_CASE( "Abs_Vec4f" )
{
    gm::Vec4f vector( 0.0f, -2.333f, 4.666f, -6.999f );
    gm::Vec4f vectorAbs = gm::Abs( vector );
    CHECK( vectorAbs[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorAbs[ 1 ] == Approx( 2.333f ) );
    CHECK( vectorAbs[ 2 ] == Approx( 4.666f ) );
    CHECK( vectorAbs[ 3 ] == Approx( 6.999f ) );
}

TEST_CASE( "Abs_Mat3f" )
{
    gm::Mat3f matrix( 0.0f, -2.333f, 4.666f, -6.999f, 9.332f, -11.665f, 13.998f, -16.331f, 18.664f );
    gm::Mat3f matrixAbs = gm::Abs( matrix );
    CHECK( matrixAbs[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixAbs[ 1 ] == Approx( 2.333f ) );
    CHECK( matrixAbs[ 2 ] == Approx( 4.666f ) );
    CHECK( matrixAbs[ 3 ] == Approx( 6.999f ) );
    CHECK( matrixAbs[ 4 ] == Approx( 9.332f ) );
    CHECK( matrixAbs[ 5 ] == Approx( 11.665f ) );
    CHECK( matrixAbs[ 6 ] == Approx( 13.998f ) );
    CHECK( matrixAbs[ 7 ] == Approx( 16.331f ) );
    CHECK( matrixAbs[ 8 ] == Approx( 18.664f ) );
}

TEST_CASE( "Abs_Mat4f" )
{
    gm::Mat4f matrix( 0.0f,
                      -2.333f,
                      4.666f,
                      -6.999f,
                      9.332f,
                      -11.665f,
                      13.998f,
                      -16.331f,
                      18.664f,
                      -20.997f,
                      23.33f,
                      -25.663f,
                      27.996f,
                      -30.329f,
                      32.662f,
                      -34.995f );
    gm::Mat4f matrixAbs = gm::Abs( matrix );
    CHECK( matrixAbs[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixAbs[ 1 ] == Approx( 2.333f ) );
    CHECK( matrixAbs[ 2 ] == Approx( 4.666f ) );
    CHECK( matrixAbs[ 3 ] == Approx( 6.999f ) );
    CHECK( matrixAbs[ 4 ] == Approx( 9.332f ) );
    CHECK( matrixAbs[ 5 ] == Approx( 11.665f ) );
    CHECK( matrixAbs[ 6 ] == Approx( 13.998f ) );
    CHECK( matrixAbs[ 7 ] == Approx( 16.331f ) );
    CHECK( matrixAbs[ 8 ] == Approx( 18.664f ) );
    CHECK( matrixAbs[ 9 ] == Approx( 20.997f ) );
    CHECK( matrixAbs[ 10 ] == Approx( 23.33f ) );
    CHECK( matrixAbs[ 11 ] == Approx( 25.663f ) );
    CHECK( matrixAbs[ 12 ] == Approx( 27.996f ) );
    CHECK( matrixAbs[ 13 ] == Approx( 30.329f ) );
    CHECK( matrixAbs[ 14 ] == Approx( 32.662f ) );
    CHECK( matrixAbs[ 15 ] == Approx( 34.995f ) );
}
