//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/lookAt.h>

TEST_CASE( "LookAt_Vec3f_Vec3f_Vec3f" )
{
    gm::Vec3f position;
    gm::Vec3f look;
    gm::Vec3f up;
    BENCHMARK( "LookAt" )
    {
        return gm::LookAt( position, look, up );
    };
}
