#include <catch2/catch.hpp>

#include <gm/types/vec3i.h>

TEST_CASE( "Vec3i_DefaultConstructor" )
{
    gm::Vec3i vector;
    CHECK( vector == gm::Vec3i( 0, 0, 0 ) );
}

TEST_CASE( "Vec3i_CopyConstructor" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3i_CopyAssignmentConstructor" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3i_ElementReadAccess" )
{
    gm::Vec3i vector( 0, 2, 4 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
}

TEST_CASE( "Vec3i_ElementWriteAccess" )
{
    gm::Vec3i vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    vector[ 2 ] = 10;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
    CHECK( vector[ 2 ] == 10 );
}

TEST_CASE( "Vec3i_Addition" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( 0, 5, 10 );
    gm::Vec3i vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec3i( 0, 7, 14 ) );
}

TEST_CASE( "Vec3i_AdditionAssignment" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( 0, 5, 10 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec3i( 0, 7, 14 ) );
}

TEST_CASE( "Vec3i_Subtraction" )
{
    gm::Vec3i vectorA( 0, 7, 14 );
    gm::Vec3i vectorB( 0, 5, 10 );
    gm::Vec3i vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec3i( 0, 2, 4 ) );
}

TEST_CASE( "Vec3i_SubtractionAssignment" )
{
    gm::Vec3i vectorA( 0, 5, 10 );
    gm::Vec3i vectorB( 0, 7, 14 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec3i( 0, 2, 4 ) );
}

TEST_CASE( "Vec3i_ScalarVectorMultiplication" )
{
    gm::Vec3i vectorA( 0, 2, 4 );

    gm::Vec3i vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec3i( 0, 10, 20 ) );
}

TEST_CASE( "Vec3i_VectorScalarMultiplication" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec3i( 0, 10, 20 ) );
}

TEST_CASE( "Vec3i_ScalarMultiplicationAssignment" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec3i( 0, 10, 20 ) );
}

TEST_CASE( "Vec3i_VectorScalarDivision" )
{
    gm::Vec3i vectorA( 0, 10, 20 );
    gm::Vec3i vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec3i( 0, 2, 4 ) );
}

TEST_CASE( "Vec3i_ScalarDivisionAssignment" )
{
    gm::Vec3i vectorA( 0, 10, 20 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec3i( 0, 2, 4 ) );
}

TEST_CASE( "Vec3i_Negation" )
{
    gm::Vec3i vector( 0, 2, 4 );
    CHECK( -vector == gm::Vec3i( -0, -2, -4 ) );
}
