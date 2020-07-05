//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/clamp.h>

TEST_CASE( "Clamp_float_lessThanMin" )
{
    float          floatVal = -15.0f;
    gm::FloatRange range( -10.0f, 10.0f );
    float          floatValClamped  = gm::Clamp( floatVal, range );
    float          floatValExpected = -10.0f;
    CHECK( floatValClamped == floatValExpected );
}

TEST_CASE( "Clamp_int_lessThanMin" )
{
    int          intVal = -15;
    gm::IntRange range( -10, 10 );
    int          intValClamped  = gm::Clamp( intVal, range );
    int          intValExpected = -10;
    CHECK( intValClamped == intValExpected );
}

TEST_CASE( "Clamp_Mat3f_lessThanMin" )
{
    gm::Mat3f      matrix( -15.0f, -15.0f, -15.0f, -15.0f, -15.0f, -15.0f, -15.0f, -15.0f, -15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat3f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat3f      matrixExpected( -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Mat4f_lessThanMin" )
{
    gm::Mat4f      matrix( -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f,
                      -15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat4f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat4f      matrixExpected( -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f,
                              -10.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Vec2f_lessThanMin" )
{
    gm::Vec2f      vector( -15.0f, -15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec2f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec2f      vectorExpected( -10.0f, -10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3f_lessThanMin" )
{
    gm::Vec3f      vector( -15.0f, -15.0f, -15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec3f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec3f      vectorExpected( -10.0f, -10.0f, -10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4f_lessThanMin" )
{
    gm::Vec4f      vector( -15.0f, -15.0f, -15.0f, -15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec4f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec4f      vectorExpected( -10.0f, -10.0f, -10.0f, -10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec2i_lessThanMin" )
{
    gm::Vec2i    vector( -15, -15 );
    gm::IntRange range( -10, 10 );
    gm::Vec2i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec2i    vectorExpected( -10, -10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3i_lessThanMin" )
{
    gm::Vec3i    vector( -15, -15, -15 );
    gm::IntRange range( -10, 10 );
    gm::Vec3i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec3i    vectorExpected( -10, -10, -10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4i_lessThanMin" )
{
    gm::Vec4i    vector( -15, -15, -15, -15 );
    gm::IntRange range( -10, 10 );
    gm::Vec4i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec4i    vectorExpected( -10, -10, -10, -10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_float_greaterThanMax" )
{
    float          floatVal = 15.0f;
    gm::FloatRange range( -10.0f, 10.0f );
    float          floatValClamped  = gm::Clamp( floatVal, range );
    float          floatValExpected = 10.0f;
    CHECK( floatValClamped == floatValExpected );
}

TEST_CASE( "Clamp_int_greaterThanMax" )
{
    int          intVal = 15;
    gm::IntRange range( -10, 10 );
    int          intValClamped  = gm::Clamp( intVal, range );
    int          intValExpected = 10;
    CHECK( intValClamped == intValExpected );
}

TEST_CASE( "Clamp_Mat3f_greaterThanMax" )
{
    gm::Mat3f      matrix( 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat3f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat3f      matrixExpected( 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Mat4f_greaterThanMax" )
{
    gm::Mat4f      matrix( 15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f,
                      15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat4f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat4f      matrixExpected( 10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f,
                              10.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Vec2f_greaterThanMax" )
{
    gm::Vec2f      vector( 15.0f, 15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec2f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec2f      vectorExpected( 10.0f, 10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3f_greaterThanMax" )
{
    gm::Vec3f      vector( 15.0f, 15.0f, 15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec3f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec3f      vectorExpected( 10.0f, 10.0f, 10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4f_greaterThanMax" )
{
    gm::Vec4f      vector( 15.0f, 15.0f, 15.0f, 15.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec4f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec4f      vectorExpected( 10.0f, 10.0f, 10.0f, 10.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec2i_greaterThanMax" )
{
    gm::Vec2i    vector( 15, 15 );
    gm::IntRange range( -10, 10 );
    gm::Vec2i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec2i    vectorExpected( 10, 10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3i_greaterThanMax" )
{
    gm::Vec3i    vector( 15, 15, 15 );
    gm::IntRange range( -10, 10 );
    gm::Vec3i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec3i    vectorExpected( 10, 10, 10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4i_greaterThanMax" )
{
    gm::Vec4i    vector( 15, 15, 15, 15 );
    gm::IntRange range( -10, 10 );
    gm::Vec4i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec4i    vectorExpected( 10, 10, 10, 10 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_float_withinRange" )
{
    float          floatVal = 5.0f;
    gm::FloatRange range( -10.0f, 10.0f );
    float          floatValClamped  = gm::Clamp( floatVal, range );
    float          floatValExpected = 5.0f;
    CHECK( floatValClamped == floatValExpected );
}

TEST_CASE( "Clamp_int_withinRange" )
{
    int          intVal = 5;
    gm::IntRange range( -10, 10 );
    int          intValClamped  = gm::Clamp( intVal, range );
    int          intValExpected = 5;
    CHECK( intValClamped == intValExpected );
}

TEST_CASE( "Clamp_Mat3f_withinRange" )
{
    gm::Mat3f      matrix( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat3f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat3f      matrixExpected( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Mat4f_withinRange" )
{
    gm::Mat4f matrix( 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Mat4f      matrixClamped = gm::Clamp( matrix, range );
    gm::Mat4f      matrixExpected( 5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f,
                              5.0f );
    CHECK( matrixClamped == matrixExpected );
}

TEST_CASE( "Clamp_Vec2f_withinRange" )
{
    gm::Vec2f      vector( 5.0f, 5.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec2f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec2f      vectorExpected( 5.0f, 5.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3f_withinRange" )
{
    gm::Vec3f      vector( 5.0f, 5.0f, 5.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec3f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec3f      vectorExpected( 5.0f, 5.0f, 5.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4f_withinRange" )
{
    gm::Vec4f      vector( 5.0f, 5.0f, 5.0f, 5.0f );
    gm::FloatRange range( -10.0f, 10.0f );
    gm::Vec4f      vectorClamped = gm::Clamp( vector, range );
    gm::Vec4f      vectorExpected( 5.0f, 5.0f, 5.0f, 5.0f );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec2i_withinRange" )
{
    gm::Vec2i    vector( 5, 5 );
    gm::IntRange range( -10, 10 );
    gm::Vec2i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec2i    vectorExpected( 5, 5 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec3i_withinRange" )
{
    gm::Vec3i    vector( 5, 5, 5 );
    gm::IntRange range( -10, 10 );
    gm::Vec3i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec3i    vectorExpected( 5, 5, 5 );
    CHECK( vectorClamped == vectorExpected );
}

TEST_CASE( "Clamp_Vec4i_withinRange" )
{
    gm::Vec4i    vector( 5, 5, 5, 5 );
    gm::IntRange range( -10, 10 );
    gm::Vec4i    vectorClamped = gm::Clamp( vector, range );
    gm::Vec4i    vectorExpected( 5, 5, 5, 5 );
    CHECK( vectorClamped == vectorExpected );
}
