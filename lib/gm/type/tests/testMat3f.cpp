#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/mat3f.h>

TEST_CASE( "Mat3f_DefaultConstructor" )
{
    gm::Mat3f matrix;
    CHECK( matrix == gm::Mat3f( 0, 0, 0, 0, 0, 0, 0, 0, 0 ) );
}

TEST_CASE( "Mat3f_CopyConstructor" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB( matrixA );
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat3f_CopyAssignmentConstructor" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB = matrixA;
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat3f_ElementReadAccess" )
{
    gm::Mat3f matrix( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    CHECK( matrix[ 0 ] == 0 );
    CHECK( matrix[ 1 ] == 2 );
    CHECK( matrix[ 2 ] == 4 );
    CHECK( matrix[ 3 ] == 6 );
    CHECK( matrix[ 4 ] == 8 );
    CHECK( matrix[ 5 ] == 10 );
    CHECK( matrix[ 6 ] == 12 );
    CHECK( matrix[ 7 ] == 14 );
    CHECK( matrix[ 8 ] == 16 );
}

TEST_CASE( "Mat3f_ElementWriteAccess" )
{
    gm::Mat3f matrix;
    matrix[ 0 ] = 0;
    matrix[ 1 ] = 5;
    matrix[ 2 ] = 10;
    matrix[ 3 ] = 15;
    matrix[ 4 ] = 20;
    matrix[ 5 ] = 25;
    matrix[ 6 ] = 30;
    matrix[ 7 ] = 35;
    matrix[ 8 ] = 40;
    CHECK( matrix[ 0 ] == 0 );
    CHECK( matrix[ 1 ] == 5 );
    CHECK( matrix[ 2 ] == 10 );
    CHECK( matrix[ 3 ] == 15 );
    CHECK( matrix[ 4 ] == 20 );
    CHECK( matrix[ 5 ] == 25 );
    CHECK( matrix[ 6 ] == 30 );
    CHECK( matrix[ 7 ] == 35 );
    CHECK( matrix[ 8 ] == 40 );
}

TEST_CASE( "Mat3f_Addition" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB( 0, 5, 10, 15, 20, 25, 30, 35, 40 );
    gm::Mat3f matrixC = matrixA + matrixB;
    CHECK( matrixC == gm::Mat3f( 0, 7, 14, 21, 28, 35, 42, 49, 56 ) );
}

TEST_CASE( "Mat3f_AdditionAssignment" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB( 0, 5, 10, 15, 20, 25, 30, 35, 40 );
    matrixB += matrixA;
    CHECK( matrixB == gm::Mat3f( 0, 7, 14, 21, 28, 35, 42, 49, 56 ) );
}

TEST_CASE( "Mat3f_Subtraction" )
{
    gm::Mat3f matrixA( 0, 7, 14, 21, 28, 35, 42, 49, 56 );
    gm::Mat3f matrixB( 0, 5, 10, 15, 20, 25, 30, 35, 40 );
    gm::Mat3f matrixC = matrixA - matrixB;
    CHECK( matrixC == gm::Mat3f( 0, 2, 4, 6, 8, 10, 12, 14, 16 ) );
}

TEST_CASE( "Mat3f_SubtractionAssignment" )
{
    gm::Mat3f matrixA( 0, 5, 10, 15, 20, 25, 30, 35, 40 );
    gm::Mat3f matrixB( 0, 7, 14, 21, 28, 35, 42, 49, 56 );
    matrixB -= matrixA;
    CHECK( matrixB == gm::Mat3f( 0, 2, 4, 6, 8, 10, 12, 14, 16 ) );
}

TEST_CASE( "Mat3f_ScalarVectorMultiplication" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );

    gm::Mat3f matrixB = 5 * matrixA;
    CHECK( matrixB == gm::Mat3f( 0, 10, 20, 30, 40, 50, 60, 70, 80 ) );
}

TEST_CASE( "Mat3f_VectorScalarMultiplication" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB = matrixA * 5;
    CHECK( matrixB == gm::Mat3f( 0, 10, 20, 30, 40, 50, 60, 70, 80 ) );
}

TEST_CASE( "Mat3f_ScalarMultiplicationAssignment" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    matrixA *= 5;
    CHECK( matrixA == gm::Mat3f( 0, 10, 20, 30, 40, 50, 60, 70, 80 ) );
}

TEST_CASE( "Mat3f_VectorScalarDivision" )
{
    gm::Mat3f matrixA( 0, 10, 20, 30, 40, 50, 60, 70, 80 );
    gm::Mat3f matrixB = matrixA / 5;
    CHECK( matrixB == gm::Mat3f( 0, 2, 4, 6, 8, 10, 12, 14, 16 ) );
}

TEST_CASE( "Mat3f_ScalarDivisionAssignment" )
{
    gm::Mat3f matrixA( 0, 10, 20, 30, 40, 50, 60, 70, 80 );
    matrixA /= 5;
    CHECK( matrixA == gm::Mat3f( 0, 2, 4, 6, 8, 10, 12, 14, 16 ) );
}
