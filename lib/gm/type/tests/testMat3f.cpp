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

TEST_CASE( "Mat3f_AdditionOperator" )
{
    gm::Mat3f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16 );
    gm::Mat3f matrixB( 0, 5, 10, 15, 20, 25, 30, 35, 40 );
    gm::Mat3f matrixC = matrixA + matrixB;
    CHECK( matrixC[ 0 ] == 0 );
    CHECK( matrixC[ 1 ] == 7 );
    CHECK( matrixC[ 2 ] == 14 );
    CHECK( matrixC[ 3 ] == 21 );
    CHECK( matrixC[ 4 ] == 28 );
    CHECK( matrixC[ 5 ] == 35 );
    CHECK( matrixC[ 6 ] == 42 );
    CHECK( matrixC[ 7 ] == 49 );
    CHECK( matrixC[ 8 ] == 56 );
}