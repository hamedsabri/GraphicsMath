//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec4f.h>

TEST_CASE( "Vec4f_DefaultConstructor" )
{
    gm::Vec4f vector;
    CHECK( vector == gm::Vec4f( 0.0f, 0.0f, 0.0f, 0.0f ) );
}

TEST_CASE( "Vec4f_CopyConstructor" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4f_CopyAssignmentConstructor" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec4f_ElementReadAccess" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    CHECK( vector[ 0 ] == 0.0f );
    CHECK( vector[ 1 ] == 2.0f );
    CHECK( vector[ 2 ] == 4.0f );
    CHECK( vector[ 3 ] == 6.0f );
}

TEST_CASE( "Vec4f_ElementWriteAccess" )
{
    gm::Vec4f vector;
    vector[ 0 ] = 0.0f;
    vector[ 1 ] = 5.0f;
    vector[ 2 ] = 10.0f;
    vector[ 3 ] = 15.0f;
    CHECK( vector[ 0 ] == 0.0f );
    CHECK( vector[ 1 ] == 5.0f );
    CHECK( vector[ 2 ] == 10.0f );
    CHECK( vector[ 3 ] == 15.0f );
}

TEST_CASE( "Vec4f_NamedElementReadAccessorX" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    CHECK( vector.X() == 0.0f );
}

TEST_CASE( "Vec4f_NamedElementWriteAccessorX" )
{
    gm::Vec4f vector;
    vector.X() = 0.0f;
    CHECK( vector[ 0 ] == 0.0f );
}
TEST_CASE( "Vec4f_NamedElementReadAccessorY" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    CHECK( vector.Y() == 1.0f );
}

TEST_CASE( "Vec4f_NamedElementWriteAccessorY" )
{
    gm::Vec4f vector;
    vector.Y() = 1.0f;
    CHECK( vector[ 1 ] == 1.0f );
}
TEST_CASE( "Vec4f_NamedElementReadAccessorZ" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    CHECK( vector.Z() == 2.0f );
}

TEST_CASE( "Vec4f_NamedElementWriteAccessorZ" )
{
    gm::Vec4f vector;
    vector.Z() = 2.0f;
    CHECK( vector[ 2 ] == 2.0f );
}
TEST_CASE( "Vec4f_NamedElementReadAccessorW" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 1.0f, 2.0f, 3.0f );
    CHECK( vector.W() == 3.0f );
}

TEST_CASE( "Vec4f_NamedElementWriteAccessorW" )
{
    gm::Vec4f vector;
    vector.W() = 3.0f;
    CHECK( vector[ 3 ] == 3.0f );
}

TEST_CASE( "Vec4f_Addition" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    gm::Vec4f vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec4f( 0.0f, 7.0f, 14.0f, 21.0f ) );
}

TEST_CASE( "Vec4f_AdditionAssignment" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec4f( 0.0f, 7.0f, 14.0f, 21.0f ) );
}

TEST_CASE( "Vec4f_Subtraction" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 7.0f, 14.0f, 21.0f );
    gm::Vec4f vectorB = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    gm::Vec4f vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f ) );
}

TEST_CASE( "Vec4f_SubtractionAssignment" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 5.0f, 10.0f, 15.0f );
    gm::Vec4f vectorB = gm::Vec4f( 0.0f, 7.0f, 14.0f, 21.0f );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f ) );
}

TEST_CASE( "Vec4f_ScalarVectorMultiplication" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB = 5.0f * vectorA;
    CHECK( vectorB == gm::Vec4f( 0.0f, 10.0f, 20.0f, 30.0f ) );
}

TEST_CASE( "Vec4f_VectorScalarMultiplication" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    gm::Vec4f vectorB = vectorA * 5.0f;
    CHECK( vectorB == gm::Vec4f( 0.0f, 10.0f, 20.0f, 30.0f ) );
}

TEST_CASE( "Vec4f_ScalarMultiplicationAssignment" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec4f( 0.0f, 10.0f, 20.0f, 30.0f ) );
}

TEST_CASE( "Vec4f_VectorScalarDivision" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 10.0f, 20.0f, 30.0f );
    gm::Vec4f vectorB = vectorA / 5.0f;
    CHECK( vectorB == gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f ) );
}

TEST_CASE( "Vec4f_ScalarDivisionAssignment" )
{
    gm::Vec4f vectorA = gm::Vec4f( 0.0f, 10.0f, 20.0f, 30.0f );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f ) );
}

TEST_CASE( "Vec4f_Negation" )
{
    gm::Vec4f vector = gm::Vec4f( 0.0f, 2.0f, 4.0f, 6.0f );
    CHECK( -vector == gm::Vec4f( 0.0f, -2.0f, -4.0f, -6.0f ) );
}
