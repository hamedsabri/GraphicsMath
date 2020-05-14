#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/mat4f.h>

TEST_CASE( "Mat4f_DefaultConstructor" )
{
    gm::Mat4f matrix;
    CHECK( matrix == gm::Mat4f( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ) );
}

TEST_CASE( "Mat4f_CopyConstructor" )
{
    gm::Mat4f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 );
    gm::Mat4f matrixB( matrixA );
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat4f_CopyAssignmentConstructor" )
{
    gm::Mat4f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 );
    gm::Mat4f matrixB = matrixA;
    CHECK( matrixA == matrixB );
}

TEST_CASE( "Mat4f_ElementReadAccess" )
{
    gm::Mat4f matrix( 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 );
    CHECK( matrix[ 0 ] == 0 );
    CHECK( matrix[ 1 ] == 2 );
    CHECK( matrix[ 2 ] == 4 );
    CHECK( matrix[ 3 ] == 6 );
    CHECK( matrix[ 4 ] == 8 );
    CHECK( matrix[ 5 ] == 10 );
    CHECK( matrix[ 6 ] == 12 );
    CHECK( matrix[ 7 ] == 14 );
    CHECK( matrix[ 8 ] == 16 );
    CHECK( matrix[ 9 ] == 18 );
    CHECK( matrix[ 10 ] == 20 );
    CHECK( matrix[ 11 ] == 22 );
    CHECK( matrix[ 12 ] == 24 );
    CHECK( matrix[ 13 ] == 26 );
    CHECK( matrix[ 14 ] == 28 );
    CHECK( matrix[ 15 ] == 30 );
}

TEST_CASE( "Mat4f_ElementWriteAccess" )
{
    gm::Mat4f matrix;
    matrix[ 0 ]  = 0;
    matrix[ 1 ]  = 5;
    matrix[ 2 ]  = 10;
    matrix[ 3 ]  = 15;
    matrix[ 4 ]  = 20;
    matrix[ 5 ]  = 25;
    matrix[ 6 ]  = 30;
    matrix[ 7 ]  = 35;
    matrix[ 8 ]  = 40;
    matrix[ 9 ]  = 45;
    matrix[ 10 ] = 50;
    matrix[ 11 ] = 55;
    matrix[ 12 ] = 60;
    matrix[ 13 ] = 65;
    matrix[ 14 ] = 70;
    matrix[ 15 ] = 75;
    CHECK( matrix[ 0 ] == 0 );
    CHECK( matrix[ 1 ] == 5 );
    CHECK( matrix[ 2 ] == 10 );
    CHECK( matrix[ 3 ] == 15 );
    CHECK( matrix[ 4 ] == 20 );
    CHECK( matrix[ 5 ] == 25 );
    CHECK( matrix[ 6 ] == 30 );
    CHECK( matrix[ 7 ] == 35 );
    CHECK( matrix[ 8 ] == 40 );
    CHECK( matrix[ 9 ] == 45 );
    CHECK( matrix[ 10 ] == 50 );
    CHECK( matrix[ 11 ] == 55 );
    CHECK( matrix[ 12 ] == 60 );
    CHECK( matrix[ 13 ] == 65 );
    CHECK( matrix[ 14 ] == 70 );
    CHECK( matrix[ 15 ] == 75 );
}

TEST_CASE( "Mat4f_AdditionOperator" )
{
    gm::Mat4f matrixA( 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 );
    gm::Mat4f matrixB( 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 );
    gm::Mat4f matrixC = matrixA + matrixB;
    CHECK( matrixC[ 0 ] == 0 );
    CHECK( matrixC[ 1 ] == 7 );
    CHECK( matrixC[ 2 ] == 14 );
    CHECK( matrixC[ 3 ] == 21 );
    CHECK( matrixC[ 4 ] == 28 );
    CHECK( matrixC[ 5 ] == 35 );
    CHECK( matrixC[ 6 ] == 42 );
    CHECK( matrixC[ 7 ] == 49 );
    CHECK( matrixC[ 8 ] == 56 );
    CHECK( matrixC[ 9 ] == 63 );
    CHECK( matrixC[ 10 ] == 70 );
    CHECK( matrixC[ 11 ] == 77 );
    CHECK( matrixC[ 12 ] == 84 );
    CHECK( matrixC[ 13 ] == 91 );
    CHECK( matrixC[ 14 ] == 98 );
    CHECK( matrixC[ 15 ] == 105 );
}