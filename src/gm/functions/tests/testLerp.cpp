//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/lerp.h>

TEST_CASE( "Lerp_float" )
{
    float floatValA    = 3.0f;
    float floatValB    = 1.0f;
    float floatValLerp = gm::Lerp( floatValA, floatValB, 0.5f );
    CHECK( floatValLerp == Approx( 2.0f ) );
}

TEST_CASE( "Lerp_Mat3f" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB( 0.0f, 4.0f, 8.0f, 12.0f, 16.0f, 20.0f, 24.0f, 28.0f, 32.0f );
    gm::Mat3f matrixLerp = gm::Lerp( matrixA, matrixB, 0.5f );
    CHECK( matrixLerp[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixLerp[ 1 ] == Approx( 3.0f ) );
    CHECK( matrixLerp[ 2 ] == Approx( 6.0f ) );
    CHECK( matrixLerp[ 3 ] == Approx( 9.0f ) );
    CHECK( matrixLerp[ 4 ] == Approx( 12.0f ) );
    CHECK( matrixLerp[ 5 ] == Approx( 15.0f ) );
    CHECK( matrixLerp[ 6 ] == Approx( 18.0f ) );
    CHECK( matrixLerp[ 7 ] == Approx( 21.0f ) );
    CHECK( matrixLerp[ 8 ] == Approx( 24.0f ) );
}

TEST_CASE( "Lerp_Mat4f" )
{
    gm::Mat4f matrixA( 0.0f,
                       2.0f,
                       4.0f,
                       6.0f,
                       8.0f,
                       10.0f,
                       12.0f,
                       14.0f,
                       16.0f,
                       18.0f,
                       20.0f,
                       22.0f,
                       24.0f,
                       26.0f,
                       28.0f,
                       30.0f );
    gm::Mat4f matrixB( 0.0f,
                       4.0f,
                       8.0f,
                       12.0f,
                       16.0f,
                       20.0f,
                       24.0f,
                       28.0f,
                       32.0f,
                       36.0f,
                       40.0f,
                       44.0f,
                       48.0f,
                       52.0f,
                       56.0f,
                       60.0f );
    gm::Mat4f matrixLerp = gm::Lerp( matrixA, matrixB, 0.5f );
    CHECK( matrixLerp[ 0 ] == Approx( 0.0f ) );
    CHECK( matrixLerp[ 1 ] == Approx( 3.0f ) );
    CHECK( matrixLerp[ 2 ] == Approx( 6.0f ) );
    CHECK( matrixLerp[ 3 ] == Approx( 9.0f ) );
    CHECK( matrixLerp[ 4 ] == Approx( 12.0f ) );
    CHECK( matrixLerp[ 5 ] == Approx( 15.0f ) );
    CHECK( matrixLerp[ 6 ] == Approx( 18.0f ) );
    CHECK( matrixLerp[ 7 ] == Approx( 21.0f ) );
    CHECK( matrixLerp[ 8 ] == Approx( 24.0f ) );
    CHECK( matrixLerp[ 9 ] == Approx( 27.0f ) );
    CHECK( matrixLerp[ 10 ] == Approx( 30.0f ) );
    CHECK( matrixLerp[ 11 ] == Approx( 33.0f ) );
    CHECK( matrixLerp[ 12 ] == Approx( 36.0f ) );
    CHECK( matrixLerp[ 13 ] == Approx( 39.0f ) );
    CHECK( matrixLerp[ 14 ] == Approx( 42.0f ) );
    CHECK( matrixLerp[ 15 ] == Approx( 45.0f ) );
}

TEST_CASE( "Lerp_Vec2f" )
{
    gm::Vec2f vectorA( 0.0f, 2.0f );
    gm::Vec2f vectorB( 0.0f, 4.0f );
    gm::Vec2f vectorLerp = gm::Lerp( vectorA, vectorB, 0.5f );
    CHECK( vectorLerp[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorLerp[ 1 ] == Approx( 3.0f ) );
}

TEST_CASE( "Lerp_Vec3f" )
{
    gm::Vec3f vectorA( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB( 0.0f, 4.0f, 8.0f );
    gm::Vec3f vectorLerp = gm::Lerp( vectorA, vectorB, 0.5f );
    CHECK( vectorLerp[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorLerp[ 1 ] == Approx( 3.0f ) );
    CHECK( vectorLerp[ 2 ] == Approx( 6.0f ) );
}

TEST_CASE( "Lerp_Vec4f" )
{
    gm::Vec4f vectorA( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB( 0.0f, 4.0f, 8.0f, 12.0f );
    gm::Vec4f vectorLerp = gm::Lerp( vectorA, vectorB, 0.5f );
    CHECK( vectorLerp[ 0 ] == Approx( 0.0f ) );
    CHECK( vectorLerp[ 1 ] == Approx( 3.0f ) );
    CHECK( vectorLerp[ 2 ] == Approx( 6.0f ) );
    CHECK( vectorLerp[ 3 ] == Approx( 9.0f ) );
}
