#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec2f.h>

TEST_CASE( "Vec2f_DefaultConstructor" )
{
    gm::Vec2f vector;
    CHECK( vector == gm::Vec2f( 0, 0 ) );
}

TEST_CASE( "Vec2f_CopyConstructor" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec2f_CopyAssignmentConstructor" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec2f_ElementReadAccess" )
{
    gm::Vec2f vector( 0, 2 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
}

TEST_CASE( "Vec2f_ElementWriteAccess" )
{
    gm::Vec2f vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
}

TEST_CASE( "Vec2f_Addition" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB( 0, 5 );
    gm::Vec2f vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec2f( 0, 7 ) );
}

TEST_CASE( "Vec2f_AdditionAssignment" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB( 0, 5 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec2f( 0, 7 ) );
}

TEST_CASE( "Vec2f_Subtraction" )
{
    gm::Vec2f vectorA( 0, 7 );
    gm::Vec2f vectorB( 0, 5 );
    gm::Vec2f vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec2f( 0, 2 ) );
}

TEST_CASE( "Vec2f_SubtractionAssignment" )
{
    gm::Vec2f vectorA( 0, 5 );
    gm::Vec2f vectorB( 0, 7 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec2f( 0, 2 ) );
}

TEST_CASE( "Vec2f_ScalarVectorMultiplication" )
{
    gm::Vec2f vectorA( 0, 2 );

    gm::Vec2f vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec2f( 0, 10 ) );
}

TEST_CASE( "Vec2f_VectorScalarMultiplication" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec2f( 0, 10 ) );
}

TEST_CASE( "Vec2f_ScalarMultiplicationAssignment" )
{
    gm::Vec2f vectorA( 0, 2 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec2f( 0, 10 ) );
}

TEST_CASE( "Vec2f_VectorScalarDivision" )
{
    gm::Vec2f vectorA( 0, 10 );
    gm::Vec2f vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec2f( 0, 2 ) );
}

TEST_CASE( "Vec2f_ScalarDivisionAssignment" )
{
    gm::Vec2f vectorA( 0, 10 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec2f( 0, 2 ) );
}
