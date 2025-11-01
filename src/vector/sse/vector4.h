#pragma once

namespace overdrive::math
{
    template<>
    struct alignas(16) vector<float, 4, isa::sse>
    {
        vector() noexcept = default;
        vector(__m128 xmm) noexcept;
        vector(float s) noexcept;
        vector(float x, float y, float z, float w = 1.f) noexcept;
        vector(const float v[]) noexcept;
        vector(const vector<float, 4, isa::fpu>& v) noexcept;

        operator __m128() const noexcept { return xmm; }

        union
        {
            __m128 xmm;
            struct { float x, y, z, w; };
            float v[4];
        };
    };
} // overdrive::math
