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

TEST_CASE( "Vec4i_AdditionOperator" )
{
    gm::Vec4i vectorA( 0, 2, 4, 6 );
    gm::Vec4i vectorB( 0, 5, 10, 15 );
    gm::Vec4i vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
    CHECK( vectorC[ 2 ] == 14 );
    CHECK( vectorC[ 3 ] == 21 );
}