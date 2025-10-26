namespace overdrive::math
{
template<class T>
constexpr T abs(T x) noexcept
{
    return x < T(0) ? -x : x;
}

template<class T>
constexpr T ceil(T x) noexcept
{
    long long i = (long long)x;
    T y = T(i);
    return x < T(0) ? y : (x == y ? x : y + T(1));
}

template<class T>
constexpr T clamp(T x, T lo, T hi) noexcept
{
    return x < lo ? lo : (x > hi ? hi : x);
}

template<class T>
constexpr T floor(T x) noexcept
{
    long long i = (long long)x;
    T y = T(i);
    return x >= T(0) ? y : (x == y ? x : y - T(1));
}

template<class T>
constexpr T isinf(T x) noexcept
{
    return (std::numeric_limits<T>::infinity() == x) ||
        (-std::numeric_limits<T>::infinity() == x);
}

template<class T>
constexpr T isnan(T x) noexcept
{
    return x != x;
}

template<class T>
constexpr T max(T x, T y) noexcept
{
    return x > y ? x : y;
}

template<class T>
constexpr T min(T x, T y) noexcept
{
    return x < y ? x : y;
}

template<class T>
constexpr T pow(T x, int e) noexcept
{
    return (0 == e) ? T(1) : (e > 0)
        ? x * pow(x, e - 1)
        : T(1) / pow(x, -e);
}

template<class T>
constexpr T round(T x) noexcept
{
    return x > T(0) ? floor(x + T(0.5)) : ceil(x - T(0.5));
}

template<class T>
constexpr T sign(T x) noexcept
{
    return x > T(0) ? T(1) : (x < T(0) ? T(-1) : T(0));
}

template<class T>
constexpr T safediv(T x, T y) noexcept
{
    assert(y != T(0));
    return abs(y) > (T)1e-9 ? (x / y) : T(0);
}
} // overdrive::math