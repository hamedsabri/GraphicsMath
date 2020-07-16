//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/trilinearInterpolation.h>

TEST_CASE( "TrilinearInterpolation_float" )
{
    float value000 = 0.0f;
    float value001 = 2.0f;
    float value010 = 3.0f;
    float value011 = 5.0f;

    float value100 = 1.0f;
    float value101 = 3.0f;
    float value110 = 4.0f;
    float value111 = 6.0f;

    float result = gm::TrilinearInterpolation( value000,
                                               value001,
                                               value010,
                                               value011,
                                               value100,
                                               value101,
                                               value110,
                                               value111,
                                               /* weightX */ 0.5,
                                               /* weightY */ 0.5,
                                               /* weightZ */ 0.5 );

    CHECK( result == 3.0f );
}

TEST_CASE( "TrilinearInterpolation_Mat3f" )
{
    gm::Mat3f value000 = gm::Mat3f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat3f value001 = gm::Mat3f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat3f value010 = gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat3f value011 = gm::Mat3f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat3f value100 = gm::Mat3f( 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Mat3f value101 = gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat3f value110 = gm::Mat3f( 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Mat3f value111 = gm::Mat3f( 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Mat3f result = gm::TrilinearInterpolation( value000,
                                                   value001,
                                                   value010,
                                                   value011,
                                                   value100,
                                                   value101,
                                                   value110,
                                                   value111,
                                                   /* weightX */ 0.5,
                                                   /* weightY */ 0.5,
                                                   /* weightZ */ 0.5 );

    CHECK( result == gm::Mat3f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Mat4f" )
{
    gm::Mat4f value000 =
        gm::Mat4f( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Mat4f value001 =
        gm::Mat4f( 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Mat4f value010 =
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat4f value011 =
        gm::Mat4f( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Mat4f value100 =
        gm::Mat4f( 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Mat4f value101 =
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Mat4f value110 =
        gm::Mat4f( 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Mat4f value111 =
        gm::Mat4f( 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Mat4f result = gm::TrilinearInterpolation( value000,
                                                   value001,
                                                   value010,
                                                   value011,
                                                   value100,
                                                   value101,
                                                   value110,
                                                   value111,
                                                   /* weightX */ 0.5,
                                                   /* weightY */ 0.5,
                                                   /* weightZ */ 0.5 );

    CHECK(
        result ==
        gm::Mat4f( 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec2f" )
{
    gm::Vec2f value000 = gm::Vec2f( 0.0f, 0.0f );
    gm::Vec2f value001 = gm::Vec2f( 2.0f, 2.0f );
    gm::Vec2f value010 = gm::Vec2f( 3.0f, 3.0f );
    gm::Vec2f value011 = gm::Vec2f( 5.0f, 5.0f );

    gm::Vec2f value100 = gm::Vec2f( 1.0f, 1.0f );
    gm::Vec2f value101 = gm::Vec2f( 3.0f, 3.0f );
    gm::Vec2f value110 = gm::Vec2f( 4.0f, 4.0f );
    gm::Vec2f value111 = gm::Vec2f( 6.0f, 6.0f );

    gm::Vec2f result = gm::TrilinearInterpolation( value000,
                                                   value001,
                                                   value010,
                                                   value011,
                                                   value100,
                                                   value101,
                                                   value110,
                                                   value111,
                                                   /* weightX */ 0.5,
                                                   /* weightY */ 0.5,
                                                   /* weightZ */ 0.5 );

    CHECK( result == gm::Vec2f( 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec3f" )
{
    gm::Vec3f value000 = gm::Vec3f( 0.0f, 0.0f, 0.0f );
    gm::Vec3f value001 = gm::Vec3f( 2.0f, 2.0f, 2.0f );
    gm::Vec3f value010 = gm::Vec3f( 3.0f, 3.0f, 3.0f );
    gm::Vec3f value011 = gm::Vec3f( 5.0f, 5.0f, 5.0f );

    gm::Vec3f value100 = gm::Vec3f( 1.0f, 1.0f, 1.0f );
    gm::Vec3f value101 = gm::Vec3f( 3.0f, 3.0f, 3.0f );
    gm::Vec3f value110 = gm::Vec3f( 4.0f, 4.0f, 4.0f );
    gm::Vec3f value111 = gm::Vec3f( 6.0f, 6.0f, 6.0f );

    gm::Vec3f result = gm::TrilinearInterpolation( value000,
                                                   value001,
                                                   value010,
                                                   value011,
                                                   value100,
                                                   value101,
                                                   value110,
                                                   value111,
                                                   /* weightX */ 0.5,
                                                   /* weightY */ 0.5,
                                                   /* weightZ */ 0.5 );

    CHECK( result == gm::Vec3f( 3.0f, 3.0f, 3.0f ) );
}

TEST_CASE( "TrilinearInterpolation_Vec4f" )
{
    gm::Vec4f value000 = gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f );
    gm::Vec4f value001 = gm::Vec4f( 2.0f, 2.0f, 2.0f, 2.0f );
    gm::Vec4f value010 = gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Vec4f value011 = gm::Vec4f( 5.0f, 5.0f, 5.0f, 5.0f );

    gm::Vec4f value100 = gm::Vec4f( 1.0f, 1.0f, 1.0f, 1.0f );
    gm::Vec4f value101 = gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f );
    gm::Vec4f value110 = gm::Vec4f( 4.0f, 4.0f, 4.0f, 4.0f );
    gm::Vec4f value111 = gm::Vec4f( 6.0f, 6.0f, 6.0f, 6.0f );

    gm::Vec4f result = gm::TrilinearInterpolation( value000,
                                                   value001,
                                                   value010,
                                                   value011,
                                                   value100,
                                                   value101,
                                                   value110,
                                                   value111,
                                                   /* weightX */ 0.5,
                                                   /* weightY */ 0.5,
                                                   /* weightZ */ 0.5 );

    CHECK( result == gm::Vec4f( 3.0f, 3.0f, 3.0f, 3.0f ) );
}
