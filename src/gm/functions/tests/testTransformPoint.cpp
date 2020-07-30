//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/setIdentity.h>
#include <gm/functions/setRotateX.h>
#include <gm/functions/setScale.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/transformPoint.h>

TEST_CASE( "TransformPoint_Vec3f" )
{
    gm::Mat4f matrix;
    gm::Vec3f point( 2, 4, 6 );

    // Translate.
    gm::SetIdentity( matrix );
    gm::SetTranslate( gm::Vec3f( 1, 2, 3 ), matrix );
    CHECK( gm::TransformPoint( matrix, point ) == gm::Vec3f( 3, 6, 9 ) );

    // Rotation.
    gm::SetIdentity( matrix );
    gm::SetRotateX( 30, matrix );
    CHECK( gm::TransformPoint( matrix, point ) == gm::Vec3f( 2, 0.464102, 7.19615 ) );

    // Scale.
    gm::SetIdentity( matrix );
    gm::SetScale( gm::Vec3f( 2, 3, 4 ), matrix );
    CHECK( gm::TransformPoint( matrix, point ) == gm::Vec3f( 4, 12, 24 ) );
}