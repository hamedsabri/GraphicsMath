//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/crossProduct.h>

TEST_CASE( "CrossProduct_Vec3f" )
{
    gm::Vec3f vectorA( 1.0, 0.5, 2.0 );
    gm::Vec3f vectorB( 2.0, 5.0, 2.5 );
    gm::Vec3f res = gm::CrossProduct( vectorA, vectorB );
    CHECK( res.X() == Approx( -8.75f ) );
    CHECK( res.Y() == Approx( 1.5f ) );
    CHECK( res.Z() == Approx( 4.0f ) );
}
