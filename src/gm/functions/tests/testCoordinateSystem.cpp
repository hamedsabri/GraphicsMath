//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/coordinateSystem.h>

TEST_CASE( "CoordinateSystem_Vec3f" )
{
    gm::Vec3f vectorA( 1.0, 0.0, 0.0 );
    gm::Vec3f vectorB, vectorC;
    gm::CoordinateSystem( vectorA, vectorB, vectorC );
    CHECK( vectorB == gm::Vec3f( 0.0, 0.0, 1.0 ) );
    CHECK( vectorC == gm::Vec3f( 0.0, -1.0, 0.0 ) );
}
