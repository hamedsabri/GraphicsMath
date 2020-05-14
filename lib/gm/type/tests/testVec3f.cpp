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

TEST_CASE( "Vec3f_AdditionOperator" )
{
    gm::Vec3f vectorA( 0, 2, 4 );
    gm::Vec3f vectorB( 0, 5, 10 );
    gm::Vec3f vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
    CHECK( vectorC[ 2 ] == 14 );
}