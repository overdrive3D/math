#pragma once

namespace overdrive::math
{
    template<int N, int x, int y, int z, int w>
    struct swizzle<float, N, isa::sse, x, y, z, w>
    {
        vector<float, N, isa::sse>& shuffle() noexcept;
        vector<float, N, isa::sse> shuffled() const noexcept;

        operator vector<float, N, isa::sse>() const noexcept;
        vector<float, N, isa::sse>& operator=(const vector<float, N, isa::sse>& u) noexcept;
        vector<float, N, isa::sse>& operator+() const noexcept;
        vector<float, N, isa::sse> operator-() const noexcept;
        vector<float, N, isa::sse> operator+(float s) const noexcept;
        vector<float, N, isa::sse> operator+(const vector<float, N, isa::sse>& v) const noexcept;
        vector<float, N, isa::sse> operator-(float s) const noexcept;
        vector<float, N, isa::sse> operator-(const vector<float, N, isa::sse>& v) const noexcept;
        vector<float, N, isa::sse> operator*(float s) const noexcept;
        vector<float, N, isa::sse> operator*(const vector<float, N, isa::sse>& v) const noexcept;
        vector<float, N, isa::sse> operator/(float s) const noexcept;
        vector<float, N, isa::sse> operator/(const vector<float, N, isa::sse>& v) const noexcept;
        vector<float, N, isa::sse>& operator+=(float s) noexcept;
        vector<float, N, isa::sse>& operator+=(const vector<float, N, isa::sse>& v) noexcept;
        vector<float, N, isa::sse>& operator-=(float s) noexcept;
        vector<float, N, isa::sse>& operator-=(const vector<float, N, isa::sse>& v) noexcept;
        vector<float, N, isa::sse>& operator*=(float s) noexcept;
        vector<float, N, isa::sse>& operator*=(const vector<float, N, isa::sse>& v) noexcept;
        vector<float, N, isa::sse>& operator/=(float s) noexcept;
        vector<float, N, isa::sse>& operator/=(const vector<float, N, isa::sse>& v) noexcept;

        __m128 xmm;
    };
} // overdrive::math

#include "swizzle.inl"
