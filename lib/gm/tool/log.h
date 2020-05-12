#pragma once

#include <stdio.h>

/// \briief Logging utilities

#define GM_LOG_INFO( format, ... ) printf( format, ##__VA_ARGS__ );
#define GM_LOG_WARN( format, ... ) printf( format, ##__VA_ARGS__ );
#define GM_LOG_ERROR( format, ... ) printf( format, ##__VA_ARGS__ );
