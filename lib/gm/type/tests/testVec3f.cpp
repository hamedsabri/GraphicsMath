#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec3f.h>

TEST_CASE( "Vec3f_DefaultConstructor" )
{
    gm::Vec3f vector;
    CHECK( vector == gm::Vec3f( 0, 0, 0 ) );
}

TEST_CASE( "Vec3f_CopyConstructor" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3f_CopyAssignmentConstructor" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3f_ElementReadAccess" )
{
    gm::Vec3f vector( 0, 2, 4 );
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
}

TEST_CASE( "Vec3f_ElementWriteAccess" )
{
    gm::Vec3f vector;
    vector[ 0 ] = 0;
    vector[ 1 ] = 5;
    vector[ 2 ] = 10;
    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 5 );
    CHECK( vector[ 2 ] == 10 );
}

TEST_CASE( "Vec3f_Addition" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB( 0, 5, 10 );
    gm::Vec3f vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec3f( 0, 7, 14 ) );
}

TEST_CASE( "Vec3f_AdditionAssignment" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB( 0, 5, 10 );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec3f( 0, 7, 14 ) );
}

TEST_CASE( "Vec3f_Subtraction" )
{
    gm::Vec3f vectorA( 0, 7, 14 );
    gm::Vec3f vectorB( 0, 5, 10 );
    gm::Vec3f vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec3f( 0, 2, 4 ) );
}

TEST_CASE( "Vec3f_SubtractionAssignment" )
{
    gm::Vec3f vectorA( 0, 5, 10 );
    gm::Vec3f vectorB( 0, 7, 14 );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec3f( 0, 2, 4 ) );
}

TEST_CASE( "Vec3f_ScalarVectorMultiplication" )
{
    gm::Vec3f vectorA( 0, 2, 4 );

    gm::Vec3f vectorB = 5 * vectorA;
    CHECK( vectorB == gm::Vec3f( 0, 10, 20 ) );
}

TEST_CASE( "Vec3f_VectorScalarMultiplication" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB = vectorA * 5;
    CHECK( vectorB == gm::Vec3f( 0, 10, 20 ) );
}

TEST_CASE( "Vec3f_ScalarMultiplicationAssignment" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec3f( 0, 10, 20 ) );
}

TEST_CASE( "Vec3f_VectorScalarDivision" )
{
    gm::Vec3f vectorA( 0, 10, 20 );
    gm::Vec3f vectorB = vectorA / 5;
    CHECK( vectorB == gm::Vec3f( 0, 2, 4 ) );
}

TEST_CASE( "Vec3f_ScalarDivisionAssignment" )
{
    gm::Vec3f vectorA( 0, 10, 20 );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec3f( 0, 2, 4 ) );
}
