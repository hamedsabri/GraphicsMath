//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/bilinearInterpolation.h>

TEST_CASE( "BilinearInterpolation_float" )
{
    float value00 = 0.0f;
    float value01 = 2.0f;
    float value10 = 3.0f;
    float value11 = 5.0f;

    float result = gm::BilinearInterpolation( value00,
                                              value01,
                                              value10,
                                              value11,
                                              /* weightX */ 0.5,
                                              /* weightY */ 0.5 );

    CHECK( result == 2.5f );
}

TEST_CASE( "BilinearInterpolation_Mat3f" )
{
    gm::Mat3f value00 = gm::Mat3f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat3f value01 = gm::Mat3f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat3f value10 = gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat3f value11 = gm::Mat3f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat3f result = gm::BilinearInterpolation( value00,
                                                  value01,
                                                  value10,
                                                  value11,
                                                  /* weightX */ 0.5,
                                                  /* weightY */ 0.5 );

    CHECK( result == gm::Mat3f( 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f ) );
}

TEST_CASE( "BilinearInterpolation_Mat4f" )
{
    gm::Mat4f value00 =
        gm::Mat4f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat4f value01 =
        gm::Mat4f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat4f value10 =
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat4f value11 =
        gm::Mat4f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat4f result = gm::BilinearInterpolation( value00,
                                                  value01,
                                                  value10,
                                                  value11,
                                                  /* weightX */ 0.5,
                                                  /* weightY */ 0.5 );

    CHECK(
        result ==
        gm::Mat4f( 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f ) );
}

TEST_CASE( "BilinearInterpolation_Vec2f" )
{
    gm::Vec2f value00 = gm::Vec2f( 0.0f, 0.0f );
    gm::Vec2f value01 = gm::Vec2f( 2.0f, 2.0f );
    gm::Vec2f value10 = gm::Vec2f( 3.0f, 3.0f );
    gm::Vec2f value11 = gm::Vec2f( 5.0f, 5.0f );

    gm::Vec2f result = gm::BilinearInterpolation( value00,
                                                  value01,
                                                  value10,
                                                  value11,
                                                  /* weightX */ 0.5,
                                                  /* weightY */ 0.5 );

    CHECK( result == gm::Vec2f( 2.5f, 2.5f ) );
}

TEST_CASE( "BilinearInterpolation_Vec3f" )
{
    gm::Vec3f value00 = gm::Vec3f( 0.0f, 0.0f, 0.0f );
    gm::Vec3f value01 = gm::Vec3f( 2.0f, 2.0f, 2.0f );
    gm::Vec3f value10 = gm::Vec3f( 3.0f, 3.0f, 3.0f );
    gm::Vec3f value11 = gm::Vec3f( 5.0f, 5.0f, 5.0f );

    gm::Vec3f result = gm::BilinearInterpolation( value00,
                                                  value01,
                                                  value10,
                                                  value11,
                                                  /* weightX */ 0.5,
                                                  /* weightY */ 0.5 );

    CHECK( result == gm::Vec3f( 2.5f, 2.5f, 2.5f ) );
}

TEST_CASE( "BilinearInterpolation_Vec4f" )
{
    gm::Vec4f value00 = gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Vec4f value01 = gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Vec4f value10 = gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Vec4f value11 = gm::Vec4f( 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Vec4f result = gm::BilinearInterpolation( value00,
                                                  value01,
                                                  value10,
                                                  value11,
                                                  /* weightX */ 0.5,
                                                  /* weightY */ 0.5 );

    CHECK( result == gm::Vec4f( 2.5f, 2.5f, 2.5f, 2.5f ) );
}
