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

TEST_CASE( "Vec2i_AdditionOperator" )
{
    gm::Vec2i vectorA( 0, 2 );
    gm::Vec2i vectorB( 0, 5 );
    gm::Vec2i vectorC = vectorA + vectorB;
    CHECK( vectorC[ 0 ] == 0 );
    CHECK( vectorC[ 1 ] == 7 );
}