#pragma once

namespace overdrive::math
{
    template<>
    struct vector<bool, 2, isa::fpu>
    {
        constexpr vector() noexcept = default;
        constexpr vector(bool x, bool y) noexcept;
        constexpr bool any() const noexcept;
        constexpr bool all() const noexcept;

        union
        {
            struct { uint8_t x: 1, y: 1; };
            uint8_t mask;
        };
    };

    template<>
    struct vector<bool, 3, isa::fpu>
    {
        constexpr vector() noexcept = default;
        constexpr vector(bool x, bool y, bool z) noexcept;
        constexpr bool any() const noexcept;
        constexpr bool all() const noexcept;

        union
        {
            struct { uint8_t x: 1, y: 1, z: 1; };
            uint8_t mask;
        };
    };

    template<>
    struct vector<bool, 4, isa::fpu>
    {
        constexpr vector() noexcept = default;
        constexpr vector(bool x, bool y, bool z, bool w) noexcept;
        constexpr bool any() const noexcept;
        constexpr bool all() const noexcept;

        union
        {
            struct { uint8_t x: 1, y: 1, z: 1, w: 1; };
            uint8_t mask;
        };
    };
} // overdrive::math

#include "bvector.inl"
