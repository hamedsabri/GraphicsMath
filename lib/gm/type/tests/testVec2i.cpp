#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <gm/type/vec2i.h>

TEST_CASE( "Vec2i_ElementReadAccess" )
{
    GM_NS::Vec2i vector( 0, 2 );

    CHECK( vector[ 0 ] == 0 );
    CHECK( vector[ 1 ] == 2 );
}