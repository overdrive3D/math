namespace overdrive::math
{
inline vector<float, 3, isa::sse>::vector(__m128 xmm) noexcept:
    xmm(xmm)
{}

inline vector<float, 3, isa::sse>::vector(float s) noexcept:
    xmm(_mm_set_ps1(s))
{}

inline vector<float, 3, isa::sse>::vector(float x, float y, float z /* 0 */) noexcept:
    xmm(_mm_set_ps(0.f, z, y, x))
{}

inline vector<float, 3, isa::sse>::vector(const float v[]) noexcept:
    xmm(_mm_set_ps(0.f, 0.f, v[1], v[0]))
{}

inline vector<float, 3, isa::sse>::vector(const vector<float, 3, isa::fpu>& v) noexcept:
    xmm(_mm_set_ps(0.f, v.z, v.y, v.x))
{}

template<int i>
inline float vector<float, 3, isa::sse>::extract() const noexcept
{
    static_assert((i >= 0) && (i <= 2), "component index out of range");
#ifdef OVERDRIVE_SSE4
    int c = _mm_extract_ps(xmm, i);
    return *reinterpret_cast<float *>(&c);
#else
    if constexpr (i == 0)
        return _mm_cvtss_f32(xmm);
    else
    {
        __m128 v = _mm_shuffle_ps(xmm, xmm, _MM_SHUFFLE(i, i, i, i));
        return _mm_cvtss_f32(v);
    }
#endif // !OVERDRIVE_SSE4
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator-() const noexcept
{
    return _mm_sub_ps(_mm_setzero_ps(), xmm);
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator+(float s) const noexcept
{
    return _mm_add_ps(xmm, _mm_set_ps(0.f, s, s, s));
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator+(const vector& v) const noexcept
{
    return _mm_add_ps(xmm, v.xmm);
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator-(float s) const noexcept
{
    return _mm_sub_ps(xmm, _mm_set_ps(0.f, s, s, s));
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator-(const vector& v) const noexcept
{
    return _mm_sub_ps(xmm, v.xmm);
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator*(float s) const noexcept
{
    return _mm_mul_ps(xmm, _mm_set_ps(0.f, s, s, s));
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator*(const vector& v) const noexcept
{
    return _mm_mul_ps(xmm, v.xmm);
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator/(float s) const noexcept
{
    assert(s != 0.f);
    return _mm_div_ps(xmm, _mm_set_ps(0.f, s, s, s));
}

inline vector<float, 3, isa::sse> vector<float, 3, isa::sse>::operator/(const vector& v) const noexcept
{
    return _mm_div_ps(xmm, v.xmm);
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator+=(float s) noexcept
{
    xmm = _mm_add_ps(xmm, _mm_set_ps(0.f, s, s, s));
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator+=(const vector& v) noexcept
{
    xmm = _mm_add_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator-=(float s) noexcept
{
    xmm = _mm_sub_ps(xmm, _mm_set_ps(0.f, s, s, s));
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator-=(const vector& v) noexcept
{
    xmm = _mm_sub_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator*=(float s) noexcept
{
    xmm = _mm_mul_ps(xmm, _mm_set_ps(0.f, s, s, s));
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator*=(const vector& v) noexcept
{
    xmm = _mm_mul_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator/=(float s) noexcept
{
    assert(s != 0.f);
    xmm = _mm_div_ps(xmm, _mm_set_ps(0.f, s, s, s));
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator/=(const vector& v) noexcept
{
    xmm = _mm_div_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 3, isa::sse>& vector<float, 3, isa::sse>::operator=(const vector& v) noexcept
{
    xmm = v.xmm;
    return *this;
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator==(const vector& v) const noexcept
{
    return _mm_cmpeq_ps(xmm, v.xmm);
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator!=(const vector& v) const noexcept
{
    return _mm_cmpneq_ps(xmm, v.xmm);
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator>(const vector& v) const noexcept
{
    return _mm_cmpgt_ps(xmm, v.xmm);
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator>=(const vector& v) const noexcept
{
    return _mm_cmpge_ps(xmm, v.xmm);
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator<(const vector& v) const noexcept
{
    return _mm_cmplt_ps(xmm, v.xmm);
}

inline vector<bool, 3, isa::sse> vector<float, 3, isa::sse>::operator<=(const vector& v) const noexcept
{
    return _mm_cmple_ps(xmm, v.xmm);
}

inline vector<float, 3, isa::sse>::operator float() const noexcept
{
    return _mm_cvtss_f32(xmm);
}
} // overdrive::math
