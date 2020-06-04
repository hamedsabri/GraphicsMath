#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>
#include <gm/functions/isIdentity.h>

TEST_CASE( "IsIdentity_Mat3f" )
{
    gm::Mat3f matrix;
    gm::SetIdentity( matrix );
    CHECK( gm::IsIdentity( matrix ) );
}

TEST_CASE( "IsIdentity_Mat4f" )
{
    gm::Mat4f matrix;
    gm::SetIdentity( matrix );
    CHECK( gm::IsIdentity( matrix ) );
}
