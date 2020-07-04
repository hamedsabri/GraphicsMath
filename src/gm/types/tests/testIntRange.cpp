//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/intRange.h>

TEST_CASE( "IntRange_DefaultConstructor" )
{
    gm::IntRange range;
    CHECK( range.Min() == std::numeric_limits< int >::max() );
    CHECK( range.Max() == std::numeric_limits< int >::min() );
}

TEST_CASE( "IntRange_MinMaxConstructor" )
{
    gm::IntRange range( -1, 1 );
    CHECK( range.Min() == -1 );
    CHECK( range.Max() == 1 );
}