#pragma once

namespace overdrive::math
{
    template<>
    struct alignas(16) vector<float, 2, isa::sse>
    {
        using boolvector = vector<bool, 2, isa::sse>;
        template<int x, int y>
        using swizzle = swizzle<float, 2, isa::sse, x, y>;

        vector() noexcept = default;
        vector(__m128 xmm) noexcept;
        vector(float s) noexcept;
        vector(float x, float y) noexcept;
        vector(const float v[]) noexcept;
        vector(const vector<float, 2, isa::fpu>& v) noexcept;
        vector dot(const vector& v) const noexcept;
        vector skew(const vector& v) const noexcept;
        template<int i> float extract() const noexcept;

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
        boolvector operator==(const vector& v) const noexcept;
        boolvector operator!=(const vector& v) const noexcept;
        boolvector operator>(const vector& v) const noexcept;
        boolvector operator>=(const vector& v) const noexcept;
        boolvector operator<(const vector& v) const noexcept;
        boolvector operator<=(const vector& v) const noexcept;
        float operator[](int i) const noexcept { return v[i]; }
        operator __m128() const noexcept { return xmm; }
        operator float() const noexcept;

        union
        {
            __m128 xmm;
            struct { const float x, y; };
            const float v[2];

            swizzle<0, 0> xx;
            swizzle<0, 1> xy;
            swizzle<1, 0> yx;
            swizzle<1, 1> yy;
            swizzle<0, 0> rr;
            swizzle<0, 1> rg;
            swizzle<1, 0> gr;
            swizzle<1, 1> gg;
            swizzle<0, 0> ss;
            swizzle<0, 1> st;
            swizzle<1, 0> ts;
            swizzle<1, 1> tt;
        };
    };
} // overdrive::math

#include "vector2.inl"
