//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/matrixProduct.h>

TEST_CASE( "MatrixProduct_Mat3f_Mat3f" )
{
    gm::Mat3f lhs;
    gm::Mat3f rhs;
    BENCHMARK( "MatrixProduct" )
    {
        return gm::MatrixProduct( lhs, rhs );
    };
}

TEST_CASE( "MatrixProduct_Mat4f_Mat4f" )
{
    gm::Mat4f lhs;
    gm::Mat4f rhs;
    BENCHMARK( "MatrixProduct" )
    {
        return gm::MatrixProduct( lhs, rhs );
    };
}
