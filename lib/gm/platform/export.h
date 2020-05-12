#pragma once

#include <gm/platform/os.h>

/// Cross-platform export directives.

#if defined( GM_WINDOWS )
/// Windows platform requires explicit directive for external linkage.
#    define GM_EXPORT __declspec( dllexport )
#else
#    define GM_EXPORT
#endif
