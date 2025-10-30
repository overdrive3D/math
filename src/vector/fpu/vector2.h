#pragma once

namespace overdrive::math
{
    template<class T>
    struct vector<T, 2, isa::fpu>
    {
        static_assert(std::is_floating_point<T>::value,
            "vector requires floating-point type");
        using boolvector = vector<bool, 2, isa::fpu>;
        template<int x, int y>
        using swizzle = swizzle<T, 2, isa::fpu, x, y>;

        constexpr vector() noexcept = default;
        constexpr vector(T s) noexcept;
        constexpr vector(T x, T y) noexcept;
        constexpr vector(const T v[]) noexcept;
        constexpr void zero() noexcept;
        constexpr bool isZero() const noexcept;
        constexpr bool isNan() const noexcept;
        constexpr bool isEqual(const vector& v, T eps = T(1e-6)) const noexcept;
        constexpr bool isUnit(T eps = T(1e-6)) const noexcept;
        constexpr void abs() noexcept;
        constexpr void round() noexcept;
        constexpr void clamp(T lo, T hi) noexcept;
        constexpr void saturate() noexcept;
        constexpr T sum() const noexcept;
        constexpr T sumAbs() const noexcept;
        constexpr T dot(const vector& v) const noexcept;
        constexpr T skew(const vector& v) const noexcept;
        constexpr T squareLength() const noexcept;
        T length() const noexcept;
        constexpr T lengthEst() const noexcept;
        void normalize() noexcept;
        void normalizeEst() noexcept;
        vector normalized() const noexcept;
        vector normalizedEst() const noexcept;
        constexpr void select(const vector& v, const boolvector& c) noexcept;
        constexpr void shuffle(int a, int b, int, int) noexcept;
        constexpr void store(T *p) const noexcept;

        constexpr vector& operator+() noexcept { return *this; }
        constexpr const vector& operator+() const noexcept { return *this; }
        constexpr vector operator-() const noexcept;
        constexpr vector operator+(T s) const noexcept;
        constexpr vector operator+(const vector& v) const noexcept;
        constexpr vector operator-(T s) const noexcept;
        constexpr vector operator-(const vector& v) const noexcept;
        constexpr vector operator*(T s) const noexcept;
        constexpr vector operator*(const vector& v) const noexcept;
        constexpr vector operator/(T s) const noexcept;
        constexpr vector operator/(const vector& v) const noexcept;
        constexpr vector& operator+=(T s) noexcept;
        constexpr vector& operator+=(const vector& v) noexcept;
        constexpr vector& operator-=(T s) noexcept;
        constexpr vector& operator-=(const vector& v) noexcept;
        constexpr vector& operator*=(T s) noexcept;
        constexpr vector& operator*=(const vector& v) noexcept;
        constexpr vector& operator/=(T s) noexcept;
        constexpr vector& operator/=(const vector& v) noexcept;
        constexpr boolvector operator==(const vector& v) const noexcept;
        constexpr boolvector operator!=(const vector& v) const noexcept;
        constexpr boolvector operator>(const vector& v) const noexcept;
        constexpr boolvector operator>=(const vector& v) const noexcept;
        constexpr boolvector operator<(const vector& v) const noexcept;
        constexpr boolvector operator<=(const vector& v) const noexcept;
        constexpr T& operator[](int i) noexcept { return v[i]; }
        constexpr T operator[](int i) const noexcept { return v[i]; }

        union
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
            T v[2];

            swizzle<0, 0> xx;
            swizzle<0, 1> xy;
            swizzle<1, 0> yx;
            swizzle<1, 1> yy;
            swizzle<0, 0> rr;
            swizzle<0, 1> rg;
            swizzle<1, 0> gr;
            swizzle<1, 1> gg;
            swizzle<0, 0> ss;
            swizzle<0, 1> st;
            swizzle<1, 0> ts;
            swizzle<1, 1> tt;
        };
    };

    template<class T> constexpr vector<T, 2, isa::fpu> select(
        const vector<T, 2, isa::fpu>& v1, const vector<T, 2, isa::fpu>& v2,
        const vector<bool, 2, isa::fpu>& c) noexcept;
} // overdrive::math

#include "vector2.inl"
