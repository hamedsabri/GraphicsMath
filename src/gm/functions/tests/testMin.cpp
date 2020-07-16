//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/min.h>

TEST_CASE( "Min_float" )
{
    float valueA = 1.333f;
    float valueB = 2.333f;
    CHECK( gm::Min( valueA, valueB ) == 1.333f );
}

TEST_CASE( "Min_int" )
{
    int valueA = 1;
    int valueB = 2;
    CHECK( gm::Min( valueA, valueB ) == 1 );
}

TEST_CASE( "Min_bool" )
{
    bool valueA = true;
    bool valueB = true;
    CHECK( gm::Min( valueA, valueB ) == true );
}

TEST_CASE( "Min_Vec2f" )
{
    gm::Vec2f valueA = gm::Vec2f( 0.0f, 1.333f );
    gm::Vec2f valueB = gm::Vec2f( 0.0f, 2.333f );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec2f( 0.0f, 1.333f ) );
}

TEST_CASE( "Min_Vec3f" )
{
    gm::Vec3f valueA = gm::Vec3f( 0.0f, 1.333f, 2.666f );
    gm::Vec3f valueB = gm::Vec3f( 0.0f, 2.333f, 4.666f );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec3f( 0.0f, 1.333f, 2.666f ) );
}

TEST_CASE( "Min_Vec4f" )
{
    gm::Vec4f valueA = gm::Vec4f( 0.0f, 1.333f, 2.666f, 3.999f );
    gm::Vec4f valueB = gm::Vec4f( 0.0f, 2.333f, 4.666f, 6.999f );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec4f( 0.0f, 1.333f, 2.666f, 3.999f ) );
}

TEST_CASE( "Min_Vec2i" )
{
    gm::Vec2i valueA = gm::Vec2i( 0, 1 );
    gm::Vec2i valueB = gm::Vec2i( 0, 2 );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec2i( 0, 1 ) );
}

TEST_CASE( "Min_Vec3i" )
{
    gm::Vec3i valueA = gm::Vec3i( 0, 1, 2 );
    gm::Vec3i valueB = gm::Vec3i( 0, 2, 4 );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec3i( 0, 1, 2 ) );
}

TEST_CASE( "Min_Vec4i" )
{
    gm::Vec4i valueA = gm::Vec4i( 0, 1, 2, 3 );
    gm::Vec4i valueB = gm::Vec4i( 0, 2, 4, 6 );
    CHECK( gm::Min( valueA, valueB ) == gm::Vec4i( 0, 1, 2, 3 ) );
}

TEST_CASE( "Min_Mat3f" )
{
    gm::Mat3f valueA = gm::Mat3f( 0.0f, 1.333f, 2.666f, 3.999f, 5.332f, 6.665f, 7.998f, 9.331f, 10.664f );
    gm::Mat3f valueB = gm::Mat3f( 0.0f, 2.333f, 4.666f, 6.999f, 9.332f, 11.665f, 13.998f, 16.331f, 18.664f );
    CHECK( gm::Min( valueA, valueB ) ==
           gm::Mat3f( 0.0f, 1.333f, 2.666f, 3.999f, 5.332f, 6.665f, 7.998f, 9.331f, 10.664f ) );
}

TEST_CASE( "Min_Mat4f" )
{
    gm::Mat4f valueA = gm::Mat4f( 0.0f,
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
    gm::Mat4f valueB = gm::Mat4f( 0.0f,
                                  2.333f,
                                  4.666f,
                                  6.999f,
                                  9.332f,
                                  11.665f,
                                  13.998f,
                                  16.331f,
                                  18.664f,
                                  20.997f,
                                  23.33f,
                                  25.663f,
                                  27.996f,
                                  30.329f,
                                  32.662f,
                                  34.995f );
    CHECK( gm::Min( valueA, valueB ) == gm::Mat4f( 0.0f,
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
                                                   19.995f ) );
}
