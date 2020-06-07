#include <catch2/catch.hpp>

#include <gm/functions/transpose.h>

TEST_CASE( "Transpose_Mat3f" )
{
    // Upper triangular matrix becomes a lower triangular matrix.
    gm::Mat3f matrix(
        1, 1, 1,
        0, 1, 1,
        0, 0, 1
    );

    CHECK( gm::Transpose( matrix ) == gm::Mat3f(
        1, 0, 0,
        1, 1, 0,
        1, 1, 1
    ) );
}

TEST_CASE( "Transpose_Mat4f" )
{
    // Upper triangular matrix becomes a lower triangular matrix.
    gm::Mat4f matrix(
        1, 1, 1, 1,
        0, 1, 1, 1,
        0, 0, 1, 1,
        0, 0, 0, 1
    );
    CHECK( gm::Transpose( matrix ) == gm::Mat4f(
        1, 0, 0, 0,
        1, 1, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 1
    ) );
}
