namespace overdrive::math
{
template<int N>
inline vector<bool, N, isa::sse>::vector(__m128 xmm) noexcept:
    xmm(xmm)
{}

template<int N>
inline bool vector<bool, N, isa::sse>::any() const noexcept
{
    return (_mm_movemask_ps(xmm) & bitmask<N>::value) != 0;
}

template<int N>
inline bool vector<bool, N, isa::sse>::all() const noexcept
{
    return (_mm_movemask_ps(xmm) & bitmask<N>::value) == bitmask<N>::value;
}
} // overdrive::math
