namespace overdrive::math
{
template<class T>
constexpr vector<T, 3, isa::fpu>::vector(T s) noexcept:
    x(s), y(s), z(s)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(T x, T y, T z /* 0 */) noexcept:
    x(x), y(y), z(z)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1]), z(v[2])
{}
} // overdrive::math
