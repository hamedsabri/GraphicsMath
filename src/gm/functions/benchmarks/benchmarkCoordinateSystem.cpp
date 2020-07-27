//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/coordinateSystem.h>

TEST_CASE( "CoordinateSystem_Vec3f_Vec3f_Vec3f" )
{
    gm::Vec3f vectorA;
    gm::Vec3f vectorB;
    gm::Vec3f vectorC;
    BENCHMARK( "CoordinateSystem" )
    {
        return gm::CoordinateSystem( vectorA, vectorB, vectorC );
    };
}
