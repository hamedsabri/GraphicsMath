//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/faceForward.h>

TEST_CASE( "FaceForward_Vec2f_Vec2f" )
{
    gm::Vec2f normal;
    gm::Vec2f guide;
    BENCHMARK( "FaceForward" )
    {
        return gm::FaceForward( normal, guide );
    };
}

TEST_CASE( "FaceForward_Vec3f_Vec3f" )
{
    gm::Vec3f normal;
    gm::Vec3f guide;
    BENCHMARK( "FaceForward" )
    {
        return gm::FaceForward( normal, guide );
    };
}

TEST_CASE( "FaceForward_Vec4f_Vec4f" )
{
    gm::Vec4f normal;
    gm::Vec4f guide;
    BENCHMARK( "FaceForward" )
    {
        return gm::FaceForward( normal, guide );
    };
}
