#pragma once

#include <gm/gm.h>

#include <stdarg.h>

/// \file tool/assert.h
///
/// Assertion tool for printing out failure location when an expression wrapped with GM_ASSERT( ... ) fails to
/// evaluate.
///
/// In Debug builds, GM_ASSERT macro will print the stacktrace when the input expression evaluates to false.
/// In Release builds, the GM_ASSERT macro will be pre-processed away in Release builds.

#ifdef GM_DEBUG
#define GM_ASSERT( expr )                                                                                              \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        gm::Assert( #expr );                                                                                           \
    }
#define GM_ASSERT_MSG( expr, format, ... )                                                                             \
    if ( !( expr ) )                                                                                                   \
    {                                                                                                                  \
        gm::Assert( #expr, format, ##__VA_ARGS__ );                                                                    \
    }
#else
#define GM_ASSERT( expr, ... ) void()
#define GM_ASSERT_MSG( expr, format, ... ) void()
#endif

GM_NS_BEGIN

void Assert( const char* i_expression )
{
    fprintf( stderr, "Assert failed for expression: %s\n", i_expression );
}

void Assert( const char* i_expression, const char* i_format, ... )
{
    char    buffer[ 256 ];
    va_list args;
    va_start( args, i_format );
    vsprintf( buffer, i_format, args );
    va_end( args );
    fprintf( stderr, "Assert failed for expression: %s, %s\n", i_expression, buffer );
}

GM_NS_END
