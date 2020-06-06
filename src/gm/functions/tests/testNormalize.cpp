//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/functions/normalize.h>

TEST_CASE( "Normalize_Vec2f" )
{
    gm::Vec2f vector( 0.0f, 2.0f );
    CHECK( gm::Normalize( vector ) == gm::Vec2f( 0.0f, 1.0f ) );
}

TEST_CASE( "Normalize_Vec3f" )
{
    gm::Vec3f vector( 0.0f, 2.0f, 4.0f );
    CHECK( gm::Normalize( vector ) == gm::Vec3f( 0.0f, 0.4472135955f, 0.894427191f ) );
}

TEST_CASE( "Normalize_Vec4f" )
{
    gm::Vec4f vector( 0.0f, 2.0f, 4.0f, 6.0f );
    CHECK( gm::Normalize( vector ) == gm::Vec4f( 0.0f, 0.267261241912f, 0.534522483825f, 0.801783725737f ) );
}
