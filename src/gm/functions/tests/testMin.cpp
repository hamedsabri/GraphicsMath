//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/min.h>

TEST_CASE( "Min_float" )
{
    float floatValA   = 2.333f;
    float floatValB   = 1.333f;
    float floatValMin = gm::Min( floatValA, floatValB );
    CHECK( floatValMin == Approx( 1.333f ) );
}

TEST_CASE( "Min_int" )
{
    int intValA   = 2;
    int intValB   = 1;
    int intValMin = gm::Min( intValA, intValB );
    CHECK( intValMin == Approx( 1 ) );
}

TEST_CASE( "Min_Mat3f" )
{
    gm::Mat3f matrixA( 0.0f, 2.333f, 4.666f, 6.999f, 9.332f, 11.665f, 13.998f, 16.331f, 18.664f );
    gm::Mat3f matrixB( 0.0f, 1.333f, 2.666f, 3.999f, 5.332f, 6.665f, 7.998f, 9.331f, 10.664f );
    gm::Mat3f matrixMin = gm::Min( matrixA, matrixB );
    CHECK( matrixMin[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixMin[ 1 ] == Approx( 1.333f ) );
    CHECK( matrixMin[ 2 ] == Approx( 2.666f ) );
    CHECK( matrixMin[ 3 ] == Approx( 3.999f ) );
    CHECK( matrixMin[ 4 ] == Approx( 5.332f ) );
    CHECK( matrixMin[ 5 ] == Approx( 6.665f ) );
    CHECK( matrixMin[ 6 ] == Approx( 7.998f ) );
    CHECK( matrixMin[ 7 ] == Approx( 9.331f ) );
    CHECK( matrixMin[ 8 ] == Approx( 10.664f ) );
}

TEST_CASE( "Min_Mat4f" )
{
    gm::Mat4f matrixA( 0.0f,
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
    gm::Mat4f matrixB( 0.0f,
                       1.333f,
                       2.666f,
                       3.999f,
                       5.332f,
                       6.665f,
                       7.998f,
                       9.331f,
                       10.664f,
                       11.997f,
                       13.33f,
                       14.663f,
                       15.996f,
                       17.329f,
                       18.662f,
                       19.995f );
    gm::Mat4f matrixMin = gm::Min( matrixA, matrixB );
    CHECK( matrixMin[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixMin[ 1 ] == Approx( 1.333f ) );
    CHECK( matrixMin[ 2 ] == Approx( 2.666f ) );
    CHECK( matrixMin[ 3 ] == Approx( 3.999f ) );
    CHECK( matrixMin[ 4 ] == Approx( 5.332f ) );
    CHECK( matrixMin[ 5 ] == Approx( 6.665f ) );
    CHECK( matrixMin[ 6 ] == Approx( 7.998f ) );
    CHECK( matrixMin[ 7 ] == Approx( 9.331f ) );
    CHECK( matrixMin[ 8 ] == Approx( 10.664f ) );
    CHECK( matrixMin[ 9 ] == Approx( 11.997f ) );
    CHECK( matrixMin[ 10 ] == Approx( 13.33f ) );
    CHECK( matrixMin[ 11 ] == Approx( 14.663f ) );
    CHECK( matrixMin[ 12 ] == Approx( 15.996f ) );
    CHECK( matrixMin[ 13 ] == Approx( 17.329f ) );
    CHECK( matrixMin[ 14 ] == Approx( 18.662f ) );
    CHECK( matrixMin[ 15 ] == Approx( 19.995f ) );
}

TEST_CASE( "Min_Vec2f" )
{
    gm::Vec2f vectorA( 0.0f, 2.333f );
    gm::Vec2f vectorB( 0.0f, 1.333f );
    gm::Vec2f vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMin[ 1 ] == Approx( 1.333f ) );
}

TEST_CASE( "Min_Vec3f" )
{
    gm::Vec3f vectorA( 0.0f, 2.333f, 4.666f );
    gm::Vec3f vectorB( 0.0f, 1.333f, 2.666f );
    gm::Vec3f vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMin[ 1 ] == Approx( 1.333f ) );
    CHECK( vectorMin[ 2 ] == Approx( 2.666f ) );
}

TEST_CASE( "Min_Vec4f" )
{
    gm::Vec4f vectorA( 0.0f, 2.333f, 4.666f, 6.999f );
    gm::Vec4f vectorB( 0.0f, 1.333f, 2.666f, 3.999f );
    gm::Vec4f vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMin[ 1 ] == Approx( 1.333f ) );
    CHECK( vectorMin[ 2 ] == Approx( 2.666f ) );
    CHECK( vectorMin[ 3 ] == Approx( 3.999f ) );
}

TEST_CASE( "Min_Vec2i" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( 0, 1 );
    gm::Vec2i vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0 ) );
    CHECK( vectorMin[ 1 ] == Approx( 1 ) );
}

TEST_CASE( "Min_Vec3i" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( 0, 1, 2 );
    gm::Vec3i vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0 ) );
    CHECK( vectorMin[ 1 ] == Approx( 1 ) );
    CHECK( vectorMin[ 2 ] == Approx( 2 ) );
}

TEST_CASE( "Min_Vec4i" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( 0, 1, 2, 3 );
    gm::Vec4i vectorMin = gm::Min( vectorA, vectorB );
    CHECK( vectorMin[ 0 ] == Approx( 0 ) );
    CHECK( vectorMin[ 1 ] == Approx( 1 ) );
    CHECK( vectorMin[ 2 ] == Approx( 2 ) );
    CHECK( vectorMin[ 3 ] == Approx( 3 ) );
}
