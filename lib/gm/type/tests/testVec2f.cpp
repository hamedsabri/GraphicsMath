#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec2f.h>

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