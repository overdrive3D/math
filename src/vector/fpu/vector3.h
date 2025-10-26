#pragma once

namespace overdrive::math
{
    template<class T>
    struct vector<T, 3, isa::fpu>
    {
        static_assert(std::is_floating_point<T>::value,
            "vector requires floating-point type");

        constexpr vector() noexcept = default;
        constexpr vector(T s) noexcept;
        constexpr vector(T x, T y, T z = T(0)) noexcept;
        constexpr vector(const T v[]) noexcept;

        union
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };
            T v[3];
        };
    };
} // overdrive::math

#include "vector3.inl"
