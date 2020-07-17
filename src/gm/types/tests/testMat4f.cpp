//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/mat4f.h>

TEST_CASE( "Mat4f_DefaultConstructor" )
{
    gm::Mat4f matrix;
    CHECK(
        matrix ==
        gm::Mat4f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f ) );
}

TEST_CASE( "Mat4f_CopyConstructor" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB( matrixA );
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat4f_CopyAssignmentConstructor" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB = matrixA;
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat4f_ElementReadAccess" )
{
    gm::Mat4f matrix = gm::Mat4f( 0.0f,
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
    CHECK( matrix[ 0 ] == 0.0f );
    CHECK( matrix[ 1 ] == 2.0f );
    CHECK( matrix[ 2 ] == 4.0f );
    CHECK( matrix[ 3 ] == 6.0f );
    CHECK( matrix[ 4 ] == 8.0f );
    CHECK( matrix[ 5 ] == 10.0f );
    CHECK( matrix[ 6 ] == 12.0f );
    CHECK( matrix[ 7 ] == 14.0f );
    CHECK( matrix[ 8 ] == 16.0f );
    CHECK( matrix[ 9 ] == 18.0f );
    CHECK( matrix[ 10 ] == 20.0f );
    CHECK( matrix[ 11 ] == 22.0f );
    CHECK( matrix[ 12 ] == 24.0f );
    CHECK( matrix[ 13 ] == 26.0f );
    CHECK( matrix[ 14 ] == 28.0f );
    CHECK( matrix[ 15 ] == 30.0f );
}

TEST_CASE( "Mat4f_ElementWriteAccess" )
{
    gm::Mat4f matrix;
    matrix[ 0 ]  = 0.0f;
    matrix[ 1 ]  = 5.0f;
    matrix[ 2 ]  = 10.0f;
    matrix[ 3 ]  = 15.0f;
    matrix[ 4 ]  = 20.0f;
    matrix[ 5 ]  = 25.0f;
    matrix[ 6 ]  = 30.0f;
    matrix[ 7 ]  = 35.0f;
    matrix[ 8 ]  = 40.0f;
    matrix[ 9 ]  = 45.0f;
    matrix[ 10 ] = 50.0f;
    matrix[ 11 ] = 55.0f;
    matrix[ 12 ] = 60.0f;
    matrix[ 13 ] = 65.0f;
    matrix[ 14 ] = 70.0f;
    matrix[ 15 ] = 75.0f;
    CHECK( matrix[ 0 ] == 0.0f );
    CHECK( matrix[ 1 ] == 5.0f );
    CHECK( matrix[ 2 ] == 10.0f );
    CHECK( matrix[ 3 ] == 15.0f );
    CHECK( matrix[ 4 ] == 20.0f );
    CHECK( matrix[ 5 ] == 25.0f );
    CHECK( matrix[ 6 ] == 30.0f );
    CHECK( matrix[ 7 ] == 35.0f );
    CHECK( matrix[ 8 ] == 40.0f );
    CHECK( matrix[ 9 ] == 45.0f );
    CHECK( matrix[ 10 ] == 50.0f );
    CHECK( matrix[ 11 ] == 55.0f );
    CHECK( matrix[ 12 ] == 60.0f );
    CHECK( matrix[ 13 ] == 65.0f );
    CHECK( matrix[ 14 ] == 70.0f );
    CHECK( matrix[ 15 ] == 75.0f );
}

TEST_CASE( "Mat4f_Addition" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB = gm::Mat4f( 0.0f,
                                   5.0f,
                                   10.0f,
                                   15.0f,
                                   20.0f,
                                   25.0f,
                                   30.0f,
                                   35.0f,
                                   40.0f,
                                   45.0f,
                                   50.0f,
                                   55.0f,
                                   60.0f,
                                   65.0f,
                                   70.0f,
                                   75.0f );
    gm::Mat4f matrixC = matrixA + matrixB;
    CHECK( matrixC == gm::Mat4f( 0.0f,
                                 7.0f,
                                 14.0f,
                                 21.0f,
                                 28.0f,
                                 35.0f,
                                 42.0f,
                                 49.0f,
                                 56.0f,
                                 63.0f,
                                 70.0f,
                                 77.0f,
                                 84.0f,
                                 91.0f,
                                 98.0f,
                                 105.0f ) );
}

TEST_CASE( "Mat4f_AdditionAssignment" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB = gm::Mat4f( 0.0f,
                                   5.0f,
                                   10.0f,
                                   15.0f,
                                   20.0f,
                                   25.0f,
                                   30.0f,
                                   35.0f,
                                   40.0f,
                                   45.0f,
                                   50.0f,
                                   55.0f,
                                   60.0f,
                                   65.0f,
                                   70.0f,
                                   75.0f );
    matrixB += matrixA;
    CHECK( matrixB == gm::Mat4f( 0.0f,
                                 7.0f,
                                 14.0f,
                                 21.0f,
                                 28.0f,
                                 35.0f,
                                 42.0f,
                                 49.0f,
                                 56.0f,
                                 63.0f,
                                 70.0f,
                                 77.0f,
                                 84.0f,
                                 91.0f,
                                 98.0f,
                                 105.0f ) );
}

TEST_CASE( "Mat4f_Subtraction" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
                                   7.0f,
                                   14.0f,
                                   21.0f,
                                   28.0f,
                                   35.0f,
                                   42.0f,
                                   49.0f,
                                   56.0f,
                                   63.0f,
                                   70.0f,
                                   77.0f,
                                   84.0f,
                                   91.0f,
                                   98.0f,
                                   105.0f );
    gm::Mat4f matrixB = gm::Mat4f( 0.0f,
                                   5.0f,
                                   10.0f,
                                   15.0f,
                                   20.0f,
                                   25.0f,
                                   30.0f,
                                   35.0f,
                                   40.0f,
                                   45.0f,
                                   50.0f,
                                   55.0f,
                                   60.0f,
                                   65.0f,
                                   70.0f,
                                   75.0f );
    gm::Mat4f matrixC = matrixA - matrixB;
    CHECK( matrixC == gm::Mat4f( 0.0f,
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
                                 30.0f ) );
}

TEST_CASE( "Mat4f_SubtractionAssignment" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
                                   5.0f,
                                   10.0f,
                                   15.0f,
                                   20.0f,
                                   25.0f,
                                   30.0f,
                                   35.0f,
                                   40.0f,
                                   45.0f,
                                   50.0f,
                                   55.0f,
                                   60.0f,
                                   65.0f,
                                   70.0f,
                                   75.0f );
    gm::Mat4f matrixB = gm::Mat4f( 0.0f,
                                   7.0f,
                                   14.0f,
                                   21.0f,
                                   28.0f,
                                   35.0f,
                                   42.0f,
                                   49.0f,
                                   56.0f,
                                   63.0f,
                                   70.0f,
                                   77.0f,
                                   84.0f,
                                   91.0f,
                                   98.0f,
                                   105.0f );
    matrixB -= matrixA;
    CHECK( matrixB == gm::Mat4f( 0.0f,
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
                                 30.0f ) );
}

