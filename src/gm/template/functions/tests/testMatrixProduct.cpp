#include <catch2/catch.hpp>

#include <gm/functions/matrixProduct.h>
#include <gm/functions/setIdentity.h>

TEST_CASE( "MatrixProduct_Mat3f" )
{
    gm::Mat3f matrixA;
    gm::Mat3f matrixB;

    // I * I == I
    gm::SetIdentity( matrixA );
    gm::SetIdentity( matrixB );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) == gm::Mat3f( 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 ) );

    // E^-1 * E^-1 = L
    matrixA = gm::Mat3f(
        1, 0, 0,
        2, 1, 0,
        0, 0, 1
    );
    matrixB = gm::Mat3f(
        1, 0, 0,
        0, 1, 0,
        3, 0, 1
    );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) == gm::Mat3f(
        1, 0, 0,
        2, 1, 0,
        3, 0, 1
    ) );

    // L * L = L
    matrixA = gm::Mat3f(
        1, 0, 0,
        1, 1, 0,
        1, 1, 1
    );
    matrixB = gm::Mat3f(
        1, 0, 0,
        1, 1, 0,
        1, 1, 1
    );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) == gm::Mat3f(
        1, 0, 0,
        2, 1, 0,
        3, 2, 1
    ) );
}

TEST_CASE( "MatrixProduct_Mat4f" )
{
    gm::Mat4f matrixA;
    gm::Mat4f matrixB;

    // I * I == I
    gm::SetIdentity( matrixA );
    gm::SetIdentity( matrixB );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) ==
           gm::Mat4f( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );

    // E^-1 * E^-1 = L
    matrixA = gm::Mat4f(
        1, 0, 0, 0,
        2, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
    matrixB = gm::Mat4f(
        1, 0, 0, 0,
        0, 1, 0, 0,
        3, 0, 1, 0,
        0, 0, 0, 1
    );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) == gm::Mat4f(
        1, 0, 0, 0,
        2, 1, 0, 0,
        3, 0, 1, 0,
        0, 0, 0, 1
    ) );

    // L * L = L
    matrixA = gm::Mat4f(
        1, 0, 0, 0,
        1, 1, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 1
    );
    matrixB = gm::Mat4f(
        1, 0, 0, 0,
        1, 1, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 1
    );
    CHECK( gm::MatrixProduct( matrixA, matrixB ) == gm::Mat4f(
        1, 0, 0, 0,
        2, 1, 0, 0,
        3, 2, 1, 0,
        4, 3, 2, 1
    ) );
}
