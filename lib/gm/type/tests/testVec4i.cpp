#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec4i.h>

TEST_CASE( "Vec4i_DefaultConstructor" )
{
    gm::Vec4i vector;
    CHECK( vector == gm::Vec4i( 0, 0, 0, 0 ) );
}

TEST_CASE( "Vec4i_CopyConstructor" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4i_CopyAssignmentConstructor" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4i_ElementReadAccess" )
{
    gm::Vec4i vector( 0, 2, 4, 6 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
    CHECK( vector[ 3 ] == 6 );
}

TEST_CASE( "Vec4i_ElementWriteAccess" )
{
    gm::Vec4i vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    vector[ 2 ] = 10;
    vector[ 3 ] = 15;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
    CHECK( vector[ 2 ] == 10 );
    CHECK( vector[ 3 ] == 15 );
}

TEST_CASE( "Vec4i_Addition" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( 0, 5, 10, 15 );
    gm::Vec4i vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec4i( 0, 7, 14, 21 ) );
}

TEST_CASE( "Vec4i_AdditionAssignment" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( 0, 5, 10, 15 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec4i( 0, 7, 14, 21 ) );
}

TEST_CASE( "Vec4i_Subtraction" )
{
    gm::Vec4i vectorA( 0, 7, 14, 21 );
    gm::Vec4i vectorB( 0, 5, 10, 15 );
    gm::Vec4i vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec4i( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4i_SubtractionAssignment" )
{
    gm::Vec4i vectorA( 0, 5, 10, 15 );
    gm::Vec4i vectorB( 0, 7, 14, 21 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec4i( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4i_ScalarVectorMultiplication" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );

    gm::Vec4i vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec4i( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4i_VectorScalarMultiplication" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec4i( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4i_ScalarMultiplicationAssignment" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec4i( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4i_VectorScalarDivision" )
{
    gm::Vec4i vectorA( 0, 10, 20, 30 );
    gm::Vec4i vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec4i( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4i_ScalarDivisionAssignment" )
{
    gm::Vec4i vectorA( 0, 10, 20, 30 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec4i( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4i_Negation" )
{
    gm::Vec4i vector( 0, 2, 4, 6 );

    CHECK( -vector == gm::Vec4i( -0, -2, -4, -6 ) );
}
