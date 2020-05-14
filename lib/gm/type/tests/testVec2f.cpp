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

TEST_CASE( "Vec2f_AdditionOperator" )
{
    gm::Vec2f vectorA( 0, 2 );
    gm::Vec2f vectorB( 0, 5 );
    gm::Vec2f vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
}