#pragma once

namespace overdrive::math
{
    template<class T>
    struct vector<T, 3, isa::fpu>
    {
        static_assert(std::is_floating_point<T>::value,
            "vector requires floating-point type");
        using boolvector = vector<bool, 3, isa::fpu>;
        template<int M, int x, int y, int z = 0>
        using swizzle = swizzle<T, M, isa::fpu, x, y, z>;

        constexpr vector() noexcept = default;
        constexpr vector(T s) noexcept;
        constexpr vector(T x, T y, T z = T(0)) noexcept;
        constexpr vector(T x, const vector<T, 2, isa::fpu>& v) noexcept;
        constexpr vector(const vector<T, 2, isa::fpu>& v, T z = T(0)) noexcept;
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
        constexpr T dot(const vector& v) const noexcept;
        constexpr vector cross(const vector& v) const noexcept;
        constexpr T squareLength() const noexcept;
        T length() const noexcept;
        constexpr T lengthEst() const noexcept;
        void normalize() noexcept;
        void normalizeEst() noexcept;
        vector normalized() const noexcept;
        vector normalizedEst() const noexcept;
        constexpr void select(const vector& v, const boolvector& c) noexcept;
        constexpr void shuffle(int a, int b, int c, int) noexcept;
        constexpr void store(T *p) const noexcept;

        constexpr vector& operator+() const noexcept { return *this; }
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
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };
            T v[3];

            swizzle<2, 0, 0> xx;
            swizzle<2, 0, 1> xy;
            swizzle<2, 0, 2> xz;
            swizzle<2, 1, 0> yx;
            swizzle<2, 1, 1> yy;
            swizzle<2, 1, 2> yz;
            swizzle<2, 2, 0> zx;
            swizzle<2, 2, 1> zy;
            swizzle<2, 2, 2> zz;
            swizzle<2, 0, 0> rr;
            swizzle<2, 0, 1> rg;
            swizzle<2, 0, 2> rb;
            swizzle<2, 1, 0> gr;
            swizzle<2, 1, 1> gg;
            swizzle<2, 1, 2> gb;
            swizzle<2, 2, 0> br;
            swizzle<2, 2, 1> bg;
            swizzle<2, 2, 2> bb;
            swizzle<2, 0, 0> ss;
            swizzle<2, 0, 1> st;
            swizzle<2, 0, 2> sp;
            swizzle<2, 1, 0> ts;
            swizzle<2, 1, 1> tt;
            swizzle<2, 1, 2> tp;
            swizzle<2, 2, 0> ps;
            swizzle<2, 2, 1> pt;
            swizzle<2, 2, 2> pp;

            swizzle<3, 0, 0, 0> xxx;
            swizzle<3, 0, 0, 1> xxy;
            swizzle<3, 0, 0, 2> xxz;
            swizzle<3, 0, 1, 0> xyx;
            swizzle<3, 0, 1, 1> xyy;
            swizzle<3, 0, 1, 2> xyz;
            swizzle<3, 0, 2, 0> xzx;
            swizzle<3, 0, 2, 1> xzy;
            swizzle<3, 0, 2, 2> xzz;
            swizzle<3, 1, 0, 0> yxx;
            swizzle<3, 1, 0, 1> yxy;
            swizzle<3, 1, 0, 2> yxz;
            swizzle<3, 1, 1, 0> yyx;
            swizzle<3, 1, 1, 1> yyy;
            swizzle<3, 1, 1, 2> yyz;
            swizzle<3, 1, 2, 0> yzx;
            swizzle<3, 1, 2, 1> yzy;
            swizzle<3, 1, 2, 2> yzz;
            swizzle<3, 2, 0, 0> zxx;
            swizzle<3, 2, 0, 1> zxy;
            swizzle<3, 2, 0, 2> zxz;
            swizzle<3, 2, 1, 0> zyx;
            swizzle<3, 2, 1, 1> zyy;
            swizzle<3, 2, 1, 2> zyz;
            swizzle<3, 2, 2, 0> zzx;
            swizzle<3, 2, 2, 1> zzy;
            swizzle<3, 2, 2, 2> zzz;
            swizzle<3, 0, 0, 0> rrr;
            swizzle<3, 0, 0, 1> rrg;
            swizzle<3, 0, 0, 2> rrb;
            swizzle<3, 0, 1, 0> rgr;
            swizzle<3, 0, 1, 1> rgg;
            swizzle<3, 0, 1, 2> rgb;
            swizzle<3, 0, 2, 0> rbr;
            swizzle<3, 0, 2, 1> rbg;
            swizzle<3, 0, 2, 2> rbb;
            swizzle<3, 1, 0, 0> grr;
            swizzle<3, 1, 0, 1> grg;
            swizzle<3, 1, 0, 2> grb;
            swizzle<3, 1, 1, 0> ggr;
            swizzle<3, 1, 1, 1> ggg;
            swizzle<3, 1, 1, 2> ggb;
            swizzle<3, 1, 2, 0> gbr;
            swizzle<3, 1, 2, 1> gbg;
            swizzle<3, 1, 2, 2> gbb;
            swizzle<3, 2, 0, 0> brr;
            swizzle<3, 2, 0, 1> brg;
            swizzle<3, 2, 0, 2> brb;
            swizzle<3, 2, 1, 0> bgr;
            swizzle<3, 2, 1, 1> bgg;
            swizzle<3, 2, 1, 2> bgb;
            swizzle<3, 2, 2, 0> bbr;
            swizzle<3, 2, 2, 1> bbg;
            swizzle<3, 2, 2, 2> bbb;
            swizzle<3, 0, 0, 0> sss;
            swizzle<3, 0, 0, 1> sst;
            swizzle<3, 0, 0, 2> ssp;
            swizzle<3, 0, 1, 0> sts;
            swizzle<3, 0, 1, 1> stt;
            swizzle<3, 0, 1, 2> stp;
            swizzle<3, 0, 2, 0> sps;
            swizzle<3, 0, 2, 1> spt;
            swizzle<3, 0, 2, 2> spp;
            swizzle<3, 1, 0, 0> tss;
            swizzle<3, 1, 0, 1> tst;
            swizzle<3, 1, 0, 2> tsp;
            swizzle<3, 1, 1, 0> tts;
            swizzle<3, 1, 1, 1> ttt;
            swizzle<3, 1, 1, 2> ttp;
            swizzle<3, 1, 2, 0> tps;
            swizzle<3, 1, 2, 1> tpt;
            swizzle<3, 1, 2, 2> tpp;
            swizzle<3, 2, 0, 0> pss;
            swizzle<3, 2, 0, 1> pst;
            swizzle<3, 2, 0, 2> psp;
            swizzle<3, 2, 1, 0> pts;
            swizzle<3, 2, 1, 1> ptt;
            swizzle<3, 2, 1, 2> ptp;
            swizzle<3, 2, 2, 0> pps;
            swizzle<3, 2, 2, 1> ppt;
            swizzle<3, 2, 2, 2> ppp;
        };
    };

    template<class T> constexpr vector<T, 3, isa::fpu> select(
        const vector<T, 3, isa::fpu>& v1, const vector<T, 3, isa::fpu>& v2,
        const vector<bool, 3, isa::fpu>& c) noexcept;
} // overdrive::math

#include "vector3.inl"
