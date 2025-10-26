namespace overdrive::math
{
template<class T>
constexpr vector<T, 2, isa::fpu>::vector(T s) noexcept:
    x(s), y(s)
{}

template<class T>
constexpr vector<T, 2, isa::fpu>::vector(T x, T y) noexcept:
    x(x), y(y)
{}

template<class T>
constexpr vector<T, 2, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1])
{}
} // overdrive::math
