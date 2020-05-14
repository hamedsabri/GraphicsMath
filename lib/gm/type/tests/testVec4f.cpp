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

TEST_CASE( "Vec4f_AdditionOperator" )
{
    gm::Vec4f vectorA( 0, 2, 4, 6 );
    gm::Vec4f vectorB( 0, 5, 10, 15 );
    gm::Vec4f vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
    CHECK( vectorC[ 2 ] == 14 );
    CHECK( vectorC[ 3 ] == 21 );
}