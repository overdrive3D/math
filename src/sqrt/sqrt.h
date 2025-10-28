#pragma once

namespace overdrive::math
{
    template<class T, isa> inline T sqrt(T s) noexcept
    {
        static_assert(sizeof(T) == 0, "template of sqrt() has not been specialized");
    }

    template<class T, isa> constexpr T sqrtEst(T s) noexcept
    {
        static_assert(sizeof(T) == 0, "template of sqrtEst() has not been specialized");
    }

    template<class T, isa> inline T rsqrtEst(T s) noexcept
    {
        static_assert(sizeof(T) == 0, "template of rsqrtEst() has not been specialized");
    }
} // overdrive::math
