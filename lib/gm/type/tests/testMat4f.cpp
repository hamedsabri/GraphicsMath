#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/mat4f.h>

TEST_CASE( "Mat4f_ElementReadAccess" )
{
    gm::Mat4f vector( 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
    CHECK( vector[ 3 ] == 6 );
    CHECK( vector[ 4 ] == 8 );
    CHECK( vector[ 5 ] == 10 );
    CHECK( vector[ 6 ] == 12 );
    CHECK( vector[ 7 ] == 14 );
    CHECK( vector[ 8 ] == 16 );
    CHECK( vector[ 9 ] == 18 );
    CHECK( vector[ 10 ] == 20 );
    CHECK( vector[ 11 ] == 22 );
    CHECK( vector[ 12 ] == 24 );
    CHECK( vector[ 13 ] == 26 );
    CHECK( vector[ 14 ] == 28 );
    CHECK( vector[ 15 ] == 30 );
}