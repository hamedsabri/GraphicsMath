#pragma once

/// \file export.h
///
/// Cross-platform export directives.

#include <gm/platform/os.h>

#if defined( GM_WINDOWS )
/// Windows platform requires explicit directive for external linkage.
#    define GM_EXPORT __declspec( dllexport )
#else
#    define GM_EXPORT
#endif
