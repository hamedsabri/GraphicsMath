#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec3i.h>

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

TEST_CASE( "Vec3i_AdditionOperator" )
{
    gm::Vec3i vectorA( 0, 2, 4 );
    gm::Vec3i vectorB( 0, 5, 10 );
    gm::Vec3i vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
    CHECK( vectorC[ 2 ] == 14 );
}