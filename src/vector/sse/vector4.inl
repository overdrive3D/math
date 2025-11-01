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
} // overdrive::math
