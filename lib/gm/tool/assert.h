#pragma once

#include <gm/api.h>

/// \brief Assertion tool for printing the call stack when an expression wrapped with GM_ASSERT( ... ) fails to
/// evaluate.
///
/// In Debug builds, GM_ASSERT macro will print the stacktrace when the input expression evaluates to false.
/// In Release builds, the GM_ASSERT macro will be pre-processed away in Release builds.

#ifdef GM_DEBUG
#define GM_ASSERT( expr )                                                                                              \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        GM_NS::Assert( #expr );                                                                                 \
    }
#define GM_ASSERT_MSG( expr, format, ... )                                                                             \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        GM_NS::Assert( #expr, format, ##__VA_ARGS__ );                                                          \
    }
#else
#define GM_ASSERT( expr, ... ) void()
#define GM_ASSERT_MSG( expr, format, ... ) void()
#endif
