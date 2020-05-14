#pragma once

/// \file hostdevice.h
///
/// Definitions to support functions to be callable from CUDA device code.

#if defined( GM_CUDA_SUPPORT )
#define GM_HOST_DEVICE __host__ __device__
#else
#define GM_HOST_DEVICE
#endif
