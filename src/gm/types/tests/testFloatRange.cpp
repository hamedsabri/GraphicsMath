//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/floatRange.h>

TEST_CASE( "FloatRange_DefaultConstructor" )
{
    gm::FloatRange range;
    CHECK( range.Min() == std::numeric_limits< float >::max() );
    CHECK( range.Max() == std::numeric_limits< float >::min() );
}

TEST_CASE( "FloatRange_MinMaxConstructor" )
{
    gm::FloatRange range( -1.0f, 1.0f );
    CHECK( range.Min() == -1.0f );
    CHECK( range.Max() == 1.0f );
}

TEST_CASE( "FloatRange_MinAccessor" )
{
    gm::FloatRange range;
    range.Min() = -1.0f;
    CHECK( range.Min() == -1.0f );
}

TEST_CASE( "FloatRange_MaxAccessor" )
{
    gm::FloatRange range;
    range.Max() = 1.0f;
    CHECK( range.Max() == 1.0f );
}