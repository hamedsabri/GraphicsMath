//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/bilinearInterpolation.h>

TEST_CASE( "BilinearInterpolation_float_float_float_float_float_float" )
{
    float value00;
    float value01;
    float value10;
    float value11;
    float weightX;
    float weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}

TEST_CASE( "BilinearInterpolation_Mat3f_Mat3f_Mat3f_Mat3f_float_float" )
{
    gm::Mat3f value00;
    gm::Mat3f value01;
    gm::Mat3f value10;
    gm::Mat3f value11;
    float     weightX;
    float     weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}

TEST_CASE( "BilinearInterpolation_Mat4f_Mat4f_Mat4f_Mat4f_float_float" )
{
    gm::Mat4f value00;
    gm::Mat4f value01;
    gm::Mat4f value10;
    gm::Mat4f value11;
    float     weightX;
    float     weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}

TEST_CASE( "BilinearInterpolation_Vec2f_Vec2f_Vec2f_Vec2f_float_float" )
{
    gm::Vec2f value00;
    gm::Vec2f value01;
    gm::Vec2f value10;
    gm::Vec2f value11;
    float     weightX;
    float     weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}

TEST_CASE( "BilinearInterpolation_Vec3f_Vec3f_Vec3f_Vec3f_float_float" )
{
    gm::Vec3f value00;
    gm::Vec3f value01;
    gm::Vec3f value10;
    gm::Vec3f value11;
    float     weightX;
    float     weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}

TEST_CASE( "BilinearInterpolation_Vec4f_Vec4f_Vec4f_Vec4f_float_float" )
{
    gm::Vec4f value00;
    gm::Vec4f value01;
    gm::Vec4f value10;
    gm::Vec4f value11;
    float     weightX;
    float     weightY;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( value00, value01, value10, value11, weightX, weightY );
    };
}
