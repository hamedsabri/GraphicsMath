#pragma once

#include <pbr/api.h>

GM_NAMESPACE_BEGIN

/// Function for comparing if the difference between two values is within a small threshold.
GM_API
template < typename ValueT >
bool AlmostEqual( const ValueT& i_valueA, const ValueT& i_valueB, const ValueT& i_threshold = 0.0001 )
{
    return std::abs( i_valueA - i_valueB ) < i_threshold;
}

GM_NAMESPACE_END
