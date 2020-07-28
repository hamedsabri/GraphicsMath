//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/faceForward.h>

TEST_CASE( "FaceForward_Vec2f" )
{
    gm::Vec2f normal = gm::Vec2f( 0.0f, 1.0f );
    CHECK( gm::FaceForward( normal, gm::Vec2f( 2.0f, 2.0f ) ) == normal );
    CHECK( gm::FaceForward( normal, gm::Vec2f( -2.0f, -2.0f ) ) == -normal );
}

TEST_CASE( "FaceForward_Vec3f" )
{
    gm::Vec3f normal = gm::Vec3f( 0.0f, 1.0f, 2.0f );
    CHECK( gm::FaceForward( normal, gm::Vec3f( 2.0f, 2.0f, 2.0f ) ) == normal );
    CHECK( gm::FaceForward( normal, gm::Vec3f( -2.0f, -2.0f, -2.0f ) ) == -normal );
}

TEST_CASE( "FaceForward_Vec4f" )
{
    gm::Vec4f normal = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    CHECK( gm::FaceForward( normal, gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f ) ) == normal );
    CHECK( gm::FaceForward( normal, gm::Vec4f( -2.0f, -2.0f, -2.0f, -2.0f ) ) == -normal );
}
