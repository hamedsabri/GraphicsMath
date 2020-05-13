#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/mat3f.h>

TEST_CASE( "Mat3f_ElementReadAccess" )
{
    gm::Mat3f vector( 0, 2, 4, 6, 8, 10, 12, 14, 16 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
    CHECK( vector[ 3 ] == 6 );
    CHECK( vector[ 4 ] == 8 );
    CHECK( vector[ 5 ] == 10 );
    CHECK( vector[ 6 ] == 12 );
    CHECK( vector[ 7 ] == 14 );
    CHECK( vector[ 8 ] == 16 );
}