TEST_CASE( "Mat4f_ScalarVectorMultiplication" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB = 5.0f * matrixA;
    CHECK( matrixB == gm::Mat4f( 0.0f,
                                 10.0f,
                                 20.0f,
                                 30.0f,
                                 40.0f,
                                 50.0f,
                                 60.0f,
                                 70.0f,
                                 80.0f,
                                 90.0f,
                                 100.0f,
                                 110.0f,
                                 120.0f,
                                 130.0f,
                                 140.0f,
                                 150.0f ) );
}

TEST_CASE( "Mat4f_VectorScalarMultiplication" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    gm::Mat4f matrixB = matrixA * 5.0f;
    CHECK( matrixB == gm::Mat4f( 0.0f,
                                 10.0f,
                                 20.0f,
                                 30.0f,
                                 40.0f,
                                 50.0f,
                                 60.0f,
                                 70.0f,
                                 80.0f,
                                 90.0f,
                                 100.0f,
                                 110.0f,
                                 120.0f,
                                 130.0f,
                                 140.0f,
                                 150.0f ) );
}

TEST_CASE( "Mat4f_ScalarMultiplicationAssignment" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
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
    matrixA *= 5;
    CHECK( matrixA == gm::Mat4f( 0.0f,
                                 10.0f,
                                 20.0f,
                                 30.0f,
                                 40.0f,
                                 50.0f,
                                 60.0f,
                                 70.0f,
                                 80.0f,
                                 90.0f,
                                 100.0f,
                                 110.0f,
                                 120.0f,
                                 130.0f,
                                 140.0f,
                                 150.0f ) );
}

TEST_CASE( "Mat4f_VectorScalarDivision" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
                                   10.0f,
                                   20.0f,
                                   30.0f,
                                   40.0f,
                                   50.0f,
                                   60.0f,
                                   70.0f,
                                   80.0f,
                                   90.0f,
                                   100.0f,
                                   110.0f,
                                   120.0f,
                                   130.0f,
                                   140.0f,
                                   150.0f );
    gm::Mat4f matrixB = matrixA / 5.0f;
    CHECK( matrixB == gm::Mat4f( 0.0f,
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
                                 30.0f ) );
}

TEST_CASE( "Mat4f_ScalarDivisionAssignment" )
{
    gm::Mat4f matrixA = gm::Mat4f( 0.0f,
                                   10.0f,
                                   20.0f,
                                   30.0f,
                                   40.0f,
                                   50.0f,
                                   60.0f,
                                   70.0f,
                                   80.0f,
                                   90.0f,
                                   100.0f,
                                   110.0f,
                                   120.0f,
                                   130.0f,
                                   140.0f,
                                   150.0f );
    matrixA /= 5;
    CHECK( matrixA == gm::Mat4f( 0.0f,
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
                                 30.0f ) );
}

TEST_CASE( "Mat4f_Negation" )
{
    gm::Mat4f matrix = gm::Mat4f( 0.0f,
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
    CHECK( -matrix == gm::Mat4f( 0.0f,
                                 -2.0f,
                                 -4.0f,
                                 -6.0f,
                                 -8.0f,
                                 -10.0f,
                                 -12.0f,
                                 -14.0f,
                                 -16.0f,
                                 -18.0f,
                                 -20.0f,
                                 -22.0f,
                                 -24.0f,
                                 -26.0f,
                                 -28.0f,
                                 -30.0f ) );
}
