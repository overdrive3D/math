#pragma once

namespace overdrive::math
{
    template<>
    struct vector<float, 3, isa::sse>
    {
        vector() noexcept = default;
        vector(__m128 xmm) noexcept;
        vector(float s) noexcept;
        vector(float x, float y, float z) noexcept;
        vector(const float v[]) noexcept;
        vector(const vector<float, 3, isa::fpu>& v) noexcept;

        operator __m128() const noexcept { return xmm; }

        union
        {
            __m128 xmm;
            struct { float x, y, z; };
            float v[3];
        };
    };
} // overdrive::math
