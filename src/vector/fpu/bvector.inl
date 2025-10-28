namespace overdrive::math
{
constexpr vector<bool, 2, isa::fpu>::vector(bool x, bool y) noexcept:
    x(x), y(y)
{}

constexpr bool vector<bool, 2, isa::fpu>::any() const noexcept
{
    return (mask & 0b11) != 0;
}

constexpr bool vector<bool, 2, isa::fpu>::all() const noexcept
{
    return (mask & 0b11) == 0b11;
}

constexpr vector<bool, 3, isa::fpu>::vector(bool x, bool y, bool z) noexcept:
    x(x), y(y), z(z)
{}

constexpr bool vector<bool, 3, isa::fpu>::any() const noexcept
{
    return (mask & 0b111) != 0;
}

constexpr bool vector<bool, 3, isa::fpu>::all() const noexcept
{
    return (mask & 0b111) == 0b111;
}

constexpr vector<bool, 4, isa::fpu>::vector(bool x, bool y, bool z, bool w) noexcept:
    x(x), y(y), z(z), w(w)
{}

constexpr bool vector<bool, 4, isa::fpu>::any() const noexcept
{
    return (mask & 0b1111) != 0;
}

constexpr bool vector<bool, 4, isa::fpu>::all() const noexcept
{
    return (mask & 0b1111) == 0b1111;
}
} // overdrive::math
