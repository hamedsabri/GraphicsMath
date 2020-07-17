//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/trilinearInterpolation.h>

TEST_CASE( "TrilinearInterpolation_float" )
{
    float corner000 = 0.0f;
    float corner100 = 2.0f;
    float corner010 = 3.0f;
    float corner110 = 5.0f;

    float corner001 = 1.0f;
    float corner101 = 3.0f;
    float corner011 = 4.0f;
    float corner111 = 6.0f;

    float result = gm::TrilinearInterpolation( corner000,
                                               corner100,
                                               corner010,
                                               corner110,
                                               corner001,
                                               corner101,
                                               corner011,
                                               corner111,
                                               gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK( result == 3.0f );
}

TEST_CASE( "TrilinearInterpolation_Mat3f" )
{
    gm::Mat3f corner000 = gm::Mat3f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat3f corner100 = gm::Mat3f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat3f corner010 = gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat3f corner110 = gm::Mat3f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat3f corner001 = gm::Mat3f( 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Mat3f corner101 = gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat3f corner011 = gm::Mat3f( 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Mat3f corner111 = gm::Mat3f( 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Mat3f result = gm::TrilinearInterpolation( corner000,
                                                   corner100,
                                                   corner010,
                                                   corner110,
                                                   corner001,
                                                   corner101,
                                                   corner011,
                                                   corner111,
                                                   gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK( result == gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Mat4f" )
{
    gm::Mat4f corner000 =
        gm::Mat4f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat4f corner100 =
        gm::Mat4f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat4f corner010 =
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat4f corner110 =
        gm::Mat4f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat4f corner001 =
        gm::Mat4f( 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Mat4f corner101 =
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat4f corner011 =
        gm::Mat4f( 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Mat4f corner111 =
        gm::Mat4f( 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Mat4f result = gm::TrilinearInterpolation( corner000,
                                                   corner100,
                                                   corner010,
                                                   corner110,
                                                   corner001,
                                                   corner101,
                                                   corner011,
                                                   corner111,
                                                   gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK(
        result ==
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec2f" )
{
    gm::Vec2f corner000 = gm::Vec2f( 0.0f, 0.0f );
    gm::Vec2f corner100 = gm::Vec2f( 2.0f, 2.0f );
    gm::Vec2f corner010 = gm::Vec2f( 3.0f, 3.0f );
    gm::Vec2f corner110 = gm::Vec2f( 5.0f, 5.0f );

    gm::Vec2f corner001 = gm::Vec2f( 1.0f, 1.0f );
    gm::Vec2f corner101 = gm::Vec2f( 3.0f, 3.0f );
    gm::Vec2f corner011 = gm::Vec2f( 4.0f, 4.0f );
    gm::Vec2f corner111 = gm::Vec2f( 6.0f, 6.0f );

    gm::Vec2f result = gm::TrilinearInterpolation( corner000,
                                                   corner100,
                                                   corner010,
                                                   corner110,
                                                   corner001,
                                                   corner101,
                                                   corner011,
                                                   corner111,
                                                   gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK( result == gm::Vec2f( 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec3f" )
{
    gm::Vec3f corner000 = gm::Vec3f( 0.0f, 0.0f, 0.0f );
    gm::Vec3f corner100 = gm::Vec3f( 2.0f, 2.0f, 2.0f );
    gm::Vec3f corner010 = gm::Vec3f( 3.0f, 3.0f, 3.0f );
    gm::Vec3f corner110 = gm::Vec3f( 5.0f, 5.0f, 5.0f );

    gm::Vec3f corner001 = gm::Vec3f( 1.0f, 1.0f, 1.0f );
    gm::Vec3f corner101 = gm::Vec3f( 3.0f, 3.0f, 3.0f );
    gm::Vec3f corner011 = gm::Vec3f( 4.0f, 4.0f, 4.0f );
    gm::Vec3f corner111 = gm::Vec3f( 6.0f, 6.0f, 6.0f );

    gm::Vec3f result = gm::TrilinearInterpolation( corner000,
                                                   corner100,
                                                   corner010,
                                                   corner110,
                                                   corner001,
                                                   corner101,
                                                   corner011,
                                                   corner111,
                                                   gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK( result == gm::Vec3f( 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec4f" )
{
    gm::Vec4f corner000 = gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Vec4f corner100 = gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Vec4f corner010 = gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Vec4f corner110 = gm::Vec4f( 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Vec4f corner001 = gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Vec4f corner101 = gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Vec4f corner011 = gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Vec4f corner111 = gm::Vec4f( 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Vec4f result = gm::TrilinearInterpolation( corner000,
                                                   corner100,
                                                   corner010,
                                                   corner110,
                                                   corner001,
                                                   corner101,
                                                   corner011,
                                                   corner111,
                                                   gm::Vec3f( 0.5, 0.5, 0.5 ) );

    CHECK( result == gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f ) );
}
