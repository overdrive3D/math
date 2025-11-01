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
        float extractx() const noexcept;
        float extracty() const noexcept;
        float extractz() const noexcept;
        float extractw() const noexcept;

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
        vector& operator=(const vector& v) noexcept;
        float operator[](int i) const noexcept { return v[i]; }
        operator __m128() const noexcept { return xmm; }

        union
        {
            __m128 xmm;
            struct { const float x, y, z, w; };
            const float v[4];
        };
    };
} // overdrive::math

#include "vector4.inl"
