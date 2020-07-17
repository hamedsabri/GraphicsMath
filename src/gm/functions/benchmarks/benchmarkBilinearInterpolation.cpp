//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/bilinearInterpolation.h>

TEST_CASE( "BilinearInterpolation_float_float_float_float_Vec2f" )
{
    float     corner00;
    float     corner10;
    float     corner01;
    float     corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}

TEST_CASE( "BilinearInterpolation_Mat3f_Mat3f_Mat3f_Mat3f_Vec2f" )
{
    gm::Mat3f corner00;
    gm::Mat3f corner10;
    gm::Mat3f corner01;
    gm::Mat3f corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}

TEST_CASE( "BilinearInterpolation_Mat4f_Mat4f_Mat4f_Mat4f_Vec2f" )
{
    gm::Mat4f corner00;
    gm::Mat4f corner10;
    gm::Mat4f corner01;
    gm::Mat4f corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}

TEST_CASE( "BilinearInterpolation_Vec2f_Vec2f_Vec2f_Vec2f_Vec2f" )
{
    gm::Vec2f corner00;
    gm::Vec2f corner10;
    gm::Vec2f corner01;
    gm::Vec2f corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}

TEST_CASE( "BilinearInterpolation_Vec3f_Vec3f_Vec3f_Vec3f_Vec2f" )
{
    gm::Vec3f corner00;
    gm::Vec3f corner10;
    gm::Vec3f corner01;
    gm::Vec3f corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}

TEST_CASE( "BilinearInterpolation_Vec4f_Vec4f_Vec4f_Vec4f_Vec2f" )
{
    gm::Vec4f corner00;
    gm::Vec4f corner10;
    gm::Vec4f corner01;
    gm::Vec4f corner11;
    gm::Vec2f weight;
    BENCHMARK( "BilinearInterpolation" )
    {
        return gm::BilinearInterpolation( corner00, corner10, corner01, corner11, weight );
    };
}
