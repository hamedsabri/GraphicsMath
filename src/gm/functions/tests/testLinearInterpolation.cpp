//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/linearInterpolation.h>

TEST_CASE( "LinearInterpolation_float" )
{
    float source = 0.0f;
    float target = 5.0f;
    float result = gm::LinearInterpolation( source,
                                            target,
                                            /* weight */ 0.5 );

    CHECK( result == 2.5f );
}

TEST_CASE( "LinearInterpolation_Mat3f" )
{
    gm::Mat3f source = gm::Mat3f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat3f target = gm::Mat3f( 0.0f, 5.0f, 10.0f, 15.0f, 20.0f, 25.0f, 30.0f, 35.0f, 40.0f );
    gm::Mat3f result = gm::LinearInterpolation( source,
                                                target,
                                                /* weight */ 0.5 );

    CHECK( result == gm::Mat3f( 0.0f, 2.5f, 5.0f, 7.5f, 10.0f, 12.5f, 15.0f, 17.5f, 20.0f ) );
}

TEST_CASE( "LinearInterpolation_Mat4f" )
{
    gm::Mat4f source =
        gm::Mat4f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat4f target = gm::Mat4f( 0.0f,
                                  5.0f,
                                  10.0f,
                                  15.0f,
                                  20.0f,
                                  25.0f,
                                  30.0f,
                                  35.0f,
                                  40.0f,
                                  45.0f,
                                  50.0f,
                                  55.0f,
                                  60.0f,
                                  65.0f,
                                  70.0f,
                                  75.0f );
    gm::Mat4f result = gm::LinearInterpolation( source,
                                                target,
                                                /* weight */ 0.5 );

    CHECK( result == gm::Mat4f( 0.0f,
                                2.5f,
                                5.0f,
                                7.5f,
                                10.0f,
                                12.5f,
                                15.0f,
                                17.5f,
                                20.0f,
                                22.5f,
                                25.0f,
                                27.5f,
                                30.0f,
                                32.5f,
                                35.0f,
                                37.5f ) );
}

TEST_CASE( "LinearInterpolation_Vec2f" )
{
    gm::Vec2f source = gm::Vec2f( 0.0f, 0.0f );
    gm::Vec2f target = gm::Vec2f( 0.0f, 5.0f );
    gm::Vec2f result = gm::LinearInterpolation( source,
                                                target,
                                                /* weight */ 0.5 );

    CHECK( result == gm::Vec2f( 0.0f, 2.5f ) );
}

TEST_CASE( "LinearInterpolation_Vec3f" )
{
    gm::Vec3f source = gm::Vec3f( 0.0f, 0.0f, 0.0f );
    gm::Vec3f target = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    gm::Vec3f result = gm::LinearInterpolation( source,
                                                target,
                                                /* weight */ 0.5 );

    CHECK( result == gm::Vec3f( 0.0f, 2.5f, 5.0f ) );
}

TEST_CASE( "LinearInterpolation_Vec4f" )
{
    gm::Vec4f source = gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Vec4f target = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    gm::Vec4f result = gm::LinearInterpolation( source,
                                                target,
                                                /* weight */ 0.5 );

    CHECK( result == gm::Vec4f( 0.0f, 2.5f, 5.0f, 7.5f ) );
}
