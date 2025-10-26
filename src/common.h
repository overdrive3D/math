#pragma once

namespace overdrive::math
{
    enum class isa
    {
        fpu, sse, avx, neon
    };

    template<class T> constexpr T abs(T x) noexcept;
    template<class T> constexpr T ceil(T x) noexcept;
    template<class T> constexpr T clamp(T x, T lo, T hi) noexcept;
    template<class T> constexpr T floor(T x) noexcept;
    template<class T> constexpr T isinf(T x) noexcept;
    template<class T> constexpr T isnan(T x) noexcept;
    template<class T> constexpr T max(T x, T y) noexcept;
    template<class T> constexpr T min(T x, T y) noexcept;
    template<class T> constexpr T pow(T x, int e) noexcept;
    template<class T> constexpr T round(T x) noexcept;
    template<class T> constexpr T sign(T x) noexcept;
    template<class T> constexpr T safediv(T x, T y) noexcept;
} // overdrive::math

#include "common.inl"
