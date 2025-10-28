#pragma once

namespace overdrive::math
{
    template<class T, int N, isa>
    struct vector
    {
        static_assert(N > 1, "vector requires at least two dimensions");
        static_assert(sizeof(T) == 0, "vector template has not been specialized");
    };
} // overdrive::math
