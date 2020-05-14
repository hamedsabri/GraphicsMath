#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec4f.h>

TEST_CASE( "Vec4f_DefaultConstructor" )
{
    gm::Vec4f vector;
    CHECK( vector == gm::Vec4f( 0, 0, 0, 0 ) );
}

TEST_CASE( "Vec4f_CopyConstructor" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4f_CopyAssignmentConstructor" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4f_ElementReadAccess" )
{
    gm::Vec4f vector( 0, 2, 4, 6 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
    CHECK( vector[ 3 ] == 6 );
}

TEST_CASE( "Vec4f_ElementWriteAccess" )
{
    gm::Vec4f vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    vector[ 2 ] = 10;
    vector[ 3 ] = 15;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
    CHECK( vector[ 2 ] == 10 );
    CHECK( vector[ 3 ] == 15 );
}

TEST_CASE( "Vec4f_Addition" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB( 0, 5, 10, 15 );
    gm::Vec4f vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec4f( 0, 7, 14, 21 ) );
}

TEST_CASE( "Vec4f_AdditionAssignment" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB( 0, 5, 10, 15 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec4f( 0, 7, 14, 21 ) );
}

TEST_CASE( "Vec4f_Subtraction" )
{
    gm::Vec4f vectorA( 0, 7, 14, 21 );
    gm::Vec4f vectorB( 0, 5, 10, 15 );
    gm::Vec4f vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec4f( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4f_SubtractionAssignment" )
{
    gm::Vec4f vectorA( 0, 5, 10, 15 );
    gm::Vec4f vectorB( 0, 7, 14, 21 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec4f( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4f_ScalarVectorMultiplication" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );

    gm::Vec4f vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec4f( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4f_VectorScalarMultiplication" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec4f( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4f_ScalarMultiplicationAssignment" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec4f( 0, 10, 20, 30 ) );
}

TEST_CASE( "Vec4f_VectorScalarDivision" )
{
    gm::Vec4f vectorA( 0, 10, 20, 30 );
    gm::Vec4f vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec4f( 0, 2, 4, 6 ) );
}

TEST_CASE( "Vec4f_ScalarDivisionAssignment" )
{
    gm::Vec4f vectorA( 0, 10, 20, 30 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec4f( 0, 2, 4, 6 ) );
}
