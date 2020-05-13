#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec4i.h>

TEST_CASE( "Vec4i_ElementReadAccess" )
{
    GM_NS::Vec4i vector( 0, 2, 4, 6 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
    CHECK( vector[ 3 ] == 6 );
}