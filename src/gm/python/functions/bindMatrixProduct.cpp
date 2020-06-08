//
// This file is auto-generated, please do not modify directly!
//

#include <pybind11/pybind11.h>

#include <gm/functions/matrixProduct.h>

// Python bindings for MatrixProduct.

GM_NS_USING

void BindMatrixProduct( pybind11::module& o_module )
{
    o_module.def( "MatrixProduct",
                  []( const Mat3f& i_lhs, const Mat3f& i_rhs ) { return MatrixProduct( i_lhs, i_rhs ); } );
    o_module.def( "MatrixProduct",
                  []( const Mat4f& i_lhs, const Mat4f& i_rhs ) { return MatrixProduct( i_lhs, i_rhs ); } );
}