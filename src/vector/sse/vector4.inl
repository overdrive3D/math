namespace overdrive::math
{
inline vector<float, 4, isa::sse>::vector(__m128 xmm) noexcept:
    xmm(xmm)
{}

inline vector<float, 4, isa::sse>::vector(float s) noexcept:
    xmm(_mm_set_ps1(s))
{}

inline vector<float, 4, isa::sse>::vector(float x, float y, float z, float w /* 1.f */) noexcept:
    xmm(_mm_set_ps(w, z, y, x))
{}

inline vector<float, 4, isa::sse>::vector(const float v[]) noexcept:
    xmm(_mm_loadu_ps(v))
{}

inline vector<float, 4, isa::sse>::vector(const vector<float, 4, isa::fpu>& v) noexcept:
    xmm(_mm_loadu_ps(v.v))
{}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::dot(const vector& v) const noexcept
{
#ifdef OVERDRIVE_SSE4
    return _mm_dp_ps(xmm, v.xmm, 0xFF);
#elif defined(OVERDRIVE_SSE3)
    __m128 d = _mm_mul_ps(xmm, v.xmm);
    d = _mm_hadd_ps(d, d);
    return _mm_hadd_ps(d, d);
#else
    __m128 d = _mm_mul_ps(xmm, v.xmm);
    __m128 t = _mm_shuffle_ps(v.xmm, d, _MM_SHUFFLE(1, 0, 0, 0));
    t = _mm_add_ps(t, d); // z = x + z; w = y + w
    d = _mm_shuffle_ps(d, t, _MM_SHUFFLE(0, 3, 0, 0));
    d = _mm_add_ps(d, t); // z + w
    return _mm_shuffle_ps(d, d, _MM_SHUFFLE(2, 2, 2, 2));
#endif // !OVERDRIVE_SSE3
}

template<int i>
inline float vector<float, 4, isa::sse>::extract() const noexcept
{
    static_assert((i >= 0) && (i <= 3), "component index out of range");
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

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator-() const noexcept
{
    return _mm_sub_ps(_mm_setzero_ps(), xmm);
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator+(float s) const noexcept
{
    return _mm_add_ps(xmm, _mm_set_ps1(s));
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator+(const vector& v) const noexcept
{
    return _mm_add_ps(xmm, v.xmm);
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator-(float s) const noexcept
{
    return _mm_sub_ps(xmm, _mm_set_ps1(s));
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator-(const vector& v) const noexcept
{
    return _mm_sub_ps(xmm, v.xmm);
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator*(float s) const noexcept
{
    return _mm_mul_ps(xmm, _mm_set_ps1(s));
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator*(const vector& v) const noexcept
{
    return _mm_mul_ps(xmm, v.xmm);
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator/(float s) const noexcept
{
    assert(s != 0.f);
    return _mm_div_ps(xmm, _mm_set_ps1(s));
}

inline vector<float, 4, isa::sse> vector<float, 4, isa::sse>::operator/(const vector& v) const noexcept
{
    return _mm_div_ps(xmm, v.xmm);
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator+=(float s) noexcept
{
    xmm = _mm_add_ps(xmm, _mm_set_ps1(s));
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator+=(const vector& v) noexcept
{
    xmm = _mm_add_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator-=(float s) noexcept
{
    xmm = _mm_sub_ps(xmm, _mm_set_ps1(s));
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator-=(const vector& v) noexcept
{
    xmm = _mm_sub_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator*=(float s) noexcept
{
    xmm = _mm_mul_ps(xmm, _mm_set_ps1(s));
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator*=(const vector& v) noexcept
{
    xmm = _mm_mul_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator/=(float s) noexcept
{
    assert(s != 0.f);
    xmm = _mm_div_ps(xmm, _mm_set_ps1(s));
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator/=(const vector& v) noexcept
{
    xmm = _mm_div_ps(xmm, v.xmm);
    return *this;
}

inline vector<float, 4, isa::sse>& vector<float, 4, isa::sse>::operator=(const vector& v) noexcept
{
    xmm = v.xmm;
    return *this;
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator==(const vector& v) const noexcept
{
    return _mm_cmpeq_ps(xmm, v.xmm);
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator!=(const vector& v) const noexcept
{
    return _mm_cmpneq_ps(xmm, v.xmm);
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator>(const vector& v) const noexcept
{
    return _mm_cmpgt_ps(xmm, v.xmm);
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator>=(const vector& v) const noexcept
{
    return _mm_cmpge_ps(xmm, v.xmm);
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator<(const vector& v) const noexcept
{
    return _mm_cmplt_ps(xmm, v.xmm);
}

inline vector<bool, 4, isa::sse> vector<float, 4, isa::sse>::operator<=(const vector& v) const noexcept
{
    return _mm_cmple_ps(xmm, v.xmm);
}

inline vector<float, 4, isa::sse>::operator float() const noexcept
{
    return _mm_cvtss_f32(xmm);
}
} // overdrive::math
