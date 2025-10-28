#pragma once

namespace overdrive::math
{
    template<class T, int N, int x, int y, int z, int w>
    struct swizzle<T, N, isa::fpu, x, y, z, w>
    {
        vector<T, N, isa::fpu>& shuffle() noexcept;
        vector<T, N, isa::fpu> shuffled() const noexcept;

        operator vector<T, N, isa::fpu>() const noexcept;
        vector<T, N, isa::fpu>& operator=(const vector<T, N, isa::fpu>& u) noexcept;
        vector<T, N, isa::fpu>& operator+() const noexcept;
        vector<T, N, isa::fpu> operator-() const noexcept;
        vector<T, N, isa::fpu> operator+(T s) const noexcept;
        vector<T, N, isa::fpu> operator+(const vector<T, N, isa::fpu>& v) const noexcept;
        vector<T, N, isa::fpu> operator-(T s) const noexcept;
        vector<T, N, isa::fpu> operator-(const vector<T, N, isa::fpu>& v) const noexcept;
        vector<T, N, isa::fpu> operator*(T s) const noexcept;
        vector<T, N, isa::fpu> operator*(const vector<T, N, isa::fpu>& v) const noexcept;
        vector<T, N, isa::fpu> operator/(T s) const noexcept;
        vector<T, N, isa::fpu> operator/(const vector<T, N, isa::fpu>& v) const noexcept;
        vector<T, N, isa::fpu>& operator+=(T s) noexcept;
        vector<T, N, isa::fpu>& operator+=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<T, N, isa::fpu>& operator-=(T s) noexcept;
        vector<T, N, isa::fpu>& operator-=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<T, N, isa::fpu>& operator*=(T s) noexcept;
        vector<T, N, isa::fpu>& operator*=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<T, N, isa::fpu>& operator/=(T s) noexcept;
        vector<T, N, isa::fpu>& operator/=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator==(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator!=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator>(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator>=(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator<(const vector<T, N, isa::fpu>& v) noexcept;
        vector<bool, N, isa::fpu> operator<=(const vector<T, N, isa::fpu>& v) noexcept;

        T v[1];
    };
} // overdrive::math

#include "swizzle.inl"
