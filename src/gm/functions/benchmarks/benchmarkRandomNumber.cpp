//
// This file is auto-generated, please do not modify directly!
//

#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>

#include <gm/functions/randomNumber.h>

TEST_CASE( "RandomNumber_FloatRange" )
{
    gm::FloatRange range;
    BENCHMARK( "RandomNumber" )
    {
        return gm::RandomNumber( range );
    };
}

TEST_CASE( "RandomNumber_IntRange" )
{
    gm::IntRange range;
    BENCHMARK( "RandomNumber" )
    {
        return gm::RandomNumber( range );
    };
}
