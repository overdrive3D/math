#pragma once

namespace overdrive::math
{
    template<int N>
    struct bvector<N, isa::fpu>
    {
        constexpr bvector() noexcept = default;
        constexpr bvector(bool x, bool y, bool z = false, bool w = false) noexcept;
        constexpr bool any() const noexcept;
        constexpr bool all() const noexcept;

        union
        {
            uint8_t mask;
            struct { uint8_t x: 1, y: 1, z: 1, w: 1; };
        };
    };
} // overdrive::math

#include "bvector.inl"
