//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/viewportTransform.h>

TEST_CASE( "ViewportTransform_Vec2f_Vec2f" )
{
    gm::Vec2f dimensions;
    gm::Vec2f offset;
    BENCHMARK( "ViewportTransform" )
    {
        return gm::ViewportTransform( dimensions, offset );
    };
}
