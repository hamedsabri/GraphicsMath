#include <catch2/catch.hpp>

#include <gm/functions/matrixProduct.h>
#include <gm/functions/inverse.h>

template < typename MatrixT >
void CHECK_INVERSE( const MatrixT& i_matrix )
{
    MatrixT identity;
    gm::SetIdentity( identity );
    MatrixT inverse;
    CHECK( gm::Inverse( i_matrix, inverse ) );
    CHECK( gm::MatrixProduct( i_matrix, inverse ) == identity );
    CHECK( gm::MatrixProduct( inverse, i_matrix ) == identity );
}

TEST_CASE( "Inverse_Mat4f" )
{
    CHECK_INVERSE( gm::Mat4f(
            1,  7, 0.25, 8,
            0,  5, 8,    9,
            2, -3, 1,    1.3,
            8,  1, 2,    1.3
        )
    );

    CHECK_INVERSE( gm::Mat4f(
            5,  7, 52,  1.0,
            1,  5, 72,  0.5,
            0, -3, 2.5, 5.5,
            1,  1, 5,   1.3
        )
    );
}
