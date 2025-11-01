#pragma once

namespace overdrive::math
{
    template<int N>
    struct vector<bool, N, isa::sse>
    {
        vector() noexcept = default;
        vector(__m128 xmm) noexcept;
        bool any() const noexcept;
        bool all() const noexcept;

        __m128 xmm;
    };
} // overdrive::math

#include "bvector.inl"
