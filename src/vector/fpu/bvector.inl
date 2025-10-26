namespace overdrive::math
{
template<int N>
constexpr bvector<N, isa::fpu>::bvector(bool x, bool y,
    bool z /* false */, bool w /* false */) noexcept:
    mask(uint8_t(x) | (uint8_t(y) << 1))
{
    if constexpr (N >= 3) mask |= uint8_t(z) << 2;
    if constexpr (N >= 4) mask |= uint8_t(w) << 3;
}

template<int N>
constexpr bool bvector<N, isa::fpu>::any() const noexcept
{
    return (mask != 0);
}

template<int N>
constexpr bool bvector<N, isa::fpu>::all() const noexcept
{
    return mask == ((1 << N) - 1);
}
} // overdrive::math
