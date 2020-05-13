#pragma once

#include <gm/gm.h>

GM_NS_BEGIN

/// Function for comparing if the difference between two values is within a small threshold.
template < typename ValueT >
bool AlmostEqual( const ValueT& i_valueA, const ValueT& i_valueB, const ValueT& i_threshold = 0.0001 )
{
    return std::abs( i_valueA - i_valueB ) < i_threshold;
}

GM_NS_END
