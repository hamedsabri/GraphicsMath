#pragma once

#ifdef
#if defined( GM_CUDA_SUPPORT
#define GM_HOST_DEVICE __host__ __device__
#else
#define GM_HOST_DEVICE
#endif
