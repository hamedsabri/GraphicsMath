#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec3f.h>

TEST_CASE( "Vec3f_ElementReadAccess" )
{
    GM_NS::Vec3f vector( 0, 2, 4 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
}