//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/vec3f.h>

TEST_CASE( "Vec3f_DefaultConstructor" )
{
    gm::Vec3f vector;
    CHECK( vector == gm::Vec3f( 0.0f, 0.0f, 0.0f ) );
}

TEST_CASE( "Vec3f_CopyConstructor" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB( vectorA );
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3f_CopyAssignmentConstructor" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB = vectorA;
    CHECK( vectorA == vectorB );
}

TEST_CASE( "Vec3f_ElementReadAccess" )
{
    gm::Vec3f vector = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    CHECK( vector[ 0 ] == 0.0f );
    CHECK( vector[ 1 ] == 2.0f );
    CHECK( vector[ 2 ] == 4.0f );
}

TEST_CASE( "Vec3f_ElementWriteAccess" )
{
    gm::Vec3f vector;
    vector[ 0 ] = 0.0f;
    vector[ 1 ] = 5.0f;
    vector[ 2 ] = 10.0f;
    CHECK( vector[ 0 ] == 0.0f );
    CHECK( vector[ 1 ] == 5.0f );
    CHECK( vector[ 2 ] == 10.0f );
}

TEST_CASE( "Vec3f_NamedElementXAccessor" )
{
    gm::Vec3f vector = gm::Vec3f( 0.0f, 1.0f, 2.0f );
    CHECK( vector.X() == 0.0f );
}

TEST_CASE( "Vec3f_NamedElementYAccessor" )
{
    gm::Vec3f vector = gm::Vec3f( 0.0f, 1.0f, 2.0f );
    CHECK( vector.Y() == 1.0f );
}

TEST_CASE( "Vec3f_NamedElementZAccessor" )
{
    gm::Vec3f vector = gm::Vec3f( 0.0f, 1.0f, 2.0f );
    CHECK( vector.Z() == 2.0f );
}

TEST_CASE( "Vec3f_Addition" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    gm::Vec3f vectorC = vectorA + vectorB;
    CHECK( vectorC == gm::Vec3f( 0.0f, 7.0f, 14.0f ) );
}

TEST_CASE( "Vec3f_AdditionAssignment" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    vectorB += vectorA;
    CHECK( vectorB == gm::Vec3f( 0.0f, 7.0f, 14.0f ) );
}

TEST_CASE( "Vec3f_Subtraction" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 7.0f, 14.0f );
    gm::Vec3f vectorB = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    gm::Vec3f vectorC = vectorA - vectorB;
    CHECK( vectorC == gm::Vec3f( 0.0f, 2.0f, 4.0f ) );
}

TEST_CASE( "Vec3f_SubtractionAssignment" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 5.0f, 10.0f );
    gm::Vec3f vectorB = gm::Vec3f( 0.0f, 7.0f, 14.0f );
    vectorB -= vectorA;
    CHECK( vectorB == gm::Vec3f( 0.0f, 2.0f, 4.0f ) );
}

TEST_CASE( "Vec3f_ScalarVectorMultiplication" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB = 5.0f * vectorA;
    CHECK( vectorB == gm::Vec3f( 0.0f, 10.0f, 20.0f ) );
}

TEST_CASE( "Vec3f_VectorScalarMultiplication" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    gm::Vec3f vectorB = vectorA * 5.0f;
    CHECK( vectorB == gm::Vec3f( 0.0f, 10.0f, 20.0f ) );
}

TEST_CASE( "Vec3f_ScalarMultiplicationAssignment" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    vectorA *= 5;
    CHECK( vectorA == gm::Vec3f( 0.0f, 10.0f, 20.0f ) );
}

TEST_CASE( "Vec3f_VectorScalarDivision" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 10.0f, 20.0f );
    gm::Vec3f vectorB = vectorA / 5.0f;
    CHECK( vectorB == gm::Vec3f( 0.0f, 2.0f, 4.0f ) );
}

TEST_CASE( "Vec3f_ScalarDivisionAssignment" )
{
    gm::Vec3f vectorA = gm::Vec3f( 0.0f, 10.0f, 20.0f );
    vectorA /= 5;
    CHECK( vectorA == gm::Vec3f( 0.0f, 2.0f, 4.0f ) );
}

TEST_CASE( "Vec3f_Negation" )
{
    gm::Vec3f vector = gm::Vec3f( 0.0f, 2.0f, 4.0f );
    CHECK( -vector == gm::Vec3f( 0.0f, -2.0f, -4.0f ) );
}
