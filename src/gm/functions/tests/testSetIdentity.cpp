#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>

TEST_CASE( "SetIdentity_Mat3f" )
{
    gm::Mat3f matrix;
    gm::SetIdentity( matrix );
    CHECK( matrix == gm::Mat3f( 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "SetIdentity_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    CHECK( matrix == gm::Mat4f( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}
