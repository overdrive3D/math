namespace overdrive::math
{
template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::shuffle() noexcept
{
    auto& v = *reinterpret_cast<vector<T, N, isa::fpu>*>(this);
    if constexpr (mask<x, y, z, w>::swizzled)
        v.shuffle(x, y, z, w);
    return v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::shuffled() const noexcept
{
    auto v = *reinterpret_cast<const vector<T, N, isa::fpu>*>(this);
    if constexpr (mask<x, y, z, w>::swizzled)
        v.shuffle(x, y, z, w);
    return v;
}

template<class T, int N, int x, int y, int z, int w>
inline swizzle<T, N, isa::fpu, x, y, z, w>::operator vector<T, N, isa::fpu>() const noexcept
{
    return shuffled();
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator=(const vector<T, N, isa::fpu>& u) noexcept
{
    v[x] = u.x;
    v[y] = u.y;
    if constexpr (N > 2)
        v[z] = u.z;
    if constexpr (N > 3)
        v[w] = u.w;
    return *reinterpret_cast<vector<T, N, isa::fpu>*>(this);
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator+() const noexcept
{
    return shuffle().operator+();
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator-() const noexcept
{
    return shuffled().operator-();
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator+(T s) const noexcept
{
    return shuffled() + s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator+(const vector<T, N, isa::fpu>& v) const noexcept
{
    return shuffled() + v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator-(T s) const noexcept
{
    return shuffled() - s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator-(const vector<T, N, isa::fpu>& v) const noexcept
{
    return shuffled() - v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator*(T s) const noexcept
{
    return shuffled() * s;
}
template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator*(const vector<T, N, isa::fpu>& v) const noexcept
{
    return shuffled() * v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator/(T s) const noexcept
{
    return shuffled() / s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu> swizzle<T, N, isa::fpu, x, y, z, w>::operator/(const vector<T, N, isa::fpu>& v) const noexcept
{
    return shuffled() / v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator+=(T s) noexcept
{
    return shuffle() += s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator+=(const vector<T, N, isa::fpu>& v) noexcept
{
    return shuffle() += v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator-=(T s) noexcept
{
    return shuffle() -= s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator-=(const vector<T, N, isa::fpu>& v) noexcept
{
    return shuffle() -= v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator*=(T s) noexcept
{
    return shuffle() *= s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator*=(const vector<T, N, isa::fpu>& v) noexcept
{
    return shuffle() *= v;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator/=(T s) noexcept
{
    return shuffle() /= s;
}

template<class T, int N, int x, int y, int z, int w>
inline vector<T, N, isa::fpu>& swizzle<T, N, isa::fpu, x, y, z, w>::operator/=(const vector<T, N, isa::fpu>& v) noexcept
{
    return shuffle() /= v;
}
} // overdrive::math
