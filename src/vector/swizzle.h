#pragma once

namespace overdrive::math
{
    template<class T, int N, isa, int x, int y, int z = 0, int w = 0>
    struct swizzle
    {
        static_assert(N > 1, "swizzling requires at least two dimensions");
        static_assert(x >= 0 && x <= 3, "swizzle x out of range");
        static_assert(y >= 0 && y <= 3, "swizzle y out of range");
        static_assert(z >= 0 && z <= 3, "swizzle z out of range");
        static_assert(w >= 0 && w <= 3, "swizzle w out of range");
        static_assert(sizeof(T) == 0, "swizzle template has not been specialized");
    };

    template<int x, int y, int z = 0, int w = 0>
    struct mask
    {
        constexpr static bool swizzled = true;
    };

    template<> struct mask<0, 1> { constexpr static bool swizzled = false; };
    template<> struct mask<0, 1, 2> { constexpr static bool swizzled = false; };
    template<> struct mask<0, 1, 2, 3> { constexpr static bool swizzled = false; };

    template<int N>
    struct bitmask
    {
        constexpr static int value = 0;
    };

    template<> struct bitmask<1>{ constexpr static int value = 0b1; };
    template<> struct bitmask<2>{ constexpr static int value = 0b11; };
    template<> struct bitmask<3>{ constexpr static int value = 0b111; };
    template<> struct bitmask<4>{ constexpr static int value = 0b1111; };
} // overdrive::math
