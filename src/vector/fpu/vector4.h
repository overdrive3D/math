#pragma once

namespace overdrive::math
{
    template<class T>
    struct vector<T, 4, isa::fpu>
    {
        static_assert(std::is_floating_point<T>::value,
            "vector requires floating-point type");

        constexpr vector() noexcept = default;
        constexpr vector(T s) noexcept;
        constexpr vector(T x, T y, T z = T(0), T w = T(1)) noexcept;
        constexpr vector(const T v[]) noexcept;

        union
        {
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T s, t, p, q; };
            T v[4];
        };
    };
} // overdrive::math

#include "vector4.inl"
