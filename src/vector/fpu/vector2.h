#pragma once

namespace overdrive::math
{
    template<class T>
    struct vector<T, 2, isa::fpu>
    {
        static_assert(std::is_floating_point<T>::value,
            "vector requires floating-point type");

        constexpr vector() noexcept = default;
        constexpr vector(T s) noexcept;
        constexpr vector(T x, T y) noexcept;
        constexpr vector(const T v[]) noexcept;

        union
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
            T v[2];
        };
    };
} // overdrive::math

#include "vector2.inl"
