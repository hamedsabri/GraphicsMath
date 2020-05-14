#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec2i.h>

TEST_CASE( "Vec2i_DefaultConstructor" )
{
    gm::Vec2i vector;
    CHECK( vector == gm::Vec2i( 0, 0 ) );
}

TEST_CASE( "Vec2i_CopyConstructor" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec2i_CopyAssignmentConstructor" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec2i_ElementReadAccess" )
{
    gm::Vec2i vector( 0, 2 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
}

TEST_CASE( "Vec2i_ElementWriteAccess" )
{
    gm::Vec2i vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
}

TEST_CASE( "Vec2i_Addition" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( 0, 5 );
    gm::Vec2i vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec2i( 0, 7 ) );
}

TEST_CASE( "Vec2i_AdditionAssignment" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( 0, 5 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec2i( 0, 7 ) );
}

TEST_CASE( "Vec2i_Subtraction" )
{
    gm::Vec2i vectorA( 0, 7 );
    gm::Vec2i vectorB( 0, 5 );
    gm::Vec2i vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec2i( 0, 2 ) );
}

TEST_CASE( "Vec2i_SubtractionAssignment" )
{
    gm::Vec2i vectorA( 0, 5 );
    gm::Vec2i vectorB( 0, 7 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec2i( 0, 2 ) );
}

TEST_CASE( "Vec2i_ScalarVectorMultiplication" )
{
    gm::Vec2i vectorA( 0, 2 );

    gm::Vec2i vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec2i( 0, 10 ) );
}

TEST_CASE( "Vec2i_VectorScalarMultiplication" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec2i( 0, 10 ) );
}

TEST_CASE( "Vec2i_ScalarMultiplicationAssignment" )
{
    gm::Vec2i vectorA( 0, 2 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec2i( 0, 10 ) );
}

TEST_CASE( "Vec2i_VectorScalarDivision" )
{
    gm::Vec2i vectorA( 0, 10 );
    gm::Vec2i vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec2i( 0, 2 ) );
}

TEST_CASE( "Vec2i_ScalarDivisionAssignment" )
{
    gm::Vec2i vectorA( 0, 10 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec2i( 0, 2 ) );
}

TEST_CASE( "Vec2i_Negation" )
{
    gm::Vec2i vector( 0, 2 );

    CHECK( -vector == gm::Vec2i( -0, -2 ) );
}
