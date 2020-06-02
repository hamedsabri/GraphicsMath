//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>

TEST_CASE( "SetIdentity_Mat3f" )
{
    gm::Mat3f matrix;
    BENCHMARK( "SetIdentity" )
    {
        return gm::SetIdentity( matrix );
    };
}

TEST_CASE( "SetIdentity_Mat4f" )
{
    gm::Mat4f matrix;
    BENCHMARK( "SetIdentity" )
    {
        return gm::SetIdentity( matrix );
    };
}
