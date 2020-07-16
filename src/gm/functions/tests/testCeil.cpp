//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/ceil.h>

TEST_CASE( "Ceil_float" )
{
    float value = 1.333f;
    CHECK( gm::Ceil( value ) == 2.0f );
}

TEST_CASE( "Ceil_Vec2f" )
{
    gm::Vec2f value = gm::Vec2f( 0.0f, 1.333f );
    CHECK( gm::Ceil( value ) == gm::Vec2f( 0.0f, 2.0f ) );
}

TEST_CASE( "Ceil_Vec3f" )
{
    gm::Vec3f value = gm::Vec3f( 0.0f, 1.333f, 2.666f );
    CHECK( gm::Ceil( value ) == gm::Vec3f( 0.0f, 2.0f, 3.0f ) );
}

TEST_CASE( "Ceil_Vec4f" )
{
    gm::Vec4f value = gm::Vec4f( 0.0f, 1.333f, 2.666f, 3.999f );
    CHECK( gm::Ceil( value ) == gm::Vec4f( 0.0f, 2.0f, 3.0f, 4.0f ) );
}

TEST_CASE( "Ceil_Mat3f" )
{
    gm::Mat3f value = gm::Mat3f( 0.0f, 1.333f, 2.666f, 3.999f, 5.332f, 6.665f, 7.998f, 9.331f, 10.664f );
    CHECK( gm::Ceil( value ) == gm::Mat3f( 0.0f, 2.0f, 3.0f, 4.0f, 6.0f, 7.0f, 8.0f, 10.0f, 11.0f ) );
}

TEST_CASE( "Ceil_Mat4f" )
{
    gm::Mat4f value = gm::Mat4f( 0.0f,
                                 1.333f,
                                 2.666f,
                                 3.999f,
                                 5.332f,
                                 6.665f,
                                 7.998f,
                                 9.331f,
                                 10.664f,
                                 11.997f,
                                 13.33f,
                                 14.663f,
                                 15.996f,
                                 17.329f,
                                 18.662f,
                                 19.995f );
    CHECK( gm::Ceil( value ) == gm::Mat4f( 0.0f,
                                           2.0f,
                                           3.0f,
                                           4.0f,
                                           6.0f,
                                           7.0f,
                                           8.0f,
                                           10.0f,
                                           11.0f,
                                           12.0f,
                                           14.0f,
                                           15.0f,
                                           16.0f,
                                           18.0f,
                                           19.0f,
                                           20.0f ) );
}
