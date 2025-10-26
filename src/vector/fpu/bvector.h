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

        uint8_t mask;
    };
} // overdrive::math

#include "bvector.inl"
