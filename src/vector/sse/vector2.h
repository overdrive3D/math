#pragma once

namespace overdrive::math
{
    template<>
    struct alignas(16) vector<float, 2, isa::sse>
    {
        vector() noexcept = default;
        vector(__m128 xmm) noexcept;
        vector(float s) noexcept;
        vector(float x, float y) noexcept;
        vector(const float v[]) noexcept;
        vector(const vector<float, 2, isa::fpu>& v) noexcept;

        vector& operator+() noexcept { return *this; }
        const vector& operator+() const noexcept { return *this; }
        vector operator-() const noexcept;
        vector operator+(float s) const noexcept;
        vector operator+(const vector& v) const noexcept;
        vector operator-(float s) const noexcept;
        vector operator-(const vector& v) const noexcept;
        vector operator*(float s) const noexcept;
        vector operator*(const vector& v) const noexcept;
        vector operator/(float s) const noexcept;
        vector operator/(const vector& v) const noexcept;
        vector& operator+=(float s) noexcept;
        vector& operator+=(const vector& v) noexcept;
        vector& operator-=(float s) noexcept;
        vector& operator-=(const vector& v) noexcept;
        vector& operator*=(float s) noexcept;
        vector& operator*=(const vector& v) noexcept;
        vector& operator/=(float s) noexcept;
        vector& operator/=(const vector& v) noexcept;
        operator __m128() const noexcept { return xmm; }

        union
        {
            __m128 xmm;
            struct { const float x, y; };
            const float v[2];
        };
    };
} // overdrive::math

#include "vector2.inl"
