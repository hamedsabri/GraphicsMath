//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>
#include <gm/functions/setRotateX.h>
#include <gm/functions/setScale.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/transformAABB.h>

TEST_CASE( "TransformAABB_Vec3fRange" )
{
    gm::Mat4f      matrix;
    gm::Vec3fRange aabb( gm::Vec3f( 1, 1, 1 ), gm::Vec3f( 3, 3, 3 ) );

    // Translate.
    gm::SetIdentity( matrix );
    gm::SetTranslate( gm::Vec3f( 1, 2, 3 ), matrix );
    CHECK( gm::TransformAABB( matrix, aabb ) == gm::Vec3fRange( gm::Vec3f( 2, 3, 4 ), gm::Vec3f( 4, 5, 6 ) ) );

    // Rotation.
    gm::SetIdentity( matrix );
    gm::SetRotateX( 30, matrix );
    CHECK( gm::TransformAABB( matrix, aabb ) ==
           gm::Vec3fRange( gm::Vec3f( 1, -0.633975, 1.36603 ), gm::Vec3f( 3, 2.09808, 4.09808 ) ) );

    // Scale.
    gm::SetIdentity( matrix );
    gm::SetScale( gm::Vec3f( 2, 3, 4 ), matrix );
    CHECK( gm::TransformAABB( matrix, aabb ) == gm::Vec3fRange( gm::Vec3f( 2, 3, 4 ), gm::Vec3f( 6, 9, 12 ) ) );
}