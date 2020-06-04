//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/max.h>

TEST_CASE( "Max_float" )
{
    float floatValA   = 2.333f;
    float floatValB   = 1.333f;
    float floatValMax = gm::Max( floatValA, floatValB );
    CHECK( floatValMax == Approx( 2.333f ) );
}

TEST_CASE( "Max_int" )
{
    int intValA   = 2;
    int intValB   = 1;
    int intValMax = gm::Max( intValA, intValB );
    CHECK( intValMax == Approx( 2 ) );
}

TEST_CASE( "Max_bool" )
{
    bool boolValA   = true;
    bool boolValB   = true;
    bool boolValMax = gm::Max( boolValA, boolValB );
    CHECK( boolValMax == Approx( true ) );
}

TEST_CASE( "Max_Mat3f" )
{
    gm::Mat3f matrixA( 0.0f, 2.333f, 4.666f, 6.999f, 9.332f, 11.665f, 13.998f, 16.331f, 18.664f );
    gm::Mat3f matrixB( 0.0f, 1.333f, 2.666f, 3.999f, 5.332f, 6.665f, 7.998f, 9.331f, 10.664f );
    gm::Mat3f matrixMax = gm::Max( matrixA, matrixB );
    CHECK( matrixMax[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixMax[ 1 ] == Approx( 2.333f ) );
    CHECK( matrixMax[ 2 ] == Approx( 4.666f ) );
    CHECK( matrixMax[ 3 ] == Approx( 6.999f ) );
    CHECK( matrixMax[ 4 ] == Approx( 9.332f ) );
    CHECK( matrixMax[ 5 ] == Approx( 11.665f ) );
    CHECK( matrixMax[ 6 ] == Approx( 13.998f ) );
    CHECK( matrixMax[ 7 ] == Approx( 16.331f ) );
    CHECK( matrixMax[ 8 ] == Approx( 18.664f ) );
}

TEST_CASE( "Max_Mat4f" )
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
    gm::Mat4f matrixMax = gm::Max( matrixA, matrixB );
    CHECK( matrixMax[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixMax[ 1 ] == Approx( 2.333f ) );
    CHECK( matrixMax[ 2 ] == Approx( 4.666f ) );
    CHECK( matrixMax[ 3 ] == Approx( 6.999f ) );
    CHECK( matrixMax[ 4 ] == Approx( 9.332f ) );
    CHECK( matrixMax[ 5 ] == Approx( 11.665f ) );
    CHECK( matrixMax[ 6 ] == Approx( 13.998f ) );
    CHECK( matrixMax[ 7 ] == Approx( 16.331f ) );
    CHECK( matrixMax[ 8 ] == Approx( 18.664f ) );
    CHECK( matrixMax[ 9 ] == Approx( 20.997f ) );
    CHECK( matrixMax[ 10 ] == Approx( 23.33f ) );
    CHECK( matrixMax[ 11 ] == Approx( 25.663f ) );
    CHECK( matrixMax[ 12 ] == Approx( 27.996f ) );
    CHECK( matrixMax[ 13 ] == Approx( 30.329f ) );
    CHECK( matrixMax[ 14 ] == Approx( 32.662f ) );
    CHECK( matrixMax[ 15 ] == Approx( 34.995f ) );
}

TEST_CASE( "Max_Vec2f" )
{
    gm::Vec2f vectorA( 0.0f, 2.333f );
    gm::Vec2f vectorB( 0.0f, 1.333f );
    gm::Vec2f vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMax[ 1 ] == Approx( 2.333f ) );
}

TEST_CASE( "Max_Vec3f" )
{
    gm::Vec3f vectorA( 0.0f, 2.333f, 4.666f );
    gm::Vec3f vectorB( 0.0f, 1.333f, 2.666f );
    gm::Vec3f vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMax[ 1 ] == Approx( 2.333f ) );
    CHECK( vectorMax[ 2 ] == Approx( 4.666f ) );
}

TEST_CASE( "Max_Vec4f" )
{
    gm::Vec4f vectorA( 0.0f, 2.333f, 4.666f, 6.999f );
    gm::Vec4f vectorB( 0.0f, 1.333f, 2.666f, 3.999f );
    gm::Vec4f vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorMax[ 1 ] == Approx( 2.333f ) );
    CHECK( vectorMax[ 2 ] == Approx( 4.666f ) );
    CHECK( vectorMax[ 3 ] == Approx( 6.999f ) );
}

TEST_CASE( "Max_Vec2i" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( 0, 1 );
    gm::Vec2i vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0 ) );
    CHECK( vectorMax[ 1 ] == Approx( 2 ) );
}

TEST_CASE( "Max_Vec3i" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( 0, 1, 2 );
    gm::Vec3i vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0 ) );
    CHECK( vectorMax[ 1 ] == Approx( 2 ) );
    CHECK( vectorMax[ 2 ] == Approx( 4 ) );
}

TEST_CASE( "Max_Vec4i" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( 0, 1, 2, 3 );
    gm::Vec4i vectorMax = gm::Max( vectorA, vectorB );
    CHECK( vectorMax[ 0 ] == Approx( 0 ) );
    CHECK( vectorMax[ 1 ] == Approx( 2 ) );
    CHECK( vectorMax[ 2 ] == Approx( 4 ) );
    CHECK( vectorMax[ 3 ] == Approx( 6 ) );
}
