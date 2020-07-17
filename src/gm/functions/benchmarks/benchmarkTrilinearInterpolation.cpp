//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/trilinearInterpolation.h>

TEST_CASE( "TrilinearInterpolation_float_float_float_float_float_float_float_float_Vec3f" )
{
    float     corner000;
    float     corner100;
    float     corner010;
    float     corner110;
    float     corner001;
    float     corner101;
    float     corner011;
    float     corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}

TEST_CASE( "TrilinearInterpolation_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Vec3f" )
{
    gm::Mat3f corner000;
    gm::Mat3f corner100;
    gm::Mat3f corner010;
    gm::Mat3f corner110;
    gm::Mat3f corner001;
    gm::Mat3f corner101;
    gm::Mat3f corner011;
    gm::Mat3f corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}

TEST_CASE( "TrilinearInterpolation_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Vec3f" )
{
    gm::Mat4f corner000;
    gm::Mat4f corner100;
    gm::Mat4f corner010;
    gm::Mat4f corner110;
    gm::Mat4f corner001;
    gm::Mat4f corner101;
    gm::Mat4f corner011;
    gm::Mat4f corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec3f" )
{
    gm::Vec2f corner000;
    gm::Vec2f corner100;
    gm::Vec2f corner010;
    gm::Vec2f corner110;
    gm::Vec2f corner001;
    gm::Vec2f corner101;
    gm::Vec2f corner011;
    gm::Vec2f corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f" )
{
    gm::Vec3f corner000;
    gm::Vec3f corner100;
    gm::Vec3f corner010;
    gm::Vec3f corner110;
    gm::Vec3f corner001;
    gm::Vec3f corner101;
    gm::Vec3f corner011;
    gm::Vec3f corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec3f" )
{
    gm::Vec4f corner000;
    gm::Vec4f corner100;
    gm::Vec4f corner010;
    gm::Vec4f corner110;
    gm::Vec4f corner001;
    gm::Vec4f corner101;
    gm::Vec4f corner011;
    gm::Vec4f corner111;
    gm::Vec3f weight;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( corner000,
                                           corner100,
                                           corner010,
                                           corner110,
                                           corner001,
                                           corner101,
                                           corner011,
                                           corner111,
                                           weight );
    };
}
