//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/isIdentity.h>

TEST_CASE( "IsIdentity_Mat3f" )
{
    gm::Mat3f matrix;
    BENCHMARK( "IsIdentity" )
    {
        return gm::IsIdentity( matrix );
    };
}

TEST_CASE( "IsIdentity_Mat4f" )
{
    gm::Mat4f matrix;
    BENCHMARK( "IsIdentity" )
    {
        return gm::IsIdentity( matrix );
    };
}
