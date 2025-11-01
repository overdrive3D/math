namespace overdrive::math
{
template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::shuffle() noexcept
{
    if constexpr (mask<x, y, z, w>::swizzled)
        xmm = _mm_shuffle_ps(xmm, xmm, _MM_SHUFFLE(w, z, y, x));
    return *reinterpret_cast<vector<float, N, isa::sse>*>(this);
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::shuffled() const noexcept
{
    __m128 v = xmm;
    if constexpr (mask<x, y, z, w>::swizzled)
        v = _mm_shuffle_ps(v, v, _MM_SHUFFLE(w, z, y, x));
    return vector<float, N, isa::sse>(v);
}

template<int N, int x, int y, int z, int w>
inline swizzle<float, N, isa::sse, x, y, z, w>::operator vector<float, N, isa::sse>() const noexcept
{
    return shuffled();
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator=(const vector<float, N, isa::sse>& v) noexcept
{
    xmm = _mm_shuffle_ps(v.xmm, v.xmm, _MM_SHUFFLE(w, z, y, x));
    return *reinterpret_cast<vector<float, N, isa::sse>*>(this);
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator+() const noexcept
{
    return shuffle().operator+();
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator-() const noexcept
{
    return shuffled().operator-();
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator+(float s) const noexcept
{
    return shuffled() + s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator+(const vector<float, N, isa::sse>& v) const noexcept
{
    return shuffled() + v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator-(float s) const noexcept
{
    return shuffled() - s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator-(const vector<float, N, isa::sse>& v) const noexcept
{
    return shuffled() - v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator*(float s) const noexcept
{
    return shuffled() * s;
}
template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator*(const vector<float, N, isa::sse>& v) const noexcept
{
    return shuffled() * v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator/(float s) const noexcept
{
    return shuffled() / s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator/(const vector<float, N, isa::sse>& v) const noexcept
{
    return shuffled() / v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator+=(float s) noexcept
{
    return shuffle() += s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator+=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffle() += v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator-=(float s) noexcept
{
    return shuffle() -= s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator-=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffle() -= v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator*=(float s) noexcept
{
    return shuffle() *= s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator*=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffle() *= v;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator/=(float s) noexcept
{
    return shuffle() /= s;
}

template<int N, int x, int y, int z, int w>
inline vector<float, N, isa::sse>& swizzle<float, N, isa::sse, x, y, z, w>::operator/=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffle() /= v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator==(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() == v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator!=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() != v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator>(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() > v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator>=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() >= v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator<(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() < v;
}

template<int N, int x, int y, int z, int w>
inline vector<bool, N, isa::sse> swizzle<float, N, isa::sse, x, y, z, w>::operator<=(const vector<float, N, isa::sse>& v) noexcept
{
    return shuffled() <= v;
}
} // overdrive::math
