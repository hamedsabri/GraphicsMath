#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/mat3f.h>

TEST_CASE( "Mat3f_DefaultConstructor" )
{
    gm::Mat3f matrix;
    CHECK( matrix == gm::Mat3f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f ) );
}

TEST_CASE( "Mat3f_CopyConstructor" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB( matrixA );
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat3f_CopyAssignmentConstructor" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB = matrixA;
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat3f_ElementReadAccess" )
{
    gm::Mat3f matrix( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    CHECK( matrix[ 0 ] == 0.0f );
    CHECK( matrix[ 1 ] == 2.0f );
    CHECK( matrix[ 2 ] == 4.0f );
    CHECK( matrix[ 3 ] == 6.0f );
    CHECK( matrix[ 4 ] == 8.0f );
    CHECK( matrix[ 5 ] == 10.0f );
    CHECK( matrix[ 6 ] == 12.0f );
    CHECK( matrix[ 7 ] == 14.0f );
    CHECK( matrix[ 8 ] == 16.0f );
}

TEST_CASE( "Mat3f_ElementWriteAccess" )
{
    gm::Mat3f matrix;
    matrix[ 0 ] = 0.0f;
    matrix[ 1 ] = 5.0f;
    matrix[ 2 ] = 10.0f;
    matrix[ 3 ] = 15.0f;
    matrix[ 4 ] = 20.0f;
    matrix[ 5 ] = 25.0f;
    matrix[ 6 ] = 30.0f;
    matrix[ 7 ] = 35.0f;
    matrix[ 8 ] = 40.0f;
    CHECK( matrix[ 0 ] == 0.0f );
    CHECK( matrix[ 1 ] == 5.0f );
    CHECK( matrix[ 2 ] == 10.0f );
    CHECK( matrix[ 3 ] == 15.0f );
    CHECK( matrix[ 4 ] == 20.0f );
    CHECK( matrix[ 5 ] == 25.0f );
    CHECK( matrix[ 6 ] == 30.0f );
    CHECK( matrix[ 7 ] == 35.0f );
    CHECK( matrix[ 8 ] == 40.0f );
}

TEST_CASE( "Mat3f_Addition" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB( 0.0f, 5.0f, 10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f );
    gm::Mat3f matrixC = matrixA + matrixB;
    CHECK( matrixC == gm::Mat3f( 0.0f, 7.0f, 14.0f, 21.0f, 28.0f, 35.0f, 42.0f, 49.0f, 56.0f ) );
}

TEST_CASE( "Mat3f_AdditionAssignment" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB( 0.0f, 5.0f, 10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f );
    matrixB += matrixA;
    CHECK( matrixB == gm::Mat3f( 0.0f, 7.0f, 14.0f, 21.0f, 28.0f, 35.0f, 42.0f, 49.0f, 56.0f ) );
}

TEST_CASE( "Mat3f_Subtraction" )
{
    gm::Mat3f matrixA( 0.0f, 7.0f, 14.0f, 21.0f, 28.0f, 35.0f, 42.0f, 49.0f, 56.0f );
    gm::Mat3f matrixB( 0.0f, 5.0f, 10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f );
    gm::Mat3f matrixC = matrixA - matrixB;
    CHECK( matrixC == gm::Mat3f( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f ) );
}

TEST_CASE( "Mat3f_SubtractionAssignment" )
{
    gm::Mat3f matrixA( 0.0f, 5.0f, 10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f );
    gm::Mat3f matrixB( 0.0f, 7.0f, 14.0f, 21.0f, 28.0f, 35.0f, 42.0f, 49.0f, 56.0f );
    matrixB -= matrixA;
    CHECK( matrixB == gm::Mat3f( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f ) );
}

TEST_CASE( "Mat3f_ScalarVectorMultiplication" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );

    gm::Mat3f matrixB = 5 * matrixA;
    CHECK( matrixB == gm::Mat3f( 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f ) );
}

TEST_CASE( "Mat3f_VectorScalarMultiplication" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    gm::Mat3f matrixB = matrixA * 5.0f;
    CHECK( matrixB == gm::Mat3f( 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f ) );
}

TEST_CASE( "Mat3f_ScalarMultiplicationAssignment" )
{
    gm::Mat3f matrixA( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    matrixA *= 5;
    CHECK( matrixA == gm::Mat3f( 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f ) );
}

TEST_CASE( "Mat3f_VectorScalarDivision" )
{
    gm::Mat3f matrixA( 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f );
    gm::Mat3f matrixB = matrixA / 5.0f;
    CHECK( matrixB == gm::Mat3f( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f ) );
}

TEST_CASE( "Mat3f_ScalarDivisionAssignment" )
{
    gm::Mat3f matrixA( 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f );
    matrixA /= 5;
    CHECK( matrixA == gm::Mat3f( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f ) );
}

TEST_CASE( "Mat3f_Negation" )
{
    gm::Mat3f matrix( 0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f );
    CHECK( -matrix == gm::Mat3f( -0.0f, -2.0f, -4.0f, -6.0f, -8.0f, -10.0f, -12.0f, -14.0f, -16.0f ) );
}
