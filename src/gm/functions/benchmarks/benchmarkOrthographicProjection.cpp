//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/orthographicProjection.h>

TEST_CASE( "OrthographicProjection_Vec3fRange" )
{
    gm::Vec3fRange viewingVolume;
    BENCHMARK( "OrthographicProjection" )
    {
        return gm::OrthographicProjection( viewingVolume );
    };
}
