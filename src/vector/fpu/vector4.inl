namespace overdrive::math
{
template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T s) noexcept:
    x(s), y(s), z(s), w(s)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T x, T y, T z /* 0 */, T w /* 1 */) noexcept:
    x(x), y(y), z(z), w(w)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1]), z(v[2]), w(v[3])
{}
} // overdrive::math
