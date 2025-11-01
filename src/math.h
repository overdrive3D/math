#pragma once
#include <algorithm>
#include <cstdint>
#include <limits>
#include <type_traits>

#ifdef OVERDRIVE_SSE
    #include <xmmintrin.h>
    #include <emmintrin.h>
#endif
#ifdef OVERDRIVE_SSE3
    #include <pmmintrin.h>
#endif
#ifdef OVERDRIVE_SSE4
    #include <smmintrin.h>
#endif
#ifdef OVERDRIVE_AVX
    #include <immintrin.h>
#endif

#include "common.h"
#include "sqrt/sqrt.h"
#include "sqrt/fpu/sqrt.h"
#include "vector/vector.h"
#include "vector/swizzle.h"
#include "vector/fpu/swizzle.h"
#include "vector/fpu/bvector.h"
#include "vector/fpu/vector2.h"
#include "vector/fpu/vector3.h"
#include "vector/fpu/vector4.h"
#ifdef OVERDRIVE_SSE
    #include "vector/sse/vector2.h"
    #include "vector/sse/vector3.h"
    #include "vector/sse/vector4.h"
#endif
