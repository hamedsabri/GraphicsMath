//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/crossProduct.h>

TEST_CASE( "CrossProduct_Vec3f_Vec3f" )
{
    gm::Vec3f lhs;
    gm::Vec3f rhs;
    BENCHMARK( "CrossProduct" )
    {
        return gm::CrossProduct( lhs, rhs );
    };
}
