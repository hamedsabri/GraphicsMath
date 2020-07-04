//
// This file is auto-generated, please do not modify directly!
//

#include <catch2/catch.hpp>

#include <gm/types/intArray.h>
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

TEST_CASE( "IntRange_MinAccessor" )
{
    gm::IntRange range;
    range.Min() = -1;
    CHECK( range.Min() == -1 );
}

TEST_CASE( "IntRange_MaxAccessor" )
{
    gm::IntRange range;
    range.Max() = 1;
    CHECK( range.Max() == 1 );
}

TEST_CASE( "IntRange_RangeIteration" )
{
    gm::IntRange range( -3, 3 );
    gm::IntArray array;
    for ( const int& value : range )
    {
        array.push_back( value );
    }

    gm::IntArray expectedArray = {-3, -2, -1, 0, 1, 2};
    CHECK( array == expectedArray );
}
