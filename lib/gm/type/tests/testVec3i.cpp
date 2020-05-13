#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec3i.h>

TEST_CASE( "Vec3i_ElementReadAccess" )
{
    GM_NS::Vec3i vector( 0, 2, 4 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
    CHECK( vector[ 2 ] == 4 );
}