//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/trilinearInterpolation.h>

TEST_CASE( "TrilinearInterpolation_float_float_float_float_float_float_float_float_float_float_float" )
{
    float value000;
    float value001;
    float value010;
    float value011;
    float value100;
    float value101;
    float value110;
    float value111;
    float weightX;
    float weightY;
    float weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}

TEST_CASE( "TrilinearInterpolation_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_Mat3f_float_float_float" )
{
    gm::Mat3f value000;
    gm::Mat3f value001;
    gm::Mat3f value010;
    gm::Mat3f value011;
    gm::Mat3f value100;
    gm::Mat3f value101;
    gm::Mat3f value110;
    gm::Mat3f value111;
    float     weightX;
    float     weightY;
    float     weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}

TEST_CASE( "TrilinearInterpolation_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_Mat4f_float_float_float" )
{
    gm::Mat4f value000;
    gm::Mat4f value001;
    gm::Mat4f value010;
    gm::Mat4f value011;
    gm::Mat4f value100;
    gm::Mat4f value101;
    gm::Mat4f value110;
    gm::Mat4f value111;
    float     weightX;
    float     weightY;
    float     weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f_float_float_float" )
{
    gm::Vec2f value000;
    gm::Vec2f value001;
    gm::Vec2f value010;
    gm::Vec2f value011;
    gm::Vec2f value100;
    gm::Vec2f value101;
    gm::Vec2f value110;
    gm::Vec2f value111;
    float     weightX;
    float     weightY;
    float     weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_Vec3f_float_float_float" )
{
    gm::Vec3f value000;
    gm::Vec3f value001;
    gm::Vec3f value010;
    gm::Vec3f value011;
    gm::Vec3f value100;
    gm::Vec3f value101;
    gm::Vec3f value110;
    gm::Vec3f value111;
    float     weightX;
    float     weightY;
    float     weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}

TEST_CASE( "TrilinearInterpolation_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_Vec4f_float_float_float" )
{
    gm::Vec4f value000;
    gm::Vec4f value001;
    gm::Vec4f value010;
    gm::Vec4f value011;
    gm::Vec4f value100;
    gm::Vec4f value101;
    gm::Vec4f value110;
    gm::Vec4f value111;
    float     weightX;
    float     weightY;
    float     weightZ;
    BENCHMARK( "TrilinearInterpolation" )
    {
        return gm::TrilinearInterpolation( value000,
                                           value001,
                                           value010,
                                           value011,
                                           value100,
                                           value101,
                                           value110,
                                           value111,
                                           weightX,
                                           weightY,
                                           weightZ );
    };
}
